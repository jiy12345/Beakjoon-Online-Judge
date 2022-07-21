#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
N: 마지막 수
k: 몇인지 알아야 하는 자리수

- 변수 제한 사항
1 ≤ N ≤ 100,000,000  
1 ≤ k ≤ 1,000,000,000


- 문제 상황
 N과 k가 주어졌을 때, 만들어진 숫자에서 k번째 자리 수를 출력한다.
 수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력한다.

2. 풀이 계획

일단, 어떤 범위인지 확정해야 한다.
따라서 값을 올리며 계산해보자

각 자리수에 대해 가지는 숫자는 다음과 같다.

(10^N - 10^(N-1)) * N

따라서 위의 수를 k에서 빼가며


3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

int N, k;

int solution() {
    int answer = 0;
    int digit = 1;
    int tenSquared = 1;

    while (k > digit * tenSquared * 9) {
        k -= (digit * tenSquared * 9);
        answer = answer + tenSquared * 9;
        digit++;
        tenSquared *= 10;
    }


    // 몇번째 숫자인지 구하기
    answer = (answer + 1) + (k - 1) / digit;

    //cout << answer << endl;

    return (answer > N) ? -1 : (to_string(answer)[(k - 1) % digit] - '0');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;

	cout << solution();
}