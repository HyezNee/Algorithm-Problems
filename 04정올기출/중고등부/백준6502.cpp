#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, w, l;
	int i = 1;
	while (1) {
		cin >> r;
		if (r == 0) {
			break;
		}
		cin >> w >> l;

		int diaSquared = w * w + l * l;
		if (4 * r * r >= diaSquared) {
			cout << "Pizza " << i << " fits on the table." << "\n";
		}
		else {
			cout << "Pizza " << i << " does not fit on the table." << "\n";
		}
		i++;
	}
}