#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 전체 용액의 수

- 변수 제한 사항
 N: 2~100,000

 각 용액의 특성값: -1,000,000,000~1,000,000,000

- 문제 상황
각 용액의 특성값들이 주어질 때, 두 용액을 혼합하였을 때 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다.

출력해야 하는 두 용액은 특성값의 오름차순으로 출력한다.

2. 풀이 계획

 다음과 같이 3가지 상황이 있을 수 있다.

1. 0을 포함한 양수만 존재하는 경우
 => 가장 앞의 두 수를 출력하면 된다.

2. 0을 포함한 음수만 존재하는 경우
 => 가장 뒤의 두 수를 출력하면 된다.

3. 음수와 양수가 섞여있는 경우
 두개의 포인터를 사용하여 한 수는 음수중 가장 큰 수를, 한 수는 양수중 가장 작은 수를 가리키게 하고, 
 두 수의 합이 양수일 떄는 음수가 작아지는 쪽으로
 두 수의 합이 음수일 때는 양수가 커지는 쪽으로 이동하도록 하여 모든 수를 탐색한 후 두 용액을 혼합하였을 때의 특성값이 가장 작았을 때의 두 용액의 특성값을 출력한다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;


vector<int> solutions; // 용액들


void solution() {
	sort(solutions.begin(), solutions.end());

    int answer[2] = {0, 0};

    int leftPtr = 0; 
    int rightPtr = N - 1;
    int min = 2000000000;
    while (leftPtr < rightPtr) {
        int sum = solutions[leftPtr] + solutions[rightPtr];

        // 갱신이 필요한 경우
        if (min > abs(sum)) {
            min = abs(sum);
            answer[0] = solutions[leftPtr];
            answer[1] = solutions[rightPtr];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            leftPtr++;
        else
            rightPtr--;
    }

    cout << answer[0] << " " << answer[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		solutions.push_back(temp);
	}

	solution();
}