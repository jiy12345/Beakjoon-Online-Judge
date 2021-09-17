#include<iostream>
#include<string>
using namespace std;

int get_min_num(string expression) {
	int min_num = 0; // 최소값을 저장할 변수
	int index;
	int i;

	
	string plus_expression="";
	string minus_expression="";

	i = expression.find('-');
	
	// 첫 - 기준으로 먼저 나누기
	plus_expression = expression.substr(0, i);
	if (i != -1) {
		minus_expression = expression.substr(i + 1);
	}

	// 첫 - 기준으로 앞쪽 수들은 모두 더하기
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
	// 첫 - 기준으로 뒷쪽 수들은 모두 빼기
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
