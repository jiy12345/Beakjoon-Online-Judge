#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int N;
unordered_set<string> unique_words;

int solution() {
	int number_of_unique_words = 0;

	for (int i = 0; i < N; i++) {
		string cur_word;
		cin >> cur_word;
		if (unique_words.find(cur_word) == unique_words.end()) {
			number_of_unique_words++;
			unique_words.insert(cur_word);
			for (int i = 0; i < cur_word.length() - 1; i++) {
				cur_word = cur_word.substr(1) + cur_word[0];
				unique_words.insert(cur_word);
			}
		}
	}
	return number_of_unique_words;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();
}