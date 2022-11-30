#include<iostream>
using namespace std;

string A, B;

int solution() {
	string longerStr, shorterStr;
	int answer = 50;

	if (A.size() < B.size()) {
		longerStr = B;
		shorterStr = A;
	}
	else {
		longerStr = A;
		shorterStr = B;
	}

	int diff = longerStr.size() - shorterStr.size();

	for (int i = 0; i <= diff; i++)
	{
		int curNum = 0;
		for (int j = 0; j < shorterStr.size(); j++)
			if (shorterStr[j] != longerStr[i + j])
				curNum++;
		answer = min(answer, curNum);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << solution();
}