#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int T, n;

int solution() {
	unordered_map<string, unordered_set<string>> clothes_list;

	for (int i = 0;i < n;i++) {
		string clothes_name, sort;
		cin >> clothes_name >> sort;
		clothes_list[sort].insert(clothes_name);
	}

	int cases = 1;
	for (auto cur_sort : clothes_list) {
		cases *= (cur_sort.second.size() + 1);
	}

	return cases - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> n;
		cout << solution() << '\n';
	}
}
