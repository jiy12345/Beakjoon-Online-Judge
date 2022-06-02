#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

bool solution() {
	while (1) {
		if (S.size() == T.size()) {
			if (S == T)
				return true;
			break;
		}

		if (T[T.size() - 1] == 'A')
			T.pop_back();
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> S;
	cin >> T;

	cout << solution();
}