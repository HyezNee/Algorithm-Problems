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
int visited[101];
int gnum = 0;//그룹 번호

void dfs(int n) {
	visited[n] = 1;
	group[gnum].push_back(n);
	for (int i = 0; i < know[n].size(); ++i) {
		int nxt = know[n][i];
		if (visited[nxt] == 1)continue;
		dfs(nxt);
	}
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
	//dfs로 위원회 수 세고 그룹 만들기
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == 1)continue;
		gnum++;//1번 그룹~
		dfs(i);
	}

	cout << gnum << endl;

	//각 그룹 별로 BFS로 최저 값 확인하기
	for (int i = 1; i <= gnum; ++i) {
		vector<int> v = group[i];
		int len = v.size();
		int small = 87654321;
		int snum;

		for (int j = 0; j < len; ++j) {
			int start = v[j];
			int dis[101];
			memset(dis, -1, sizeof(dis));
			dis[start] = 0;
			queue<int> q;
			q.push(start);
			int tot = 0;//총 거리
			while (!q.empty()) {
				int here = q.front(); q.pop();
				for (int k = 0; k < know[here].size(); ++k) {
					int there = know[here][k];
					if (dis[there] == -1) {
						dis[there] = dis[here] + 1;
						q.push(there);
						if (dis[there] > tot)
							tot = dis[there];
					}
				}
			}
			if (tot < small) {
				small = tot;
				snum = start;
			}
		}
		pres.push_back(snum);
	}

	sort(pres.begin(), pres.end());
	for (int i = 0; i < pres.size(); ++i)cout << pres[i] << endl;

	return 0;
}