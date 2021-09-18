#include<iostream>
using namespace std;

// 방향에 따른 이동을 진행하는 함수
void move(int &r, int &c, int d) {
	switch (d) {
	case 0:
		r--;
		break;
	case 1:
		c++;
		break;
	case 2:
		r++;
		break;
	case 3:
		c--;
	}
}

// 각 방향에 있는 공간의 상태를 체크해주는 함수
int check(int r, int c, int d, int **space) {
	switch (d) {
	case 0:
		return space[r - 1][c];
	case 1:
		return space[r][c + 1];
	case 2:
		return space[r + 1][c];
	case 3:
		return space[r][c - 1];
	}
}

// 왼쪽으로 회전
void turn_left(int& d) {
	d--;
	if (d == -1) {
		d = 3;
	}
}

int solution (int N, int M, int r, int c, int d) {
	
	int answer = 0;

	// 로봇 청소기가 있는 공간에 해당하는 배열 동적할당 받기
	// 0: 청소되어 있지 않은 공간, 1: 벽, 2: 청소된 공간
	int** space = new int*[N];
	for (int i = 0; i < N; i++)
		space[i] = new int[M];

	// 값 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> space[i][j];
		}
	}

	while (true) {
		int i = 0;
		// 1. 현재 위치를 청소한다.
		if (space[r][c] == 0) {
			space[r][c] = 2;
			answer++;
		}

		// 2. 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
		for (i = 0; i < 4; i++) {
			
			turn_left(d);
			// 1) 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한칸을 전진하고 1번부터 진행한다.
			if (check(r, c, d, space) == 0){
				move(r, c, d);
				break;
			}
		}
		
		if (i == 4) { // 네 방향 모두 청소되어있거나 벽인 경우
			int backward_direction = (d - 2 >= 0) ? (d - 2) : (d - 2) + 4;
			int backward_direction_state = check(r, c, backward_direction, space);
			if (backward_direction_state == 2) { // 뒤쪽이 청소된 공간일 경우
				move(r, c, backward_direction);
			}
			else if (backward_direction_state == 1) { // 뒤쪽이 벽일 경우
				break; // 청소 종료
			}
		}

	}

	return answer;
}

int main() {

	int N, M;

	cin >> N >> M;

	int r, c, d;

	cin >> r >> c >> d;

	cout << solution(N, M, r, c, d);

	return 0;
}
