#include<iostream>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
s: 숫자의 크기(각각 -와 |의 개수)
n: 나타내야할 수

- 변수 제한 사항
s: 1 ~ 10
n: 0 ~ 9,999,999,999


- 문제 상황
각 숫자를 길이가 s인 '-'와 '|'를 이용해서 출력해야 한다. 
각 숫자는 모두 s+2의 가로와 2s+3의 세로로 이루어 진다. 
나머지는 공백으로 채워야 한다. 
각 숫자의 사이에는 공백이 한 칸 있어야 한다.

2. 풀이 계획

최대 10자리

가장 긴 길이 10

따라서 가로 최대 길이
13 x 10 = 130

배열에 받아놓고 출력하면 될 듯 하다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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
// s: 한 획의 길이
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