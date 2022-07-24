#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
H, W: �������� ����, ���� ����
N: ��ƼĿ�� ����
Ri, Ci: i��° ��ƼĿ�� ����, ���� ����

- ���� ���� ����
 N: 1 ~ 100


- ���� ��Ȳ
 ũ�����忡 ������ ���� 4���� ��ư�� �ִٰ� �� ��,

ȭ�鿡 A�� ����Ѵ�.
Ctrl-A: ȭ���� ��ü �����Ѵ�
Ctrl-C: ��ü ������ ������ ���ۿ� �����Ѵ�
Ctrl-V: ���۰� ������� ���� ��쿡�� ȭ�鿡 ��µ� ���ڿ��� �ٷ� �ڿ� ������ ������ �ٿ��ִ´�.

 ũ�������� ��ư�� �� N�� ������ ȭ�鿡 ��µ� A ������ �ִ밪�� ���Ͽ���!

2. Ǯ�� ��ȹ

�ΰ��� ��ƼĿ�� �ִ��� ���� ���� ���� ��ġ�ϱ� ���ؼ��� �ִ��� ���� �������� ����ؾ� �Ѵ�.

��ƼĿ �ΰ��� ��ĥ �� �����Ƿ�, ������ ���� ��찡 ���� �� �ִ�.

�� ��ƼĿ�� �̴� ���� ������ ��� �����Ƿ�, �������� �̾ƾ� �Ѵ�.


1. �� ��ƼĿ�� ���η� �þ���´�.
 => �� ���, �� ��ƼĿ�� ������ ���� 2���� ������ üũ�ؾ� �Ѵ�.

 ���� ������ �� <= �������� ���� ����
 ���� ������ �ִ밪 <= �������� ���� ����

2. �� ��ƼĿ�� ���η� �þ���´�.
 ���� ������ �� <= �������� ���� ����
 ���� ������ �ִ밪 <= �������� ���� ����

 ����, �� ��ƼĿ�� ��� 90�� ȸ���� �����ϹǷ�, ȸ���� ���� 4���� ��츦 ��� üũ����� �Ѵ�!

3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
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
	// 1. ȸ�� ���� �ʾ��� ���
	if (canBePlaced(stickers[firstStickerIndex][R], stickers[firstStickerIndex][C],
		stickers[secondStickerIndex][R], stickers[secondStickerIndex][C])) 
		return true;
	
	// 2. ù���� ��ƼĿ�� ȸ������ ���
	if (canBePlaced(stickers[firstStickerIndex][C], stickers[firstStickerIndex][R],
		stickers[secondStickerIndex][R], stickers[secondStickerIndex][C]))
		return true;

	// 3. �ι��� ��ƼĿ�� ȸ������ ���
	if (canBePlaced(stickers[firstStickerIndex][R], stickers[firstStickerIndex][C],
		stickers[secondStickerIndex][C], stickers[secondStickerIndex][R]))
		return true;

	// 4. �� ��ƼĿ ��� ȸ������ ���
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
	// ����
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