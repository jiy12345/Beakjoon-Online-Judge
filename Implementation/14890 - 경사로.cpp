#include<iostream>
using namespace std;

int N, L;
int Map[100][100];
int Map_Inv[100][100];

bool isPassable(int rowNum, int Map[][100]) {
	bool isPassable = true;

	int prevHeight = Map[rowNum][0];; // 이전의 높이
	int prevFlatNum = 1; // 이전까지의 평평한 땅의 개수 
	int cnt; // 경사로를 설치할만한 공간이 있는지 세기 위한 변수

	for (int i = 1; i < N; i++) {
		// 이전과 같은 높이일 경우
		if (Map[rowNum][i] == prevHeight) {
			prevFlatNum++;
			continue;
		} // 이전보다 하나 낮은 높이일 경우
		else if (Map[rowNum][i] == prevHeight - 1) {
			cnt = L - 1;
			while (true) {
				// 조건을 모두 만족하였을 경우
				if (cnt == 0) {
					break;
				}

				i++;
				cnt--;
				// 조건 1. 경사로를 설치할 공간을 두지 못하게 지도의 끝을 만났을 경우
				if (i == N) return false;
				// 조건 2. 경사로를 설치할 공간을 두지 못하게 높이가 변화하였을 경우
				if (Map[rowNum][i] != prevHeight - 1) return false;
			}
			prevFlatNum = 0; // 현 위치까지 내리막 경사로가 설치되었으므로
			prevHeight--;
		}
		else if (Map[rowNum][i] == prevHeight + 1) {
			if (prevFlatNum < L) {
				return false;
			}

			prevFlatNum = 1;
			prevHeight++;
		}
		else {
			return false;
		}
	}

	return isPassable;
}


int solution() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += isPassable(i, Map) ? 1 : 0;
		answer += isPassable(i, Map_Inv) ? 1 : 0;
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			Map_Inv[j][i] = Map[i][j];
		}
	}

	cout << solution();

	return 0;
}
