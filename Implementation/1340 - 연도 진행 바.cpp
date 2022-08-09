#include <iostream>
#include <string>
using namespace std;

string curMonth, curTime, curDay;
int curYear;
string eng_mon[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int dateMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int totalMin;

void solution() {
	int count = 0;
	
	if ((curYear % 400 == 0) || (curYear % 4 == 0 && curYear % 100 != 0)) {
		dateMonth[1] = 29;
		totalMin = 366 * 24 * 60;
	}
	else
		totalMin = 365 * 24 * 60;

	int curDate = 0;

	for (int i = 0; i < 12; i++) {
		if (curMonth == eng_mon[i])
			break;
		curDate += dateMonth[i];
	}

	curDate += stoi(curDay.substr(0, 2)) - 1;

	int curMin = curDate * 24 * 60 + stoi(curTime.substr(0, 2)) * 60 + stoi(curTime.substr(3));

	double result = (double)curMin / totalMin * 100;
	cout.precision(10);
	cout << result;
}

int main() {
	cin >> curMonth >> curDay >> curYear >> curTime;

	solution();
}