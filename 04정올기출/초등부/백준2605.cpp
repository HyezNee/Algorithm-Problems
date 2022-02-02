#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* student_Queue = new int[n];
	for (int i = 0; i < n; i++)
		student_Queue[i] = 0;	// 0���� �ʱ�ȭ
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if(student_Queue[i - input] == 0)	// �л��� 0�� �̾��� ���(���� ����)
			student_Queue[i - input] = i + 1;	// ���� �ε����� 0���� �����ϹǷ� 1�� �����ش�.
		else {	// 0 ���� ���ڸ� �̾��� ��� (���� ����)
			for (int j = n - 2; j >= i - input ; j--)	// �� ĭ�� �о��
				student_Queue[j + 1] = student_Queue[j];
			student_Queue[i - input] = i + 1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << student_Queue[i] << " ";

	delete[] student_Queue;
	return 0;
}