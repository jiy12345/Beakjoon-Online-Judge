#include<iostream>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
N: 배열의 세로, 가로 길이는 2^N
R: 연산의 개수
k: 연산의 번호
l: 부분 배열의 크기가 2^l


- 변수 제한 사항
N: 1 ~ 7
R: 1 ~ 1,000
배열의 각 원소: -999 ~ 999

k = 1: 각 부분 배열 내부 상하 반전
k = 2: 각 부분 배열 내부 좌우 반전
k = 3: 각 부분 배열 내부 오른쪽으로 90도 회전
k = 4: 각 부분 배열 내부 왼쪽으로 90도 회전
k = 5: 각 부분 배열 간 상하 반전
k = 6: 각 부분 배열 간 좌우 반전
k = 7: 각 부분 배열 간 오른쪽으로 90도 회전
k = 8: 각 부분 배열 간 왼쪽으로 90도 회전


- 문제 상황
배열에 R개의 연산을 순서대로 수행한 결과를 구하여라

2. 풀이 계획
1, 2번 연산: swap 연산을 통해 진행하면 될 듯 하다.
 => 반복 횟수를 계산하는 것이 아니라 각 반복때마다 sub array의 크기만큼 더하면 될 듯 하다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int N, R, k, l, sizeOfArray;
int A1[128][128];
int A2[128][128];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void operationOne(int sizeOfSubArray) {
	// 각 부분별로 연산 진행
	for (int i = 0; i < sizeOfArray; i += sizeOfSubArray) {
		for (int j = 0; j < sizeOfArray; j += sizeOfSubArray) {
			// 끝 위치 설정
			int end_i = i + sizeOfSubArray;
			int end_j = j + sizeOfSubArray;

			for (int k = i; k < end_i; k++) {
				for (int l = j; l < end_j; l++) {
					A2[end_i - 1 - k + i][l] = A1[k][l];
				}
			}
		}
	}
	memcpy(A1, A2, sizeof(A2));
}

void operationTwo(int sizeOfSubArray) {
	// 각 부분별로 연산 진행
	for (int i = 0; i < sizeOfArray; i += sizeOfSubArray) {
		for (int j = 0; j < sizeOfArray; j += sizeOfSubArray) {
			// 끝 위치 설정
			int end_i = i + sizeOfSubArray;
			int end_j = j + sizeOfSubArray;

			for (int k = i; k < end_i; k++) {
				for (int l = j; l < end_j; l++) {
					A2[k][end_j - 1 - l + j] = A1[k][l];
				}
			}
		}
	}
	memcpy(A1, A2, sizeof(A2));
}

void operationThree(int sizeOfSubArray) {
	// 각 부분별로 연산 진행
	for (int i = 0; i < sizeOfArray; i += sizeOfSubArray) {
		for (int j = 0; j < sizeOfArray; j += sizeOfSubArray) {
			// 끝 위치 설정
			int end_i = i + sizeOfSubArray;
			int end_j = j + sizeOfSubArray;
 
			for (int k = i; k < end_i; k++) {
				for (int l = j; l < end_j; l++) {
					A2[l - j + i][end_i - 1 - k + j] = A1[k][l];
				}
			}
		}
	}
	memcpy(A1, A2, sizeof(A2));
}

void operationFour(int sizeOfSubArray) {
	// 각 부분별로 연산 진행
	for (int i = 0; i < sizeOfArray; i += sizeOfSubArray) {
		for (int j = 0; j < sizeOfArray; j += sizeOfSubArray) {
			// 끝 위치 설정
			int end_i = i + sizeOfSubArray;
			int end_j = j + sizeOfSubArray;

			for (int k = i; k < end_i; k++) {
				for (int l = j; l < end_j; l++) {
					A2[end_j - 1 - l + i][k + j - i] = A1[k][l];
				}
			}
		}
	}
	memcpy(A1, A2, sizeof(A2));
}

void operationFive(int sizeOfSubArray) {
	operationOne(sizeOfArray);
	operationOne(sizeOfSubArray);
}

void operationSix(int sizeOfSubArray) {
	operationTwo(sizeOfArray);
	operationTwo(sizeOfSubArray);
}

void operationSeven(int sizeOfSubArray) {
	operationThree(sizeOfArray);
	operationFour(sizeOfSubArray);
}

void operationEight(int sizeOfSubArray) {
	operationFour(sizeOfArray);
	operationThree(sizeOfSubArray);
}

void solution() {

	for (int i = 0; i < R; i++) {
		cin >> k >> l;

		int sizeOfSubArray = (1 << l);;

		switch (k) {
		case 1:
			operationOne(sizeOfSubArray);
			break;
		case 2:
			operationTwo(sizeOfSubArray);
			break;
		case 3:
			operationThree(sizeOfSubArray);
			break;
		case 4:
			operationFour(sizeOfSubArray);
			break;
		case 5:
			operationFive(sizeOfSubArray);
			break;
		case 6:
			operationSix(sizeOfSubArray);
			break;
		case 7:
			operationSeven(sizeOfSubArray);
			break;
		case 8:
			operationEight(sizeOfSubArray);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R;

	sizeOfArray = (1 << N);

	for (int i = 0; i < sizeOfArray; i++) {
		for (int j = 0; j < sizeOfArray; j++) {
			cin >> A1[i][j];
		}
	}

	solution();

	for (int i = 0; i < sizeOfArray; i++) {
		for (int j = 0; j < sizeOfArray; j++) {
			cout << A1[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}