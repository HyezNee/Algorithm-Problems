#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int n, e;
	vector<int*> edge[1002];	// (끝점, 값)
	queue<int> queue;

	cin >> n >> e;

	int* indegree = new int[n + 2];
	for (int i = 1; i <= n + 1; i++) indegree[i] = 0;

	vector<int> maxPath[1002];
	int maxScore[1001] = { 0, };

	// Grape 정보 저장
	for (int i = 0; i < e; i++) {
		int a, b, p;
		cin >> a >> b >> p;
		if (b == 1)
			b = n + 1;
		int* temp = new int[2];
		temp[0] = b;	temp[1] = p;
		edge[a].push_back(temp);
		indegree[b]++;
	}

	// Topological sort
	maxPath[1].push_back(1);
	queue.push(1);
	while (!queue.empty()) {
		int i = queue.front();
		queue.pop();
		indegree[i] = -1;
		for (int k = 0; k < edge[i].size(); k++) {
			int there = edge[i][k][0];
			int point = edge[i][k][1];
			indegree[there]--;
			if (indegree[there] == 0)	queue.push(there);
			if (maxScore[i] + point > maxScore[there]) {
				maxScore[there] = maxScore[i] + point;
				maxPath[there] = maxPath[i];
				maxPath[there].push_back(there);
			}
		}
	}
	
	cout << maxScore[n + 1] << endl;
	vector<int>::iterator it;
	for (it = maxPath[n + 1].begin(); it < maxPath[n + 1].end() - 1; it++) {
		cout << *it << " ";
	}
	cout << "1";

	return 0;
}