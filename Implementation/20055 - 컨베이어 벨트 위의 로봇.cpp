#include<iostream>
#include<deque>
using namespace std;

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

		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니라면 올리는 위치에 로봇을 올린다.
		if (A[0] >= 1) {
			hasRobot.front() = true;
			A[0]--;

			// 내구도가 0인 칸의 개수 세기
			if (A[0] == 0) numOfZero++;
		}
		
		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
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
