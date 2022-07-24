#include<iostream>
using namespace std;

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
