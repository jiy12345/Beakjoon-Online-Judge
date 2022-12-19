#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int N, M;
unordered_map<int, string> pokemon_list_num_to_name;
unordered_map<string, int> pokemon_list_name_to_num;

void solution() {
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		if (isalpha(input[0])) {
			cout << pokemon_list_name_to_num[input] << '\n';
		}
		else {
			cout << pokemon_list_num_to_name[stoi(input)] << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string pokemon;
		cin >> pokemon;
		pokemon_list_num_to_name.insert({ i, pokemon });
		pokemon_list_name_to_num.insert({ pokemon, i });
	}

	solution();
}