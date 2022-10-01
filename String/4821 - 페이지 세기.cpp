#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

bool isPrinted[1001];
int totalPage;
string input;

int solution() {
	int startNum;
	int endNum;

	stringstream sstream(input);
	string curRange;

	while (getline(sstream, curRange, ',')) {
		int pos = curRange.find('-');
		if (pos != string::npos) {
			startNum = stoi(curRange.substr(0, pos));
			endNum = stoi(curRange.substr(pos + 1));
			for (int i = startNum; i <= endNum; i++)
				isPrinted[i] = true;
		}
		else {
			isPrinted[stoi(curRange)] = true;
		}
	}

	int answer = 0;
	for (int i = 1; i <= totalPage; i++)
		if(isPrinted[i])
			answer++;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> totalPage;
		if (totalPage == 0) break;

		cin >> input;
		cout << solution() << '\n';
		memset(isPrinted, false, sizeof(isPrinted));
	}
	
}