#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 배열의 세로 길이
M: 배열의 가로 길이
R: 연산의 개수
Aij: 주어지는 배열의 i행 j열 원소

- 변수 제한 사항
N, M: 2 ~ 100
R: 1 ~ 1,000
Aij: 1 ~ 10,000,000

- 문제 상황
 수빈이와 동생의 위치가 주어지고, 수빈이는 다음과 같이 이동한다고 하자.

 수빈이의 현 위치가 X일 때,

 - 걷기: 1초후에 X - 1 or X + 1
 - 순간이동: 0초 후에 2 * X

 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

2. 풀이 계획

0 - 1 로 간선이 서로 다른 가중치를 가지고 있기는 하지만,

우선순위 큐를 이동한다면?
 => 어떤 노드를 먼저 방문 했다고 했을 때, 그 방문까지 걸린 시간이 최단시간이라고 보장할 수 없기 때문에 안된다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


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