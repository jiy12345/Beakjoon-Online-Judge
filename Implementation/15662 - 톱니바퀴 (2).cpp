#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
T: 톱니바퀴의 개수
K: 회전 횟수



- 변수 제한 사항
T: 1 ~ 1,000
N극: 0
S극: 1

K: 1 ~ 1,000
시계방향: 1
반시계방향: -1

- 문제 상황

이전 톱니바퀴가 시계 또는 반시계 방향으로 회전하였을 때,

맞닿은 부분의 극(이전의 2번째 이후의 6번째)이 다르다면 이전의 톱니가 회전한 반대 방향으로 회전
맞닿은 부분의 극(이전의 2번째 이후의 6번째)이 같다면 회전하지 않는다.


2. 풀이 계획


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

int T, K;
string Gears[100];

void Rotate(string & Gear, int directionOfRotation) {
	cout << directionOfRotation << endl;
	if (directionOfRotation == CLOCKWISE) {
		Gear = Gear[7] + Gear.substr(0, 7);
	}
	else if(directionOfRotation == COUNTERCLOCKWISE) {
		Gear = Gear.substr(1) + Gear[0];
	}
}

int solution() {
	int answer = 0;

	cin >> K;

	for (int i = 0; i < K; i++) {
		int whetherToRotate[100] = { 0, };
		int startGearNum;
		int startDirectionOfRotation;
		int DirectionOfRotation;
		cin >> startGearNum >> startDirectionOfRotation;
		
		startGearNum--;

		whetherToRotate[startGearNum] = startDirectionOfRotation;

		DirectionOfRotation = startDirectionOfRotation * -1;

		// 오른쪽 방향의 톱니바퀴 회전
		for (int j = startGearNum + 1; j < T; j++) {
			if (Gears[j - 1][2] == Gears[j][6]) {
				break;
			}
			else {
				// 이전 회전 방향과 반대방향
				whetherToRotate[j] = DirectionOfRotation;
				DirectionOfRotation = DirectionOfRotation * -1;
			}
		}

		DirectionOfRotation = startDirectionOfRotation * -1;

		// 왼쪽 방향의 톱니바퀴 회전
		for (int j = startGearNum - 1; j >= 0 ; j--) {
			if (Gears[j][2] == Gears[j + 1][6]) {
				break;
			}
			else {
				// 이전 회전 방향과 반대방향
				whetherToRotate[j] = DirectionOfRotation;
				DirectionOfRotation = DirectionOfRotation * -1;
			}
		}

		for (int j = 0; j < T; j++) {
			Rotate(Gears[j], whetherToRotate[j]);
		}
	}

	for (int i = 0; i < T; i++) {
		answer += Gears[i][0] - 48;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> Gears[i];
	}

	cout << solution();

	//string Gear = "10001010";

	//Rotate(Gear, COUNTERCLOCKWISE);

	//cout << Gear;



	return 0;
}