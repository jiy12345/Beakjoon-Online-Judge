#include<iostream>
using namespace std;

int get_min_coin(int N, int K, int* coin_unit) {
	int min_coin = 0;

	// 2. 반복문을 돌리며 큰 단위부터 작은 단위 순으로 K를 나누기
	for (int i = N - 1; i >= 0; i--) {
		// 나눈 몫은 동전의 개수에 더하기
		min_coin += K / coin_unit[i];
		// 나눈 나머지 K에 저장
		K %= coin_unit[i];
	}
	return min_coin;
}

int main() {
	int N; // 동전의 종류
	int K; // 나타내야 하는 총 가치


	cin >> N >> K;

	int *coin_unit = new int[N];

	// 들어온 단위들 배열에 받기
	for (int i = 0; i < N; i++) {
		cin >> coin_unit[i];
	}

	int min_coin = get_min_coin(N, K, coin_unit);

	cout << min_coin;

	return 0;
}
