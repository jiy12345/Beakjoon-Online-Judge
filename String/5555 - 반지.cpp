#include<iostream>
using namespace std;

string String;
int N;

int solution() {
	int answer = 0;

	string curRing;
	for (int i = 0; i < N; i++) {
		cin >> curRing;
		
		for (int j = 0; j < curRing.size(); j++) {
			if (curRing[j] != String[0]) continue;

			int k;
			for (k = 1; k < String.length(); k++) {
				if (curRing[(j + k) % curRing.size()] != String[k]) break;
			}

			if (k == String.length()) {
				answer++;
				break;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> String;
	cin >> N;

	cout << solution();
}