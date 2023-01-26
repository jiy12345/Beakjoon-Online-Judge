#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

int n, k;
int cards[10];
bool is_used[10];
unordered_set<string> num_made;


void PickNumber(vector<int> cur_picked_num) {
	if (cur_picked_num.size() == k) {
		string cur_num = "";
		for (int i = 0;i < k;i++) {
			cur_num += to_string(cur_picked_num[i]);
		}

		num_made.insert(cur_num);

		return;
	}

	for (int i = 0;i < n;i++) {
		if (is_used[i] == true) continue;
		cur_picked_num.push_back(cards[i]);
		is_used[i] = true;
		PickNumber(cur_picked_num);
		cur_picked_num.pop_back();
		is_used[i] = false;
	}
}

int solution() {
	PickNumber(vector<int>());

	return num_made.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;

	for (int i = 0;i < n;i++) {
		cin >> cards[i];
	}

	cout << solution();
}