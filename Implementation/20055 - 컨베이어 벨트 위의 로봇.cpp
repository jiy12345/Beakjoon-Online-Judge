#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

/*
1. 문제 분석
- 변수
N: 컨베이어 벨트의 길이
K: 내구도가 0인 칸의 개수가 K개 이상이면 과정 종료
Ai: i번 칸의 내구도
 => 1번 위치: 올리는 위치
 => N번 위치: 내리는 위치


- 변수 제한 사항
N: 1 ~ 7
K: 1 ~ 2N
Ai: 1 ~ 1,000

- 문제 상황

벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
  로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.


2. 풀이 계획
 회전 모든 정보를 회전 시키되, 다음과 같은 규칙을 따르도록 하자.




3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int N, K, numOfZero;

deque<int> A;

void rotate(deque<bool>& hasRobot) {
	hasRobot.push_front(hasRobot.back());
	hasRobot.pop_back();
	// 내리는 위치에서 로봇 빼기
	hasRobot[N - 1] = false;

	A.push_front(A.back());
	A.pop_back();
}

void robotMove(deque<bool>& hasRobot) {
	for (int i = N - 2; i >= 0; i--) {
		// 해당 위치에 로봇이 없을 경우 진행 x
		if (hasRobot[i] == false) continue;
		
		// 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야
		if (hasRobot[i + 1] == false && A[i + 1] >= 1) {
			// 다음 칸으로 로봇 옮기기
			hasRobot[i] = false;
			hasRobot[i + 1] = true;
			// 이동한 칸의 내구도 1 감소
			A[i + 1]--;

			// 내구도가 0인 칸의 개수 세기
			if (A[i + 1] == 0) numOfZero++;
		}
	}

	// 내리는 위치에서 로봇 빼기
	hasRobot[N - 1] = false;
}

int solution() {
	int step_cnt = 0;

	deque<bool> hasRobot(2 * N, false);


	while (true) {
		step_cnt++;
		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한칸 회전
		rotate(hasRobot);

		// 2. 가장 먼저 벨트에 올라간 로봇부터 벨트가 회전하는 방향으로 한칸 이동할 수 잇다면 이동
		robotMove(hasRobot);

		// 4. 올리는 위치에 있는 칸의 내구도가 0이 아니라면 올리는 위치에 로봇을 올린다.
		if (A[0] >= 1) {
			hasRobot.front() = true;
			A[0]--;

			// 내구도가 0인 칸의 개수 세기
			if (A[0] == 0) numOfZero++;
		}

		if (numOfZero >= K) break;
	}

	return step_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++) {
		int Ai;
		cin >> Ai;
		A.push_back(Ai);
	}

	cout << solution();

	return 0;
}