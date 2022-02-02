#include <stdio.h>

int bfs(const int& startnode, const int& n,  int* nodeCheck, bool** edge, int* queue) {
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
				// distance += nodeCheck[i];	// 전달시간 합 구하는줄 알았네;;; 아 내 시간..
				if (distance < nodeCheck[i]) {
					distance = nodeCheck[i];
				}
			}
		}
		k++;
	}
	return distance;
}

int bfs(const int& startnode, const int& n, bool** edge) {
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
				// distance += nodeCheck[i];
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

	bool** edge = new bool*[n];
	for (int i = 0; i < n; i++)
		edge[i] = new bool[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			edge[i][j] = 0;
		}
	int a, b;
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		edge[a - 1][b - 1] = 1;
		edge[b - 1][a - 1] = 1;
	}

	int* nodeCheck = new int[n];
	int* minNum = new int[n];
	for (int i = 0; i < n; i++) {
		nodeCheck[i] = -1;
		minNum[i] = -1;
	}
	
	int idx = -1;
	int nodecount = 0;
	int startnode = -1;
	while (1) {
		int k;
		for (k = startnode + 1; k < n; k++) {
			if (nodeCheck[k] == -1) {
				startnode = k;
				nodecount++;
				break;
			}
		}
		if (k == n) {
			break;
		}

		int* queue = new int[n];
		for (int i = 0; i < n; i++)	queue[i] = -1;

		int min = bfs(startnode, n, nodeCheck, edge, queue);
		minNum[++idx] = startnode;
		for (int i = 1; i < n && queue[i] != -1; i++) {
			int distance = bfs(queue[i], n, edge);
			if (min > distance) {
				min = distance;
				minNum[idx] = queue[i];
			}
		}
		delete[] queue;
	}

	printf("%d", nodecount);
	for (int i = 0; i < n && *(minNum + i) != -1; i++) {
		printf("\n%d", *(minNum + i) + 1);
	}

	return 0;
}