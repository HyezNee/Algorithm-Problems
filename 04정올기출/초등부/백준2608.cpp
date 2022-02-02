#include <iostream>
#include <string>
#include <map>
using namespace std;

int ro2ar(string roNum) {
	map<char, int> prenum;
	prenum['I'] = 1;
	prenum['V'] = 5;
	prenum['X'] = 10;
	prenum['L'] = 50;
	prenum['C'] = 100;
	prenum['D'] = 500;
	prenum['M'] = 1000;

	int postnum = 0;
	for (int i = 0; i < roNum.length(); i++) {
		int temp;
		if (i == roNum.length() - 1) {
			temp = prenum[roNum[i]];
		}
		else if (prenum[roNum[i]] < prenum[roNum[i + 1]]) {	// 3¹ø ±ÔÄ¢
			temp = prenum[roNum[i + 1]] - prenum[roNum[i]];
			i++;
		}
		else {
			temp = prenum[roNum[i]];
		}
		postnum += temp;
	}

	return postnum;
}

string ar2ro(int arNum) {
	map<int, string> num2ro;
	num2ro[0] = "M";
	num2ro[1] = "CM";
	num2ro[2] = "D";
	num2ro[3] = "CD";
	num2ro[4] = "C";
	num2ro[5] = "XC";
	num2ro[6] = "L";
	num2ro[7] = "XL";
	num2ro[8] = "X";
	num2ro[9] = "IX";
	num2ro[10] = "V";
	num2ro[11] = "IV";
	num2ro[12] = "I";

	int prenum[13];
	prenum[0] = arNum / 1000;	// M
	arNum %= 1000;
	prenum[1] = arNum / 900;	// CM
	/* if (CMnum > 1) */
	arNum %= 900;
	prenum[2] = arNum / 500;	// D
	/* if (Dnum > 1) */
	arNum %= 500;
	/* int CDnum = 0;
	if (CDnum > 0) */
	prenum[3] = arNum / 400;	// CD
	arNum %= 400;
	prenum[4] = arNum / 100;	// C
	arNum %= 100;
	prenum[5] = arNum / 90;	// XC
	arNum %= 90;
	prenum[6] = arNum / 50;	// L
	arNum %= 50;
	prenum[7] = arNum / 40;	// XL
	arNum %= 40;
	prenum[8] = arNum / 10;	// X
	arNum %= 10;
	prenum[9] = arNum / 9;	// IX
	arNum %= 9;
	prenum[10] = arNum / 5;	// V
	arNum %= 5;
	prenum[11] = arNum / 4;	// IV
	arNum %= 4;
	prenum[12] = arNum;	// I

	string postnum = "";
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < prenum[i]; j++) {
			postnum += num2ro[i];
		}
	}

	return postnum;
}


int main(void) {
	string roA, roB;
	cin >> roA >> roB;
	int arA = ro2ar(roA);
	int arB = ro2ar(roB);
	int arSum = arA + arB;
	string roSum = ar2ro(arSum);

	cout << arSum << endl << roSum;

	return 0;
}