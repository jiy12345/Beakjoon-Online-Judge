#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int P;
string teleCode = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

void solution() {
	char cur_teleCode;
	int cur_num;
	char cur_type;
	for (int i = 0; i < P; i++) {
		long double input;
		string input_s;
		cin >> input_s;
		input = stod(input_s);
		if (input < -1.0l || 1.0l <= input || input_s == "-1.0000000000000001") {
			cout << "INVALID VALUE\n";
			continue;
		}

		int decimal;
		decimal = (input < 0.0f) ? ceil(input * (1 << 16)) : floor(input * (1 << 16));
		cur_type = ((decimal & 0b1) == 1) ? 'D' : 'F';
		decimal >>= 1;
		cur_num = decimal & 0b11111111111;
		decimal >>= 11;
		cur_teleCode = teleCode[decimal & 0b11111];
		cout << cur_teleCode << " " << cur_num << " " << cur_type << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;

	solution();
}
