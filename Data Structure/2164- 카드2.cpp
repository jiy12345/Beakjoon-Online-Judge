#include<iostream>
#include<queue>
using namespace std;

int N;
queue<int> card_deck;

int solution() {
	for (int i = 1; i <= N; i++) {
		card_deck.push(i);
	}

	while (true) {
		if (card_deck.size() == 1) {
			break;
		}

		card_deck.pop();
		int top_card = card_deck.front();
		card_deck.pop();
		card_deck.push(top_card);
	}

	return card_deck.front();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();
}