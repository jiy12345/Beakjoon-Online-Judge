#include<iostream>
#include<set>

using namespace std;

int n;
set<string> peopleInTheCompany;

void solution() {
	for (int i = 0; i < n; i++) {
		string name, enterOrLeave;
		cin >> name >> enterOrLeave;
		if (enterOrLeave == "enter")
			peopleInTheCompany.insert(name);
		else
			peopleInTheCompany.erase(name);
	}

	for (auto iter = peopleInTheCompany.rbegin(); iter != peopleInTheCompany.rend(); iter++)
		cout << *iter << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	solution();
}