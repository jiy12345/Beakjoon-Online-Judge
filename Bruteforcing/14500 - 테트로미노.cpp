#include<iostream>
using namespace std;

/*
1. 庚薦 歳汐
- 痕呪
N: 曽戚税 室稽 掩戚
M: 曽戚税 亜稽 掩戚

- 痕呪 薦廃 紫牌
N, M: 4~500
曽戚拭 旋微 呪: 1~1,000

- 庚薦 雌伐
 曽戚税 滴奄亜 爽嬢走壱, 益 曽戚拭 床食赤澗 呪亜 爽嬢霜 凶, 
 砺闘稽耕葛研 壕帖馬食 気精 牒税 呪級税 杯税 置企葵聖 姥馬食虞 

 恥 陥叱亜走税 砺闘稽耕葛澗 企暢, 噺穿戚 亜管馬陥.

2. 熱戚 域塙

1. 延 乞丞: 室稽 亜稽 2鯵
2. い切 乞丞: 噺穿廃 依 4鯵 + 企暢馬食 噺穿廃 依 4鯵
3. 腰鯵乞丞: 噺穿廃 依 2鯵 + 企暢馬食 噺穿廃 依 2鯵
4. で 乞丞: 4鯵
5. 舛紫唖乞丞: 1鯵


3. 域塙 伊装

 巷惟拭 企背 神硯託授生稽 舛慶鞠嬢 赤生糠稽, 戚穿 亜号拭 隔聖 呪 赤澗 左汐級精 陥製 亜号拭亀 隔聖 呪 赤陥. 魚虞辞 酔識授是 泥拭 薄仙 壱形掻昔 左汐級聖 乞砧 眼焼黍陥檎, 薄仙 亜号拭 隔聖 呪 赤澗 左汐 掻 亜維戚 亜舌 株精 左汐聖 隔惟 吃 呪 赤陥.

*/

int N, M;

int paper[500][500];

bool isInRange(int i, int j) {
	if (0 <= i && i <= N - 1 && 0 <= j && j <= M - 1) return true;
	else return false;
}

int checkIMino(int i, int j) {
	int maxNum = 0;
	// け
	// け
	// け
	// け
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 3, j)) 
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
	// けけけけ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i, j + 3)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
	
	return maxNum;
}


int checkOMino(int i, int j) {
	int maxNum = 0;

	// けけ
	// けけ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1]);

	return maxNum;
}

int checkZMino(int i, int j) {
	int maxNum = 0;

	// けけ
	//   けけ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	//   け
	// けけ
	// け
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j]);

	return maxNum;
}

int checkSMino(int i, int j) {
	int maxNum = 0;

	//   けけ
	// けけ
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i, j + 1) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2]);
	// け
	// けけ
	//   け
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);

	return maxNum;
}
int checkJMino(int i, int j) {
	int maxNum = 0;

	//   け
	//   け
	// けけ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 2, j)) 
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j]);
	// け
	// けけけ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	// けけ
	// け
	// け
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j]);
	// けけけ
	//     け
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2]);

	return maxNum;
}

int checkLMino(int i, int j) {
	int maxNum = 0;

	// け
	// け
	// けけ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1]);
	// けけけ
	// け
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j]);
	// けけ
	//   け
	//   け
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
	//     け
	// けけけ
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2]);

	return maxNum;
}

int checkTMino(int i, int j) {
	int maxNum = 0;

	// けけけ
	//   け
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]);
	//   け
	// けけ
	//   け
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 1][j]);
	//   け
	// けけけ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 1][j + 2]);
	// け
	// けけ
	// け
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j]);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maxNum = max(maxNum, checkIMino(i, j));
			maxNum = max(maxNum, checkOMino(i, j));
			maxNum = max(maxNum, checkZMino(i, j));
			maxNum = max(maxNum, checkSMino(i, j));
			maxNum = max(maxNum, checkJMino(i, j));
			maxNum = max(maxNum, checkLMino(i, j));
			maxNum = max(maxNum, checkTMino(i, j));
		}
	}
	
	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	cout << solution();
}