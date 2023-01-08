#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

string x, y;

bool isFriend() {
	bool num_of_digit_x[10], num_of_digit_y[10];
	memset(num_of_digit_x, false, sizeof(num_of_digit_x));
	memset(num_of_digit_y, false, sizeof(num_of_digit_y));

	for (const auto& i : x)
		num_of_digit_x[i - '0'] = true;
	for (const auto& i : y)
		num_of_digit_y[i - '0'] = true;

	for (int i = 0; i < 10; i++)
		if (num_of_digit_x[i] != num_of_digit_y[i])
			return false;

	return true;
}

string solution() {
	if (isFriend()) {
		return "friends";
	}

	for (int i = 0; i < x.length() - 1; i++) {
		x[i]--;
		x[i + 1]++;
		if (x[0] != '0' && isdigit(x[i]) && isdigit(x[i + 1])) {
			if (isFriend()) {
				return "almost friends";
			}
		}
		x[i]++;
		x[i + 1]--;

		x[i]++;
		x[i + 1]--;
		if (isdigit(x[i])&& isdigit(x[i + 1])) {
			if (isFriend()) {
				return "almost friends";
			}
		}
		x[i]--;
		x[i + 1]++;
	}

	for (int i = 0; i < y.length() - 1; i++) {
		y[i]--;
		y[i + 1]++;
		if (y[0] != '0' && isdigit(y[i]) && isdigit(y[i + 1])) {
			if (isFriend()) {
				return "almost friends";
			}
		}
		y[i]++;
		y[i + 1]--;

		y[i]++;
		y[i + 1]--;
		if(isdigit(y[i]) && isdigit(y[i + 1])) {
			if (isFriend()) {
				return "almost friends";
			}
		}
		y[i]--;
		y[i + 1]++;
	}

	return "nothing";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		cout << solution() << '\n';
	}
}
