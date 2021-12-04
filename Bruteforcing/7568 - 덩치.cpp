#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 사람의 수
x, y: 각 사람의 키와 몸무게

- 변수 제한 사항
N: 2~50
x, y: 10~200

- 문제 상황
각 사람의 덩치 등수를 구하여 그 순서대로 출력하라

2. 풀이 계획y1
일단 먼저 입력을 받은 후, 몸무게를 기준값으로 잡아 정렬한 후, 

각 사람의 등수를 기록한 다음 다시 위치 기준으로 정렬하면 될 듯 하다!

3. 계획 검증
*/

vector<vector<int>> people;
int N;

// 몸무게 기준으로 정렬하기 위한 비교함수
bool compare1(vector<int>person1, vector<int>person2) {
	return person1[0] > person2[0];
}

// 순서 기준으로 다시 정리하기 위한 비교함수
bool compare2(vector<int>person1, vector<int>person2) {
	return person1[2] > person2[2];
}


void solution() {
	// 사전 순 정렬
	sort(people.begin(), people.end());

	// 첫 사람의 몸무게
	int cur_min = people[0][1];

	for (int i = 0;i < N;i++) {

		/*cout << people[i][0] << people[i][1] << people[i][2] << endl;*/
	}
}

int main() {
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x, y;
		cin >> x >> y;
		people.push_back({ x,y,i });
	}

	solution();
}