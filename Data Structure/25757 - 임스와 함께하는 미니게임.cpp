#include<iostream>
#include<unordered_set>
#include<map>
using namespace std;

map<char, int> numOfPlayer = {
	{'Y', 1},
	{'F', 2},
	{'O', 3},
};
int N;
char gameName;

int solution() {
	unordered_set<string> names;

	for (int i = 0; i < N; i++) {
		string curName;
		cin >> curName;
		names.insert(curName);
	}

	return names.size() / numOfPlayer[gameName];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> gameName;

	cout << solution();
}