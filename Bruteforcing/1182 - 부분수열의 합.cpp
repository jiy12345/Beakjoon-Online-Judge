#include<iostream>
#include<vector>
using namespace std;

int answer = 0;
int N, S;

// num: 전체 수열을 담은 배열
// cur_index: 현재 탐색중인 위치를 나타내는 인덱스
// cur_sum: 현재까지 뽑은 수들을 합한 것
// cur_cnt: 현재까지 뽑은 수의 개수
void solution(vector<int> num, int cur_index, int cur_sum, int cur_cnt) {
	// 끝까지 탐색했을 경우
  if (cur_index == N) {
    // 수를 하나도 뽑지 않은 상황일 경우는 부분수열이 아니므로 제외
    // 뽑은 수들의 합이 S일 경우 answer값 1 증가
		if (cur_sum == S && cur_cnt != 0) {
			answer++;
		}
		return;
	}

	solution(num, cur_index + 1, cur_sum + num[cur_index], cur_cnt + 1); // 이번 원소를 더했을 경우
	solution(num, cur_index + 1, cur_sum, cur_cnt); // 이번 원소를 더하지 않았을 경우
	
}

int main() {

	int temp;
	cin >> N >> S;

	vector<int> num;

	for (int i = 0;i < N;i++) {
		cin >> temp;
		num.push_back(temp);
	}

	solution(num, 0, 0, 0);

	cout << answer << endl;

	return 0;
}
