#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* student_Queue = new int[n];
	for (int i = 0; i < n; i++)
		student_Queue[i] = 0;	// 0으로 초기화
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if(student_Queue[i - input] == 0)	// 학생이 0을 뽑았을 경우(순서 고정)
			student_Queue[i - input] = i + 1;	// 실제 인덱스는 0부터 시작하므로 1씩 더해준다.
		else {	// 0 외의 숫자를 뽑았을 경우 (순서 변동)
			for (int j = n - 2; j >= i - input ; j--)	// 한 칸씩 밀어내기
				student_Queue[j + 1] = student_Queue[j];
			student_Queue[i - input] = i + 1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << student_Queue[i] << " ";

	delete[] student_Queue;
	return 0;
}