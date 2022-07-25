#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
H, W: 모눈종이의 세로, 가로 길이
N: 스티커의 개수
Ri, Ci: i번째 스티커의 세로, 가로 길이

- 변수 제한 사항
 N: 1 ~ 100


- 문제 상황
 크리보드에 다음과 같은 4가지 버튼만 있다고 할 때,

화면에 A를 출력한다.
Ctrl-A: 화면을 전체 선택한다
Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.

 크리보드의 버튼을 총 N번 눌러서 화면에 출력된 A 개수의 최대값을 구하여라!

2. 풀이 계획

두개의 스티커를 최대한 작은 공간 내에 배치하기 위해서는 최대한 작은 공간만을 사용해야 한다.

스티커 두개는 겹칠 수 없으므로, 다음과 같은 경우가 있을 수 있다.

두 스티커를 뽑는 것은 순서가 상관 없으므로, 조합으로 뽑아야 한다.


1. 두 스티커를 세로로 늘어놓는다.
 => 이 경우, 두 스티커의 다음과 같은 2가지 조건을 체크해야 한다.

 세로 길이의 합 <= 모눈종이의 세로 길이
 가로 길이의 최대값 <= 모눈종이의 가로 길이

2. 두 스티커를 가로로 늘어놓는다.
 가로 길이의 합 <= 모눈종이의 가로 길이
 세로 길이의 최대값 <= 모눈종이의 세로 길이

 또한, 각 스티커는 모두 90도 회전이 가능하므로, 회전에 따른 4가지 경우를 모두 체크해줘야 한다!

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

int Map[5][5];
int answer = 0; 
bool isVisited[1000000];
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 }; 

inline bool isInRange(int i, int j) {
	return 0 <= i && i < 5 && 0 <= j && j < 5;
}

void DFS(int cur_i, int cur_j, int cur_num, int cnt) {
	if (cnt == 5) {
		if (isVisited[cur_num] == false) {
			isVisited[cur_num] = true;
			answer++;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		if (isInRange(next_i, next_j)) {
			DFS(next_i, next_j, cur_num * 10 + Map[next_i][next_j], cnt + 1);
		}
	}
}

void Solution() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) { 
			DFS(i, j, Map[i][j], 0);
		}
	}
	
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> Map[i][j];

	Solution();
}
