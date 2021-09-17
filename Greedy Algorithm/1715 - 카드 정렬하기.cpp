#include<iostream>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

int get_min_num(priority_queue<int, vector<int>, greater<int>> num_cards, int N) {
	int min_num1, min_num2; // 각 반복에서의 최소값을 저장할 변수
	int min_num = 0; // 결합하는데 드는 총 횟수를 저장할 변수

	while (num_cards.size() != 1) {
		// 현재 가장 적은 수를 가진 카드 두 뭉치 뽑기
		min_num1 = num_cards.top(); num_cards.pop();
		min_num2 = num_cards.top(); num_cards.pop();
		
		// 두 카드 뭉치 합치기
		min_num += (min_num1 + min_num2);
		// 뭉친 카드 뭉치를 다시 카드 뭉치 priority queue에 집어넣기
		num_cards.push(min_num1 + min_num2);
	}
	return min_num;
}

int main() {

	int N; // 카드 뭉치의 수

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> num_cards;

	for (int i = 0; i < N; i++) {
		int num_cards_temp;
		cin >> num_cards_temp;
		num_cards.push(num_cards_temp);
	}

	cout << get_min_num(num_cards, N);

	return 0;
}
