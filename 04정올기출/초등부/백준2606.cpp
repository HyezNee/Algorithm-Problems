#include <iostream>
using namespace std;

void dfs(bool** com, bool* isCheck, const int& n, const int& nowNode, int& wormNum) {
	for (int i = 0; i < n; i++) {
		if (com[nowNode][i] == 1 && isCheck[i] == 0) {
			isCheck[i] = 1;
			wormNum++;
			dfs(com, isCheck, n, i, wormNum);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	bool** com = new bool*[n];
	for (int i = 0; i < n; i++) {
		com[i] = new bool[n];
	}
	int m;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			com[i][j] = 0;
		}
	}
	int p, q;
	for (int i = 0; i < m; i++) {
		cin >> p >> q;
		p--;
		q--;
		com[p][q] = 1;
		com[q][p] = 1;
	}
	
	bool* isCheck = new bool[n];
	isCheck[0] = 1;
	for (int i = 1; i < n; i++)
		isCheck[i] = 0;
	int wormNum = 0;

	dfs(com, isCheck, n, 0, wormNum);
	cout << wormNum;
}