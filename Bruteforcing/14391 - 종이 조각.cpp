#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> paper;
bool is_used[4][4] = { false, };
int N, M, answer = 0;

// num: 배열을 한줄로 늘어놨을 때의 위치
// sum: 현재까지의 합
void solution(int num, int sum) {
	int cur_j_index = num % M;
	int cur_i_index = num / M;

	// 기저 사례: 배열의 위치를 벗어났을 경우
	if (num >= N * M) {
		answer = max(answer, sum);
		return;
	}

	// 현 위치가 사용된 경우에는 다음 위치로 넘어가기
	if (is_used[cur_i_index][cur_j_index]) {
		solution(num + 1, sum);
	}
	else {
		int ni, nj;
		string cur_paper;
		cur_paper = paper[cur_i_index][cur_j_index];

		// 1. 현 위치만 사용한 것
		is_used[cur_i_index][cur_j_index] = true;
		solution(num + 1, sum + stoi(cur_paper));
		is_used[cur_i_index][cur_j_index] = false;

		// 2. 밑으로 자르기
		// 자를 수 있는 위치를 제한하여 인덱스 벗어나지 않게 하기!
		for (int k = 1; k < N - cur_i_index; k++) {
			// 항상 오른쪽으로 이동하고, 밑으로만 자르므로 밑으로 자를 경우에는 사용된 인덱스가 나올 일이 없음

			// 현위치 잡아주기
			nj = cur_j_index;
			ni = cur_i_index + k;
			// 값 하나가 추가되면 현 위치의 값의 자리수가 하나씩 증가하는 것이므로 추가
			cur_paper += paper[ni][nj];

			// 현 위치까지만 자른 것
			for (int j = 1; j <= k; j++)
				is_used[cur_i_index + j][nj] = true;
			solution(num + 1, sum + stoi(cur_paper));
			for (int j = 1; j <= k; j++)
				is_used[cur_i_index + j][nj] = false;
		}
		cur_paper = paper[cur_i_index][cur_j_index];
		// 3. 오른쪽으로 자르기
		// 자를 수 있는 위치를 제한하여 인덱스 벗어나지 않게 하기!
		for (int k = 1; k < M - cur_j_index; k++) {
			// 현 위치 잡아주기
			ni = cur_i_index;
			nj = cur_j_index + k;

			// 현 위치가 사용된 위치일 경우 더이상 진행하지 않고 리턴
			if (is_used[ni][nj]) return;
			cur_paper += paper[ni][nj];
			
			// 현 위치까지만 자른 것
			for (int j = 1; j <= k; j++) 
				is_used[ni][cur_j_index + j] = true;
			solution(num + 1, sum + stoi(cur_paper));
			for (int j = 1; j <= k; j++)
				is_used[ni][cur_j_index + j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		paper.push_back(str);
	}
	solution(0, 0);
	cout << answer;
	return 0;
}
