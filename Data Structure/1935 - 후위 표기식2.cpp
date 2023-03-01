#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

int N;
int numbers[26];
string input_string;

double solution() {
	stack<double> calculation_stack;

	for (int i = 0;i < input_string.length();i++) {
		if (isalpha(input_string[i])) {
			calculation_stack.push(numbers[input_string[i] - 'A']);
		}
		else {
			double rhs = calculation_stack.top();
			calculation_stack.pop();
			double lhs = calculation_stack.top();
			calculation_stack.pop();

			switch (input_string[i]) {
			case '+':
				calculation_stack.push(lhs + rhs);
				break;
			case '-':
				calculation_stack.push(lhs - rhs);
				break;
			case '*':
				calculation_stack.push(lhs * rhs);
				break;
			case '/':
				calculation_stack.push(lhs / rhs);
				break;
			}
		}
	}

	return calculation_stack.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cin >> input_string;

	for (int i = 0;i < N;i++) {
		cin >> numbers[i];
	}

	cout << setprecision(2) << fixed << solution();
}