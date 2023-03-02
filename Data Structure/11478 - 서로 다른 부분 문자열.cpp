#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

unordered_set<string> string_set;
string input_string;

int solution() {
	int length_of_string = input_string.size();

	for (int i = 0;i < length_of_string;i++) {
		string cur_string = "";
		cur_string += input_string[i];
		string_set.insert(cur_string);

		for (int j = i + 1;j < length_of_string;j++) {
			cur_string += input_string[j];
			string_set.insert(cur_string);
		}
	}

	return string_set.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input_string;
	cout << solution();
}