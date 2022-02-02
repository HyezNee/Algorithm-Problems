#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> inputArr;
	int input;
	for (int i = 0; i < 9; i++) {	// 입력값 배열에 집어넣기
		cin >> input;
		inputArr.push_back(input);
	}
	sort(inputArr.begin(), inputArr.end());	// 배열을 오름차순으로 정렬

	int sum = 0;
	vector<int>::iterator it;
	for (it = inputArr.begin(); it != inputArr.end(); it++) {	// 9명의 키를 더함
		sum += *it;
	}
	
	sum -= 100;	// 9명의 난쟁이의 키의 합 - 7명의 난쟁이의 키의 합 (100)
	
	vector<int>::iterator itBack;	// 배열의 끝에서부터 차례대로 탐색하는 이더레이터
	for (it = inputArr.begin(); it != inputArr.end(); it++) {
		for (itBack = inputArr.end() - 1; itBack != inputArr.begin() + 1; itBack--) {
			if (sum - (*it) == *itBack)
				break;
		}
		if (sum - (*it) == *itBack)
			break;
	}

	vector<int>::iterator finalIt;	// 최종 값 출력하기 위해 사용
	for (finalIt = inputArr.begin(); finalIt != inputArr.end(); finalIt++) {
		if (finalIt != it && finalIt != itBack)
			cout << (*finalIt) << endl;
	}
	
	return 0;
}