#include<iostream>
#include<unordered_set>
using namespace std;

int num_a, num_b;
unordered_set<int> union_set;

int solution() {
	int total_number = num_a + num_b;
	for (int i = 0; i < total_number; i++) {
		int cur_number;
		cin >> cur_number;
		union_set.insert(cur_number);
	}

	int intersection_number = total_number - union_set.size();

	return (num_a - intersection_number) + (num_b - intersection_number);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> num_a >> num_b;
	cout << solution();
}