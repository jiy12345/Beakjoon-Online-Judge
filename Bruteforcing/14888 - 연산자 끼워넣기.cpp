#include<iostream>
#include<vector>
using namespace std;

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DEVIDE 3

#define INT_MIN -2147483648
#define INT_MAX 2147483647

void *solution(int N, vector<int> num, int *num_operator, int *answer, int calculated_value, int num_used_operator) {
	// 기저 사례: 모든 연산자를 다 뽑았을 경우
	if (num_used_operator == N - 1) {
    		// 현재 연산한 값이 최대값보다 크면 최대값 
		if (answer[0] < calculated_value) {
			answer[0] = calculated_value;
		}
    		// 현재 연산한 값이 최소값보다 작으면 최소값 갱신
		if (answer[1] > calculated_value) {
			answer[1] = calculated_value;
		}
	}

	for (int i = 0;i < 4;i++) {
		if (num_operator[i] != 0) {
  		  	// 연산자 하나 사용
			num_operator[i]--;
			switch(i) {
      			// 각 연산을 진행한 값 넘겨주기
			case PLUS:
				solution(N, num, num_operator, answer, calculated_value + num[num_used_operator + 1], num_used_operator + 1);
				break;			
			case MINUS:
				solution(N, num, num_operator, answer, calculated_value - num[num_used_operator + 1], num_used_operator + 1);
				break;			
			case MULTIPLY:
				solution(N, num, num_operator, answer, calculated_value * num[num_used_operator + 1], num_used_operator + 1);
				break;
			case DEVIDE:
				solution(N, num, num_operator, answer, calculated_value / num[num_used_operator + 1], num_used_operator + 1);
				break;
			}		
      			// 현 단계에서는 사용하지 않은 상태 유지해주기
			num_operator[i]++;
		}
	}
	return answer;
}

int main() {

	int N;
	vector<int> num;
	int num_operator[4];

	cin >> N;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 0;i < 4;i++) {
		cin >> num_operator[i];
	}

	int answer[2] = { INT_MIN, INT_MAX }; // answer[0]:최소값, answer[1]:최대값

	solution(N, num, num_operator, answer, num[0], 0);

	cout << answer[0] << endl;
	cout << answer[1];
	
}
