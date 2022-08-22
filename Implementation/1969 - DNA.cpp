#include<iostream>
#include<map>
using namespace std;

int N, M;
char s[1000][50];

enum DNA { A, C, G, T, NUM_OF_DNA };
map<char, int> charToIntDNA = {
	{'A', A },
	{'C', C },
	{'G', G },
	{'T', T }
};
map<char, int> intToCharDNA = {
	{ A, 'A' },
	{ C, 'C' },
	{ G, 'G' },
	{ T, 'T' }
};

void solution() {
	int sumOfHammingDistance = 0;
	string DNA = "";

	for (int i = 0; i < M; i++) {
		int numOfDNA[NUM_OF_DNA] = { 0, };

		for (int j = 0; j < N; j++) {
			numOfDNA[charToIntDNA[s[j][i]]]++;
		}

		int maxIndex = 0;
		int maxNum = 0;
		for (int j = 0; j < NUM_OF_DNA; j++) {
			if (maxNum < numOfDNA[j]) {
				maxNum = numOfDNA[j];
				maxIndex = j;
			}
		}

		sumOfHammingDistance += (N - maxNum);
		DNA += intToCharDNA[maxIndex];
	}

	cout << DNA << '\n';
	cout << sumOfHammingDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> s[i][j];

	solution();
}
