#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> inputArr;
	int input;
	for (int i = 0; i < 9; i++) {	// �Է°� �迭�� ����ֱ�
		cin >> input;
		inputArr.push_back(input);
	}
	sort(inputArr.begin(), inputArr.end());	// �迭�� ������������ ����

	int sum = 0;
	vector<int>::iterator it;
	for (it = inputArr.begin(); it != inputArr.end(); it++) {	// 9���� Ű�� ����
		sum += *it;
	}
	
	sum -= 100;	// 9���� �������� Ű�� �� - 7���� �������� Ű�� �� (100)
	
	vector<int>::iterator itBack;	// �迭�� ���������� ���ʴ�� Ž���ϴ� �̴�������
	for (it = inputArr.begin(); it != inputArr.end(); it++) {
		for (itBack = inputArr.end() - 1; itBack != inputArr.begin() + 1; itBack--) {
			if (sum - (*it) == *itBack)
				break;
		}
		if (sum - (*it) == *itBack)
			break;
	}

	vector<int>::iterator finalIt;	// ���� �� ����ϱ� ���� ���
	for (finalIt = inputArr.begin(); finalIt != inputArr.end(); finalIt++) {
		if (finalIt != it && finalIt != itBack)
			cout << (*finalIt) << endl;
	}
	
	return 0;
}