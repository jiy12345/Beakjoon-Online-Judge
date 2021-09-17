#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석

 - 변수
- 한 줄의 수식이 주어진다.
- 수식은 0~9, +, -로만 이루어져 있다.

 - 변수, 값에 대한 제한
- 가장 처음과 마지막 문자는 숫자이다.
- 연속해서 두 개 이상의 연산자는 나타나지 않는다.
- 5자리보다 많이 연속되는 숫자는 없다.
- 수는 0으로 시작할 수 있다.
- 식의 길이는 50보다 작거나 같다

 - 문제 상황
 수식이 주어졌을 때, 괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하라

2. 풀이 계획
문제와 예시를 살펴보면, 숫자의 가운데를 자르거나 연산자를 부호처럼 포함해서 잘라 곱셈을 만드는 것은 없어 보인다.

=> 그렇다면 식의 결과를 바꿀 수 있는 것은 - 로 어떻게 묶느냐에 달려있다. -로 묶은 값이 최대값이 되도록 하면된다.

 첫 - 연산자를 발견했다면, 그 뒤의 값들은 모두 빼는 값으로 간주해도 된다.

따라서

1. 문자열 변수에 식을 받는다.
2. 한 문자 씩 보며, 첫 - 가 나올 때 까지는 값들을 더하고, 첫 - 이후에는 값들을 모두 뺀다.

3. 계획 검증
첫 - 연산자 이후 그 뒤의 값들은 모두 빼는 값으로 간주해도 되는 이유는 다음과 같다.
 첫 - 연산자 이후 + 연산자가 나온다면 모두 괄호로 묶는 것으로 간주하여 모두 빼는 값으로 간주할 수 있다.
 첫 - 연산자 이후 - 연산자들만 나온다면 굳이 괄호로 묶지 않아도 최소값이 유지된다.
 첫 - 연산자 이후 + 연산자와 - 연산자가 번갈아 나와도 + 연산자는 모두 이전에 나왔단 - 연산자와 묶여 모두 빼는 값으로 전환될 수 있다.

 식의 길이는 50 이하이므로 시간의 제약이 있어보이지는 않았다.

 */

int get_min_num(string expression) {
	int min_num = 0; // 최소값을 저장할 변수
	int index;
	int i;

	// - 로 먼저 토큰화
	string plus_expression="";
	string minus_expression="";

	i = expression.find('-');

	plus_expression = expression.substr(0, i);
	if (i != -1) {
		minus_expression = expression.substr(i + 1);
	}

	// 
	string temp_string = "";
	for (i = 0; i < plus_expression.size(); i++) {

		if (plus_expression[i] == '+' || plus_expression[i] == '-') {
			min_num += stoi(temp_string);
			temp_string = "";
		}
		else{
			temp_string += plus_expression[i];
		}
	}
	if (!temp_string.empty()) {
		min_num += stoi(temp_string);
		temp_string = "";
	}

	temp_string = "";
	for (i = 0; i < minus_expression.size(); i++) {

		if (minus_expression[i] == '+' || minus_expression[i] == '-') {
			min_num -= stoi(temp_string);
			temp_string = "";
		}
		else {
			temp_string += minus_expression[i];
		}
	}
	if (!temp_string.empty()) {
		min_num -= stoi(temp_string);
		temp_string = "";
	}

	return min_num;
}

int main() {

	string expression;

	cin >> expression;

	cout<< get_min_num(expression);

	return 0;
}