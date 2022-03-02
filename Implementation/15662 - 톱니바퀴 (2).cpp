#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
T: ��Ϲ����� ����
K: ȸ�� Ƚ��



- ���� ���� ����
T: 1 ~ 1,000
N��: 0
S��: 1

K: 1 ~ 1,000
�ð����: 1
�ݽð����: -1

- ���� ��Ȳ

���� ��Ϲ����� �ð� �Ǵ� �ݽð� �������� ȸ���Ͽ��� ��,

�´��� �κ��� ��(������ 2��° ������ 6��°)�� �ٸ��ٸ� ������ ��ϰ� ȸ���� �ݴ� �������� ȸ��
�´��� �κ��� ��(������ 2��° ������ 6��°)�� ���ٸ� ȸ������ �ʴ´�.


2. Ǯ�� ��ȹ


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

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

		// ������ ������ ��Ϲ��� ȸ��
		for (int j = startGearNum + 1; j < T; j++) {
			if (Gears[j - 1][2] == Gears[j][6]) {
				break;
			}
			else {
				// ���� ȸ�� ����� �ݴ����
				whetherToRotate[j] = DirectionOfRotation;
				DirectionOfRotation = DirectionOfRotation * -1;
			}
		}

		DirectionOfRotation = startDirectionOfRotation * -1;

		// ���� ������ ��Ϲ��� ȸ��
		for (int j = startGearNum - 1; j >= 0 ; j--) {
			if (Gears[j][2] == Gears[j + 1][6]) {
				break;
			}
			else {
				// ���� ȸ�� ����� �ݴ����
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