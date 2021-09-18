#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
1. 문제 분석

 - 변수
M x N: 로봇 청소기가 있는 공간의 크기
(r, c): 로봇 청소기가 놓여있는 좌표
 r: 북쪽으로부터 떨어진 칸의 개수
 c: 서쪽으로부터 떨어진 칸의 개수

d: 로봇 청소기가 바라보고 있는 방향(0인 경우 북쪽, 1인 경우 동쪽, 2인 경우 남쪽, 3인 경우 서쪽)

 - 변수, 값에 대한 제한
3 <= N, M <= 50

 - 문제 상황
 로봇 청소기가 다음과 같이 동작하며 로봇청소기가 있는 좌표와 바라보는 방향이 주어질 때
1. 현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
 1) 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
 2) 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
 3) 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
 4) 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

 러벗 창소기가 청소하는 칸의 개수를 출력한다.

2. 풀이 계획
 일단 로봇 청소기가 있는 공간은 이차원 배열에 저장해야 하며,

 나머지 구현은 조건대로 하나하나 만족 시키며 구현하면 될것 같다.

 방향을 어떻게 하면 깔끔하게 적용할 수 있을까?
  => 함수로 만들자!


3. 계획 검증
각 값이 나오는 빈도와 자릿수를 모두 고려하여 합한 값이 정렬기준이 되었으므로, 내림차순으로 정렬한 값들에 정렬한 순서대로 매긴다면 최대값을 구할 수 있다!

 */

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