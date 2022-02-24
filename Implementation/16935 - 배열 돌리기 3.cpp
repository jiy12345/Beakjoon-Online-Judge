#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, R;
int operations[1000];
int A[100][100];
int A_temp[100][100];

void copyArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A_temp[i][j] = A[i][j];
		}
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void operationOne() {
	copyArray();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[N - i - 1][j] = A_temp[i][j];
		}
	}
}

void operationTwo() {
	copyArray();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][M - j - 1] = A_temp[i][j];
		}
	}
}

void operationThree() {
	copyArray();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[j][N - i - 1] = A_temp[i][j];
		}
	}
}

void operationFour() {
	copyArray();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[M - j - 1][i] = A_temp[i][j];
		}
	}
}

void operationFive() {
	copyArray();

	// 1 -> 2
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			A[i][j + M / 2] = A_temp[i][j];
		}
	}

	// 2 -> 3
	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			A[i + N / 2][j] = A_temp[i][j];
		}
	}
		
	// 3 -> 4
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			A[i][j - M / 2] = A_temp[i][j];
		}
	}
	
	// 4 -> 1
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			A[i - N / 2][j] = A_temp[i][j];
		}
	}
}

void operationSix() {
	copyArray();

	// 1 -> 4
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			A[i + N / 2][j] = A_temp[i][j];
		}
	}

	// 4 -> 3
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			A[i][j + M / 2] = A_temp[i][j];
		}
	}

	// 3 -> 4
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2; j < M; j++) {
			A[i - N / 2][j] = A_temp[i][j];
		}
	}

	// 2 -> 1
	for (int i = 0; i < N / 2; i++) {
		for (int j = M / 2; j < M; j++) {
			A[i][j - M / 2] = A_temp[i][j];
		}
	}
}

void solution() {
	
	for (int i = 0; i < R; i++) {
		switch (operations[i]) {
		case 1:
			operationOne();
			break;
		case 2:
			operationTwo();
			break;
		case 3:
			operationThree();
			swap(N, M);
			break;
		case 4:
			operationFour();
			swap(N, M);
			break;
		case 5:
			operationFive();
			break;
		case 6:
			operationSix();
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}


	for (int i = 0; i < R; i++) {
		cin >> operations[i];
	}

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
