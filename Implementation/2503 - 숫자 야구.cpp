#include<iostream>
#include<vector>
using namespace std;

struct NumberInfo {
	string number;
	int strike = 0;
	int ball = 0;
};

int N;
vector<NumberInfo> number_info;

int solution() {
	int cnt = 0;
	for (int i = 1;i <= 9;i++) {
		string cur_num = "";
		cur_num += i + '0';
		for (int j = 1;j <= 9;j++) {
			if (cur_num.find(j + '0') != string::npos) {
				continue;
			}
			cur_num += j + '0';
			for (int k = 1;k <= 9;k++) {
				if (cur_num.find(k + '0') != string::npos) {
					continue;
				}
				cur_num += k + '0';

				int cur_index;
				for (cur_index = 0;cur_index < N;cur_index++) {
					NumberInfo cur_number_info = number_info[cur_index];
					int cur_num_strike = 0;
					int cur_num_ball = 0;
					for (int cur_digit = 0;cur_digit < 3;cur_digit++) {
						if (cur_num[cur_digit] == cur_number_info.number[cur_digit]) {
							cur_num_strike++;
						}
						else if (cur_num.find(cur_number_info.number[cur_digit]) != string::npos) {
							cur_num_ball++;
						}
					} 
					if (cur_num_strike != number_info[cur_index].strike ||
						cur_num_ball != number_info[cur_index].ball
						) {
						break;
					}
				}

				if (cur_index == N) {
					cnt++;
				}

				cur_num = cur_num.substr(0, cur_num.size() - 1);
			}
			cur_num = cur_num.substr(0, cur_num.size() - 1);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		NumberInfo cur_number_info;
		cin >> cur_number_info.number >> cur_number_info.strike >> cur_number_info.ball;
		number_info.push_back(cur_number_info);
	}

	cout << solution();
}