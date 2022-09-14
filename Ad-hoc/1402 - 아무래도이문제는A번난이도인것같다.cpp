#include<iostream>
using namespace std;

int T;
int A, B;

string solution() {
	return "yes";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << solution() << '\n';
	}
}