#include<iostream>
using namespace std;

int N;

int solution() {
	int answer = 0;

	for (int i = 1; i * i <= N; i++)
		answer++;
	
	return answer;
}

int main() {
	cin >> N;

	cout << solution();
}