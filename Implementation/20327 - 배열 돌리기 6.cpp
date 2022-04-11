#include<iostream>
#include<cstring>
using namespace std;

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
