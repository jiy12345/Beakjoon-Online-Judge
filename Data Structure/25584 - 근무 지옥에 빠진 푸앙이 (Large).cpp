#include<iostream>
#include<map>
#include<limits.h>
using namespace std;

int N;
map<string, int> workingHours;
map<int, int> hours = {
	{0, 4},
	{1, 6},
	{2, 4},
	{3, 10}
};

void solution() {
	bool answer = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 7; k++) {
				string name;
				cin >> name;
				if (name != "-") {
					workingHours[name] += hours[j];
				}
			}
		}
	}

	int minNum = INT_MAX;
	int maxNum = 0;
	for (auto workingHour : workingHours) {
		minNum = min(minNum, workingHour.second);
		maxNum = max(maxNum, workingHour.second);
	}

	if (workingHours.empty()) minNum = 0;
	cout << ((maxNum - minNum > 12) ? "No" : "Yes");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();
}