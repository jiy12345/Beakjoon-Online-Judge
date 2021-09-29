#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int solution(int N) {
	int i, j, k;
    // 각 빌딩의 높이를 저장할 배열
	vector<int> building_h;
    
    // able_to_see[i][j] = 1: i위치의 건물에서 j 위치의 건물을 볼 수 있다
	// able_to_see[i][j] = 0: i위치의 건물에서 j 위치의 건물을 볼 수 없다
	int** able_to_see = new int* [N];

	for (int i = 0; i < N; i++) {
		able_to_see[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			able_to_see[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		building_h.push_back(temp);
	}



	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) { // i와 j 건물 비교
			// 두 지점 사이의 직선의 방정식 구하기
			double a = (double) (building_h[j] - building_h[i]) / (j - i); // 기울기
			double b = (double) - (building_h[j] - building_h[i]) * (i + 1) / (j - i) + building_h[i]; // y절편

			for (k = i + 1; k < j; k++) { // 각 위치의 좌표를 직선의 방정식에 대입한 값과 실제 건물 높이 비교
				if (building_h[k] >= a * (k + 1) + b) { // 좌표가 1부터 시작하므로 + 1 해줘야!
					break;
				}
			}
			if (k == j) { // 모든 건물에 대해 무사히 통과하면
				// i에서 j가 보인다는 것을 1로 표시
				// i에서 j가 보이면 j에서도 i가 보이므로 같이 1로 설정
				able_to_see[i][j] = able_to_see[j][i] = 1;
			}
		}
	}

	int max = 0;
	for (int i = 0;i < N;i++) {
        // 같은 행의 값들 합해주기
		int temp = accumulate(able_to_see[i], able_to_see[i] + N, 0);
		// max보다 현재 받아온 값이 크면 max 갱신
        if (max < temp) {
			max = temp;
		}
	}

	return max;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}
