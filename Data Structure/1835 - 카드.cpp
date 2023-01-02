#include<iostream>
#include<deque>
using namespace std;

deque<int> deck_of_cards;
int N;

void solution() {
	int cur_number = N;
	for (int i = N; i > 0; i--) {
		deck_of_cards.push_front(cur_number--);
		for (int j = 0; j < i; j++) {
			deck_of_cards.push_front(deck_of_cards.back());
			deck_of_cards.pop_back();
		}
	}

	for (int i = 0; i < deck_of_cards.size(); i++) {
		cout << deck_of_cards[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();
}