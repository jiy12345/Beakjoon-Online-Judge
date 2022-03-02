#include<iostream>
#include<string>
using namespace std;

#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

int T, K;
string Gears[1000];

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
		int whetherToRotate[1000] = { 0, };
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

	return 0;
}
