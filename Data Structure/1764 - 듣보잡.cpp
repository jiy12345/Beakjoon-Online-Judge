#include<iostream>
#include<set>
using namespace std;

int N, M;
set<string> un_heard;
set<string> un_seen;

void solution() {
	set<string> un_heard_seen;
	for (string person_name : un_seen) {
		if (un_heard.find(person_name) != un_heard.end()) {
			un_heard_seen.insert(person_name);
		}
	}

	cout << un_heard_seen.size() << '\n';
	for (string person_name : un_heard_seen) {
		cout << person_name << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	string person;
	for (int i = 0; i < N; i++) {
		cin >> person;
		un_heard.insert(person);
	}

	for (int j = 0; j < M; j++) {
		cin >> person;
		un_seen.insert(person);
	}

	solution();
}