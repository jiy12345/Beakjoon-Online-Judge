#include<iostream>
#include<map>
using namespace std;

string input;

void GetNumOfAlpha(map<char, int>&num_of_atom, const string &input) {
	int string_length = input.length();
	int index = 0;
	while (true) {
		input[index];
		if (index + 1 >= string_length) {
			num_of_atom[input[index]]++;
			break;
		}
		else {
			if (isalpha(input[index + 1])) {
				num_of_atom[input[index]]++;
				index++;
			}
			else {
				num_of_atom[input[index]] += (input[index + 1] -'0');
				index += 2;
			}
		}

		if (index >= string_length) {
			break;
		}
	}
}

void solution() {
	string op1, op2, res;
	map<char, int> op1_num;
	map<char, int> op2_num;
	map<char, int> res_num;


	int index_plus = input.find('+');
	int index_equal = input.find('=');
	op1 = input.substr(0, index_plus);
	op2 = input.substr(index_plus + 1, index_equal - index_plus - 1);
	res = input.substr(index_equal + 1);

	GetNumOfAlpha(op1_num, op1);
	GetNumOfAlpha(op2_num, op2);
	GetNumOfAlpha(res_num, res);
	
	int i, j, k;
	bool isFound = false;
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			for (k = 1; k <= 10; k++) {
				if (i * op1_num['C'] + j * op2_num['C'] == k * res_num['C'] &&
					i * op1_num['H'] + j * op2_num['H'] == k * res_num['H'] &&
					i * op1_num['O'] + j * op2_num['O'] == k * res_num['O']) {
					isFound = true;
					break;
				}
			}
			if (isFound) break;
		}
		if (isFound) break;
	}

	cout << i << ' ' << j << ' ' << k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;
	
	solution();

}