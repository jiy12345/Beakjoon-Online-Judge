#include<iostream>
#include<map>
using namespace std;

int M, N;
map<string, int> numbers;

map<int, string> number_int_to_string = {
	{0, "zero"},
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
};

void solution() {
	for (int cur_number = M; cur_number <= N; cur_number++) {
		int number_to_calcul = cur_number;
		string cur_number_string = "";
		
		while (true) {
			int cur_digit_number = number_to_calcul % 10;
			cur_number_string = number_int_to_string[cur_digit_number] + cur_number_string;
			number_to_calcul /= 10;
			if (number_to_calcul == 0) break;
				cur_number_string = " " + cur_number_string;
		}
		numbers.insert({ cur_number_string, cur_number });
	}
	
	int line_change = 0;
	for (auto cur_number : numbers) {
		cout << cur_number.second << " ";
		line_change++;
		if (line_change % 10 == 0) {
			cout << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	solution();
}