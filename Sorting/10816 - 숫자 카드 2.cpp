#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<iostream>
using namespace std;

void solution() {
	int N, M;
	int temp; // 입력을 받기 위한 임시 변수
	unordered_map<int, int> num_cards;

	cin >> N;

	for (int i = 0;i < N;i++) {
		// cin, cout은 속도가 매우 느리므로 scanf, printf 사용!
		scanf("%d", &temp);
		num_cards[temp]++;
	}

	cin >> M;

	for (int i = 0;i < M;i++) {
		// cin, cout은 속도가 매우 느리므로 scanf, printf 사용!
		scanf("%d", &temp);
		printf("%d ", num_cards[temp]);
	}
}

int main() {

	solution();

	return 0;
}
