#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> arr;
	int num, total = 0, tmpmax = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
		total += num;
		if (tmpmax < num)
			tmpmax = num;
	}

	// Parametric Search
	// X = 최댓값, 조건 = M개의 그룹으로 나누어짐
	// X보다 작으면 조건을 충족시키지 못함
	int left = 1, right = total - m + 2, mid;	// [left, right)
	// vector<int> ansGroup;
	int ansMax = 0, ansIdx = 0, totIdx = 0;
	vector<int> group[20];	// 그룹에 속해있는 원소의 개수
	while (1) {
		mid = (left + right) / 2;
		vector<int> sum;	// 그룹안에 속해있는 구슬들의 합
		int idx = 0, max = 0;
		if (tmpmax > mid) {
			left = mid;
			totIdx++;
			if (right - left <= 1) {
				cout << ansMax << "\n";
				for (int i = 0; i < group[ansIdx].size(); i++) {
					cout << group[ansIdx][i] << " ";
				}
				break;
			}
			continue;
		}
		sum.push_back(arr[0]);
		group[totIdx].push_back(1);
		for (int i = 1; i < n && sum.size() <= m; i++) {
			bool flag = false;
			if (group[totIdx][idx] >= (n - i + group[totIdx][idx]) - (m - idx) + 1)
				flag = true;
			if (flag || sum[idx] + arr[i] > mid) {
				sum.push_back(arr[i]);
				group[totIdx].push_back(1);
				idx++;
			}
			else {
				sum[idx] += arr[i];
				group[totIdx][idx] += 1;
			}
		}
		if (sum.size() > m) {
			left = mid;
		}
		else if (sum.size() < m) {
			right = mid;
		}
		else {
			max = 0;
			for (int i = 0; i < m; i++) {
				if (max < sum[i])
					max = sum[i];
			}
			right = max;
			ansMax = max, ansIdx = totIdx;
			/*ansGroup.clear();
			ansGroup.resize(group.size());
			copy(group.begin(), group.end(), ansGroup.begin());*/
		}
		totIdx++;
		if (right - left <= 1) {
			cout << ansMax << "\n";
			for (int i = 0; i < group[ansIdx].size(); i++) {
				cout << group[ansIdx][i] << " ";
			}
			break;
		}
	}

	return 0;
}