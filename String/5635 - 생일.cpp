#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<pair<pair<int, int>, pair<int, string>>> BD_info;

void solution() {
	sort(BD_info.begin(), BD_info.end());
	cout << BD_info[n - 1].second.second << '\n'; 
	cout << BD_info[0].second.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	BD_info.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> BD_info[i].second.second >> BD_info[i].second.first >> BD_info[i].first.second >> BD_info[i].first.first;
	}

	solution();
}