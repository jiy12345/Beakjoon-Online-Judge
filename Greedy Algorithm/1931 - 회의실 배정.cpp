#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석


 - 변수
 N: 열리는 총 회의의 개수

 - 변수, 값에 대한 제한
- 회의는 한번 시작하면 중간에 중단될 수 없다.
- 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
- 각 회의는 시작시간과 끝나는 시간이 같을 수도 있다.
- 시작시간과 끝나는 시간은 (2^31)-1보다 작거나 같은 자연수 또는 0이다. => int형으로 나타낼 수 있다.
- 1 ≤ N ≤ 100,000

 - 문제 상황
회의의 개수와 각 회의의 시작시간과 끝나는 시간이 주어질 때, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾는 문제

2. 풀이 계획
 가장 먼저 떠올릴 수 있는 방법은 회의 시간이 가장 짧은 회의부터 선택하여 시간을 채워 넣는 것이다. 그러나 이러한 방법은 회의 시간이 어떻게 겹쳐져있느냐에 따라 매우 비효율적으로 스케줄이 짜질 수도 있다.
ex)

그 다음 떠올릴만한 것은 가장 먼저 종료되는 회의부터 선택하는 것이다. 이렇게 선택하면, 확실히 앞 부터 차근차근 채워나갈 수 있어 보인다.

따라서 전체 과정을 자세히 표현하면 다음과 같다.​

1. 들어온 값들을 2차원벡터에 받는다.
2. 현재 남은 회의 시간중 종료가 가장 빠른 시간을 선택한다.(총 회의의 개수에 1을 더한다.)
3. 선택된 회의 시간의 종료 시간보다 빠른 시작시간을 가진 회의들은 더이상 선택할 수 없으므로 벡터에서 삭제한다.
4. 더 이상 남은 값 회의 시간이 없을 때까지 2~3을 반복한다. 

3. 계획 검증
위의 풀이 계획은 그리디 알고리즘을 선택하였으므로, 이 문제에 대한 그리디 알고리즘의 정당성만 증명된다면 계획이 검증되는 것으로 볼 수 있다.
 1) 탐욕적 선택속성 증명: "가장 종료시간이 빠른 회의(Smin)을 포함하는 최적해가 반드시 존재한다."는 명제를 증명해야 한다.
1. 일단, S의 최적해 중 Smin을 포함하지 않는 최적해가 있음을 가정한다.
2. Smin을 포함하지 않는 최적해에서 가장 먼저 개최되는 회의(최적해에서는 겹치지 않는 회의들만 모아놨으므로 가장 먼저 종료되는 회의이기도 하다.)를 지우고 Smin을 추가하여 새로운 회의 목록을 만든다.
3. Smin은 S에서 가장 먼저 종료되는 회의이므로, 지워진 원래의 최적해에서 가장 먼저 개최되는 회의보다도 빨리 종료되며, 따라서 Smin은 최적해의 다른 회의들과 겹치지 않는다.
4. 따라서 Smin을 포함한 새로운 회의 목록 또한 최적해 중 하나이다.
 => Smin을 선택하지 않은 최적해는 모두 Smin을 선택한 최적해로 대체될 수 있으므로, 가장 일찍 끝나는 회의를 선택하여 최적해를 얻는 것이 불가능해지는 경우가 없음을 보여준다.

 2) 최적 부분구조
 첫번째 회의를 잘 선택하고 남은 회의를 모두 걸러냈다면, 남은 회의중 회의들을 선택하는 부분 문제를 얻을 수 있는데, 이 때 또한 같은 기준을 적용하여 가장 많은 회의를 넣을 수 있도록 하는 것이 좋으므로 최적 부분 구조는 자명하게 성립한다.

*/

bool compare(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int conference_scheduling(int N, vector<vector<int>>conferences) {

	sort(conferences.begin(), conferences.end(), compare);
	
	int max_num = 0;
	int current_end_time = 0; // 현재 선택된 회의의 종료시간

	for (int i = 0; i < conferences.size(); i++) {
		int begin_time = conferences[i][0];
		int end_time = conferences[i][1];

		if (current_end_time <= begin_time) {
			current_end_time = end_time;
			max_num++;
		}
	}

	//while(!conferences.empty()){
	//	// 정렬이 되어있으므로 가장 첫 원소가 선택할 수 있는 회의중 종료시간이 가장 빠른 회의!
	//	int current_end_time = conferences[0][1];

	//	max_num++; // 회의하나가 선택되었으므로, 
	//	conferences.erase(conferences.begin());
	//	
	//	// 삭제하면 벡터의 사이즈가 바뀌는 것을 간과하고 일반적인 방법으로 시도하였다가 실패
	//	auto iter = begin(conferences);
	//	while(iter != end(conferences)) {
	//		// 남아있는 회의 중 시작시간이 현재 선택된 회의의 종료시간보다 빠른 회의들은 모두 삭제
	//		if ((*iter)[0] < current_end_time) {
	//			iter = conferences.erase(iter);
	//		}
	//		else {
	//			iter++;
	//		}
	//	}
	//}
	return max_num;
}

int main() {
	int N; // 열리는 총 회의의 개수

	cin >> N;

	// 원하는 크기대로 벡터 만들기
	vector<vector<int>> conferences(N, vector<int>(2, 0));

	for (int i = 0; i < N; ++i) {
		cin >> conferences[i][0] >> conferences[i][1];
	}

	int max_num = conference_scheduling(N, conferences);

	cout << max_num;

	return 0;
}