#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string* word = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	vector<int> element;
	map<int, char> address;
	for (int i = 0; i < (int)word[0].length(); i++) {
		int j;
		for (j = 0; j < i; j++) {
			if (word[0][i] == word[0][j]) {
				element[j]--;
				break;
			}
		}
		if (j == i) {	// 반복문 끝까지 다 돌았을 때
			element.push_back(-1);
			address[element.size() - 1] = word[0][i];
		}
	}

	int wordCount = 0;
	element.push_back(0);	//extra

	int wordIdx = 1;
	while (wordIdx < n) {

		vector<int> elementCopy;
		elementCopy.resize((int)element.size());
		copy(element.begin(), element.end(), elementCopy.begin());

		for (int j = 0; j < (int)word[wordIdx].length(); j++) {
			int i;
			for (i = 0; i < (int)address.size(); i++) {
				if (word[wordIdx][j] == address[i]) {
					elementCopy[i]++;
					break;
				}
			}
			if (i == address.size())
				elementCopy[element.size() - 1]++;
		}
		
		int k;
		bool flag[2] = { 0, };
		for (k = 0; k < (int)element.size(); k++) {
			if (elementCopy[k] > 1 || elementCopy[k] < -1)
				break;
			else if (elementCopy[k] == 1) {
				if (flag[0])
					break;
				else
					flag[0] = 1;
			}
			else if (elementCopy[k] == -1) {
				if (flag[1])
					break;
				else
					flag[1] = 1;
			}
		}
		if (k != (int)element.size()) {
			wordIdx++;
			continue;
		}

		int sum = 0;
		for (int i = 0; i < (int)element.size(); i++) {
			sum += elementCopy[i];
		}
		if ((sum <= 1) && (sum >= -1))
			wordCount++;

		wordIdx++;
	}

	cout << wordCount;

	return 0;
}