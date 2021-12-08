#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 영상의 크기

- 변수 제한 사항
N: 1~64


- 문제 상황
주어진 영상이 모두 0으로 되어 있다면 압축 결과를 0으로, 모두 1로 되어 있다면 압축 결과는 1로 압축할 수 있다고 하며,
0과 1이 섞여 있다면 쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현해야 한다고 할 때,

주어진 영상을 압축한 결과를 출력하는 영상을 출력하는 프로그램을 작성하라!

2. 풀이 계획
 재귀적으로 호출을 진행하여, 각 위치를 압축한 내용을 각 위치에서 출력하면 될 듯 하다!

 => 이때, 넘겨줘야할 매개변수는, 시작좌표와 현재 사이즈정도 일 듯 하다!
*/

string image[64];
int N;


void solution(int start_i, int start_j, int size) {
	if (size == 1) {
		cout << image[start_i][start_j];
		return;
	}

	char cur_num = image[start_i][start_j];

	int i, j;

	for (i = start_i;i < start_i + size;i++) {
		//cout << i << ": ";
		for (j = start_j;j < start_j + size;j++) {
			//cout << image[i][j];
			if (cur_num != image[i][j]) {
				break;
			}
		}
		//cout << endl;
		if (j != start_j + size) {
			break;
		}
	}

	// 현재 범위의 이미지가 모두 같은 수를 가지고 있을 경우!
	if ((i == start_i + size) && (j == start_j + size)) {
		cout << cur_num;
	}
	else { // 현재 범위의 이미지가 0과 1을 모두 포함하는 경우
		cout << "(";
		// 왼쪽 위
		solution(start_i, start_j, size / 2);
		// 오른쪽 위
		solution(start_i, start_j + size / 2, size / 2);
		// 왼쪽 아래
		solution(start_i + size / 2, start_j, size / 2);
		// 오른쪽 아래
		solution(start_i + size / 2, start_j + size / 2, size / 2);
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> image[i];
	}

	solution(0, 0, N);

}