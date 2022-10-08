#include<iostream>
#include<unordered_map>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

unordered_map<string, int> numOfTEachtask;
vector<string> tasks = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };

void solution() {
	float total = 0;

	string curTask;
	string inputLine;
	while (getline(cin, inputLine)) {
		stringstream ss(inputLine);
		while (ss >> curTask) {
			numOfTEachtask[curTask]++;
			total += 1;
		}
	}

	for (string curTask: tasks) {
		if (numOfTEachtask[curTask] == 0) {
			cout << setprecision(2) << curTask << " " << numOfTEachtask[curTask] << " " << "0.00" << '\n';
			continue;
		}
		cout << fixed << setprecision(2) << curTask << " " << numOfTEachtask[curTask] << " " << numOfTEachtask[curTask] / total << '\n';
	}

	cout << "Total " << (int)total << " 1.00" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

}