#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using  namespace std;

int N;
vector<int> know[101];
vector<int> group[101];
vector<int> pres;
bool visited[101] = { 0, };
int gnum = 0;//그룹 번호

void dfs(const int& startnode) {
	visited[startnode] = 1;
	group[gnum].push_back(startnode);
	for (int i = 0; i < know[startnode].size(); i++) {
		if (!visited[know[startnode][i]]) {
			dfs(know[startnode][i]);
		}
	}
}

int bfs(const int& startnode, const int& n) {
	int queue[101], nodeCheck[101];
	for (int i = 0; i < 101; i++) { queue[i] = -1; nodeCheck[i] = -1; }

	int idx = 0;
	queue[idx] = startnode;
	nodeCheck[startnode] = 0;
	int distance = nodeCheck[startnode];
	int k = 0;
	while (k < n && queue[k] != -1) {
		for (int i = 0; i < know[queue[k]].size(); i++) {
			int there = know[queue[k]][i];
			if (nodeCheck[there] == -1) {
				nodeCheck[there] = nodeCheck[queue[k]] + 1;
				queue[++idx] = there;
				if (distance < nodeCheck[there]) {
					distance = nodeCheck[there];
				}
			}
		}
		k++;
	}
	return distance;
}

int main() {
	cin >> N;//100이하
	int M; cin >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		know[a].push_back(b);
		know[b].push_back(a);
	}

	// Union Find by DFS
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == 1)continue;
		gnum++;//1번 그룹~
		dfs(i);
	}

	cout << gnum << endl;

	// Count min by BFS
	for (int k = 1; k <= gnum; ++k) {
		int min = 100;
		int snum = 101;
		for (int i = 0; i < group[k].size(); i++) {
			int distance = bfs(group[k][i], N);
			if (min > distance) {
				min = distance;
				snum = group[k][i];
			}
		}
		pres.push_back(snum);
	}

	sort(pres.begin(), pres.end());
	for (int i = 0; i < pres.size(); ++i)cout << pres[i] << endl;

	return 0;
}