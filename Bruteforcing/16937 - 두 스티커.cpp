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

#define MAX 100
#define R	0
#define C	1

long long stickers[MAX][2];
int curMax;
int H, W, N;

inline bool canBePlaced(int firstR, int firstC, int secondR, int secondC) {
	if ((max(firstR, secondR) <= H && firstC + secondC <= W) ||
		(max(firstC, secondC) <= W && firstR + secondR <= H)
		) return true;
	return false;
}

bool isPossible(int firstStickerIndex, int secondStickerIndex) {
	// 1. 회전 하지 않았을 경우
	if (canBePlaced(stickers[firstStickerIndex][R], stickers[firstStickerIndex][C],
		stickers[secondStickerIndex][R], stickers[secondStickerIndex][C])) 
		return true;
	
	// 2. 첫번재 스티커만 회전했을 경우
	if (canBePlaced(stickers[firstStickerIndex][C], stickers[firstStickerIndex][R],
		stickers[secondStickerIndex][R], stickers[secondStickerIndex][C]))
		return true;

	// 3. 두번재 스티커만 회전했을 경우
	if (canBePlaced(stickers[firstStickerIndex][R], stickers[firstStickerIndex][C],
		stickers[secondStickerIndex][C], stickers[secondStickerIndex][R]))
		return true;

	// 4. 두 스티커 모두 회전했을 경우
	if (canBePlaced(stickers[firstStickerIndex][C], stickers[firstStickerIndex][R],
		stickers[secondStickerIndex][C], stickers[secondStickerIndex][R]))
		return true;

	return false;
}

inline int getArear(int firstStickerIndex, int secondStickerIndex) {
	return stickers[firstStickerIndex][R] * stickers[firstStickerIndex][C] +
		stickers[secondStickerIndex][R] * stickers[secondStickerIndex][C];
}

int solution() {
	// 조합
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (isPossible(i, j)) curMax = max(curMax, getArear(i, j));
	
	return curMax;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> stickers[i][R] >> stickers[i][C];

	cout << solution();
}