#include <stdio.h>

int col = 0;

void dfs(const int& startnode, const int& n, bool edge[][101], bool nodeCheck[], int group[][101], const int& row) {
	nodeCheck[startnode] = 1;
	group[row][col++] = startnode;
	for (int i = 0; i < n; i++) {
		if (edge[startnode][i] && !nodeCheck[i]) {
			dfs(i, n, edge, nodeCheck, group, row);
		}
	}
}

int bfs(const int& startnode, const int& n, bool edge[][101]) {
	int queue[101], nodeCheck[101];
	for (int i = 0; i < 101; i++) { queue[i] = -1; nodeCheck[i] = -1; }

	int idx = 0;
	queue[idx] = startnode;
	nodeCheck[startnode] = 0;
	int distance = nodeCheck[startnode];
	int k = 0;
	while (k < n && queue[k] != -1) {
		for (int i = 0; i < n; i++) {
			if (edge[queue[k]][i] == 1 && nodeCheck[i] == -1) {
				nodeCheck[i] = nodeCheck[queue[k]] + 1;
				queue[++idx] = i;
				if (distance < nodeCheck[i]) {
					distance = nodeCheck[i];
				}
			}
		}
		k++;
	}
	return distance;
}

int main(void) {
	int n, e;
	scanf("%d\n%d", &n, &e);

	bool edge[101][101] = { 0, };
	int group[101][101];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			group[i][j] = -1;
		}
	int a, b;
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		edge[a - 1][b - 1] = 1;
		edge[b - 1][a - 1] = 1;
	}

	bool nodeCheck[101] = { 0, };
	int minNum[101];
	for (int i = 0; i < n; i++) minNum[i] = -1;

	// Union Find by DFS
	int groupIdx = 0;
	for (int i = 0; i < n; i++) {
		if (!nodeCheck[i]) {
			col = 0;
			dfs(i, n, edge, nodeCheck, group, groupIdx);
			groupIdx++;
		}
	}

	int idx = -1;
	for(int k = 0; k < groupIdx; k++)  {
		int min = 100;
		minNum[++idx] = 101;
		for (int i = 0; i < n && group[k][i] != -1; i++) {
			int distance = bfs(group[k][i], n, edge);
			if (min > distance) {
				min = distance;
				minNum[idx] = group[k][i];
			}
		}
	}
	printf("%d\n", groupIdx);
	for (int i = 0; i < n && minNum[i] != -1; i++) {
		printf("%d\n", minNum[i] + 1);
	}

	return 0;
}