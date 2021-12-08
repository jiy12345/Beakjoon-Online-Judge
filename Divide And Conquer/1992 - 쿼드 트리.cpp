#include<iostream>
using namespace std;

string image[64];
int N;

void solution(int start_i, int start_j, int size) {
	// 기저 사례: 분할된 부분의 크기가 1이어서 더이상 나눌 수 없을 때!
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
