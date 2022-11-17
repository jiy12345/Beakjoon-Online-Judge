#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int points[5][200000];

void solution() {
	vector<int> answer;

	for (int j = 1; j < 5; j++) {
		int maxNum = 0;
		int maxIndex = 200000;
		for (int i = 0; i < N; i++) {
			if(find(answer.begin(), answer.end(), points[0][i]) != answer.end()) 
				continue;
			if (maxNum < points[j][i]) {
				maxNum = points[j][i];
				maxIndex = points[0][i];
			}
			else if (maxNum == points[j][i] && maxIndex > points[0][i]) {
				maxNum = points[j][i];
				maxIndex = points[0][i];
			}
		}
		answer.push_back(maxIndex);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			cin >> points[j][i];

	solution();
}