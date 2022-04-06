#include<iostream>
#include<cstring>
using namespace std;

char buffer[23][130];

void lineA(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[0][cur_location + 1 + i] = '-';
	}
}

void lineB(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[i + 1][cur_location + s + 1] = '|';
	}
}

void lineC(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[s + 2 + i][cur_location + s + 1] = '|';
	}
}

void lineD(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[2 * s + 2][cur_location + 1 + i] = '-';
	}
}

void lineE(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[s + 2 + i][cur_location] = '|';
	}
}

void lineF(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[i + 1][cur_location] = '|';
	}
}

void lineG(int cur_location, int s) {
	for (int i = 0; i < s; i++) {
		buffer[s + 1][cur_location + 1 + i] = '-';
	}
}

void one(int cur_location, int s){
	lineB(cur_location, s);
	lineC(cur_location, s);
}

void two(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineG(cur_location, s);
	lineE(cur_location, s);
	lineD(cur_location, s);
}

void three(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineG(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
}

void four(int cur_location, int s) {
	lineF(cur_location, s);
	lineG(cur_location, s);
	lineB(cur_location, s);
	lineC(cur_location, s);
}

void five(int cur_location, int s) {
	lineA(cur_location, s);
	lineF(cur_location, s);
	lineG(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
}

void six(int cur_location, int s) {
	lineG(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
	lineE(cur_location, s);
	lineF(cur_location, s);
	lineA(cur_location, s);
}

void seven(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineC(cur_location, s);
}

void eight(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
	lineE(cur_location, s);
	lineF(cur_location, s);
	lineG(cur_location, s);
}

void nine(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
	lineF(cur_location, s);
	lineG(cur_location, s);
}

void zero(int cur_location, int s) {
	lineA(cur_location, s);
	lineB(cur_location, s);
	lineC(cur_location, s);
	lineD(cur_location, s);
	lineE(cur_location, s);
	lineF(cur_location, s);
}

void solution(int s, string number) {
	memset(buffer, ' ', sizeof(buffer));

	for (int i = 0; i < number.length(); i++) {
		int cur_location = i * (s + 3);

		switch (number[i]) {
		case '1':
			one(cur_location, s);	
			break;
		case '2':
			two(cur_location, s);
			break;
		case '3':
			three(cur_location, s);
			break;
		case '4':
			four(cur_location, s);
			break;
		case '5':
			five(cur_location, s);
			break;
		case '6':
			six(cur_location, s);
			break;
		case '7':
			seven(cur_location, s);
			break;
		case '8':
			eight(cur_location, s);
			break;
		case '9':
			nine(cur_location, s);
			break;
		case '0':
			zero(cur_location, s);
			break;
		}
	}

	int width = number.length() * (s + 3);
	int height = 2 * s + 3;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << buffer[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int s;
	string number;

	cin >> s >> number;

	solution(s, number);

	return 0;
}
