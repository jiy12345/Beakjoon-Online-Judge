#include<iostream>
#include<queue>
using namespace std;

class comp {
public:
	bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {

		if (lhs.second.length() == rhs.second.length()) {
			if (lhs.first == rhs.first) {
				return lhs.second > rhs.second;
			}
			else {
				return lhs.first > rhs.first;
			}
		}
		else {
			return lhs.second.length() > rhs.second.length();
		}
	}
};

int N;
priority_queue<pair<int, string>, vector<pair<int, string>>, comp> priority_queue_serial;

void solution() {
	for (int i = 0;i < N;i++) {
		string cur_serial;
		cin >> cur_serial;

		int cur_sum = 0;
		for (auto cur_char : cur_serial) {
			if (isdigit(cur_char)) {
				cur_sum += (cur_char - '0');
			}
		}

		priority_queue_serial.push({ cur_sum, cur_serial });
	}

	while(!priority_queue_serial.empty()) {
		cout << priority_queue_serial.top().second << '\n';
		priority_queue_serial.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}