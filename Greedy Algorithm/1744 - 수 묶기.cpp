#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

 - 변수
N: 수열의 길이

 - 변수, 값에 대한 제한
N은 1~10,000사이의 수이다 => O(NlogN)정도의 복잡도면 여유있게 해결할 수 있어보인다.
수열이 가지고 있는 수는 -10,000~10,000 사이의 정수이다.
정답은 2^31보다 작다 => int형으로 표현이 가능하다.

 - 문제 상황
수열이 주어질 때, 수열의 각 수를 두개씩 단 한번만 묶거나, 묶지 않아 합이 최대가 되개 하였을 때의 합을 출력한다.

2. 풀이 계획
시간에 대한 여유가 있으므로, 입력받은 수열을 일단 정렬 후 진행하는 것이 가능해보인다.

따라서 입력받은 값을 정렬하고, 양수끼리의 곱은 항상 크거나같은 방향의 답이 나오고, 음수끼리의 곱 또한 원래의 값들보다 더 큰 값이 답으로 나오므로, 정렬 후 음수는 작은 수부터 곱하고, 양수는 큰 수부터 곱하면 최대값이 나올것이다는 예상을 할 수 있다.

 => 그렇다면 문제가 되는것은 0근처에서의 일들이다.
  - 0이 있다면 음수쪽으로 붙어 음수중 최대값과 묶이는 것이 전체의 합이 최대값이 되는방향으로의 움직임이다. 
  - 음수쪽에 묶일 수 없다면 양수와는 묶이지 않고 0혼자 남아서 더해지는 것이 전체의 합이 최대값이 되는방향으로의 움직임이다.

따라서 0이하의 수는 최소값부터 두 수씩 묶어서 계산하고, 1이상의 수는 최대값부터 두 수 씩 묶어서 계산하면 된다.


따라서 자세한 과정은 다음과 같다.

1. 수열의 수를 배열에 저장한다.
2. 배열을 정렬한다.
3. 배열을 탐색하며 0이하의 최대값을 가진 위치의 인덱스를 구한다.
4. 구한 인덱스까지는 최소값부터 2개씩을 묶어 전체 합에 더하며, 구한 인덱스 이후는 최대값부터 2개씩 묶어 전체 합에 더한다.


3. 계획 검증
 이번 풀이 계획은 음수부(0을 포함한)와 양수부에서 각각 그리디 알고리즘이 적용되었다고 보면된다. 따라서 각각을 증명하면,
*/

int get_max_num(vector<int> num_sequence, int N) {
	
	// 배열을 오름차순으로 정렬한다.
	sort(num_sequence.begin(), num_sequence.end());

	int max_num = 0; // 합한 최대값을 저장할 변수 
	int index = 0;
	
	vector<int> minus_sequence;
	vector<int> plus_sequence;

	int center_index = -1; // 1이상의 최소값이 저장된 위치를 보여주는 변수

	// 음수 -> 양수인 위치 찾기
	while (true) {
		if (index == N || num_sequence[index] > 0) {
			// 음수부(0포함)와 양수부로 나누어주기
			minus_sequence = vector<int>(num_sequence.begin(), num_sequence.begin() + index);
			plus_sequence = vector<int>(num_sequence.begin()+index, num_sequence.end());
			break;
		}
		index++;
	}

	// 음수 수열 더하기
	for (int i = 0; i < minus_sequence.size(); i+=2) {
		if (i + 1 == minus_sequence.size()) { // 끝에 하나만 남은경우에 하나만 더하기
			max_num += minus_sequence[i];
		}
		else { // 나머지 경우에는 두개씩 묶기
			max_num += (minus_sequence[i] * minus_sequence[i + 1]);
		}
	}


	// 양수 수열 더하기
	for (int i = plus_sequence.size() - 1; i >= 0; i -= 2) {
		if (i - 1 == -1) { // 끝에 하나만 남은경우에 하나만 더하기
			max_num += plus_sequence[i];
		}
		else { // 나머지 경우에는 두개씩 묶기
			if (plus_sequence[i - 1] == 1) { // 끝 수가 1일 경우에는 곱하는 것보다는 더하는게 더 크다!
				max_num += (plus_sequence[i] + plus_sequence[i - 1]);
			}
			else {
				max_num += (plus_sequence[i] * plus_sequence[i - 1]);
			}
		}
	}

	return max_num;
}

int main() {

	int N; // 수열의 크기

	cin >> N;

	// 수열의 크기에 맞게 배열 동적할당
	vector<int> num_sequence;

	// 수열의 각각의 값 입력받기
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num_sequence.push_back(temp);
	}

	cout << get_max_num(num_sequence, N);

	return 0;
}