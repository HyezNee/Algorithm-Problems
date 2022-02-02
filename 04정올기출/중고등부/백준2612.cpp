#include <iostream>
#include <string>
using namespace std;

int Max(const int& a, const int& b, const int& c, const int& plus) {
	int max = a + plus;
	if (max < b - 2) {
		max = b - 2;
	}
	if (max < c - 2) {
		max = c - 2;
	}

	if (max <= plus) {	// 시작 지점 새로 정해짐
		return plus;
	}
	return max;
}

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	string A, B;
	int a, b;
	cin >> a >> A >> b >> B;

	int** table = new int* [a + 1];
	for (int i = 0; i < a + 1; i++)
		table[i] = new int[b + 1];

	// 0행, 0열 모두 0으로 채우기
	for (int i = 0; i <= a; i++)
		table[i][0] = 0;
	for (int i = 0; i <= b; i++)
		table[0][i] = 0;

	int maxSim = 0;
	int maxrow, maxcol;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (A[i - 1] == B[j - 1]) {
				table[i][j] = Max(table[i - 1][j - 1], table[i - 1][j], table[i][j - 1], 3);
			}
			else {
				table[i][j] = Max(table[i - 1][j - 1], table[i - 1][j], table[i][j - 1], -2);
			}
			//cout << table[i][j] << " ";
			if (maxSim < table[i][j]) {
				maxSim = table[i][j];
				maxrow = i, maxcol = j;
			}
		}
		//cout << endl;
	}

	// 경로 추적
	int i = maxrow, j = maxcol;
	int startrow = maxrow, startcol = maxcol;
	while (1) {
		if (table[i][j] == 3)	break;
		int plus;
		if (A[i - 1] == B[j - 1])	plus = 3;
		else plus = -2;
		int max = table[i - 1][j - 1] + plus;
		startrow = i - 1, startcol = j - 1;
		if (max < table[i - 1][j] - 2) {
			max = table[i - 1][j];
			startcol = j;
		}
		if (max < table[i][j - 1] - 2) {
			// max = table[i][j - 1];
			startrow = i, startcol = j - 1;
		}
		if (startrow == 0 || startcol == 0) {
			startrow = i, startcol = j;
			break;
		}
		i = startrow, j = startcol;
	}

	cout << maxSim << endl;
	for (int i = startrow; i <= maxrow; i++)
		cout << A[i - 1];
	cout << endl;
	for (int i = startcol; i <= maxcol; i++)
		cout << B[i - 1];

}