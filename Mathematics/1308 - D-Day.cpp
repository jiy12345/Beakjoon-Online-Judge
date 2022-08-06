#include<iostream>
using namespace std;

int y_1, m_1, d_1;
int y_2, m_2, d_2;

int dateOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year) {
	if (year % 4 == 0)
		if (year % 100 != 0 || year % 400 == 0)
			return true;

	return false;
}

int dayCount(int y, int m, int d) {
	int day = 0;

	for (int i = 0; i < y; ++i) {
		day += 365;
		if (isLeapYear(i))
			day += 1;
	}

	for (int i = 0; i + 1 < m; ++i) {
		if (i == 1)
			day += isLeapYear(y);
		day += dateOfMonth[i];
	}

	day += d;

	return day;
}

void solution() {
	int day1 = dayCount(y_1, m_1, d_1);
	int day2 = dayCount(y_2, m_2, d_2);

	if (y_2 - y_1 > 1000) {
		cout << "gg";
		return;
	}
	else if (y_2 - y_1 == 1000 &&
		dayCount(0, m_1, d_1) <= dayCount(0, m_2, d_2)) {
		cout << "gg";
		return;
	}

	cout << "D-" << day2 - day1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> y_1 >> m_1 >> d_1;
	cin >> y_2 >> m_2 >> d_2;

	solution();

	return 0;
}