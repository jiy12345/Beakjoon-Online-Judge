#include<iostream>
#include<string>
#include <bitset>
using namespace std;

int dx[4] = { 1, -1, 0,  0 };
int dy[4] = { 0,  0, 1, -1 };

string board[20];

int R, C;

bool is_visited[20][20];

int solution(int cur_i, int cur_j, int bit_masking, int cur_depth) {
	int max_num = cur_depth;

	// A: 65, Z: 90
	
	// 방문 표시 후 다음 탐색 시작
	is_visited[cur_i][cur_j] = true;
	for (int i = 0;i < 4;i++) {
		int next_i = cur_i + dx[i];
		int next_j = cur_j + dy[i];

		// 범위를 벗어났을 경우에는 탐색을 진행하지 않음
		if (next_i >= R || next_i < 0 || next_j >= C || next_j < 0) {
			continue;
		}
		else {
			char next_alphabet = board[next_i][next_j];
			int next_alpha_bit = (1 << (next_alphabet - 65));
			int bit_masking_result = bit_masking | next_alpha_bit;
			// 지금까지 방문하지 않았던 알파벳일 경우에만 진행
			if ((bit_masking_result != bit_masking) && is_visited[next_i][next_j] == false) {
				max_num = max(max_num, solution(next_i, next_j, bit_masking_result, cur_depth + 1));
			}
		}
	}
	// 방문 표시 지우기
	is_visited[cur_i][cur_j] = false;


	return max_num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> R >> C;

	for (int i = 0;i < R;i++) {
		cin >> board[i];
	}

	// 첫 알파벳에 대한 비트마스킹 진행
	char start_alphabet = board[0][0];
	int start_alpha_bit = (1 << (start_alphabet - 65));

	cout << solution(0, 0, start_alpha_bit, 1);

	return 0;
}
