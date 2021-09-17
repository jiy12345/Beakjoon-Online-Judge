#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

/*
1. 문제 분석


- 변수 제한 사항
1 <= 문자열의 길이 <= 1,000,000
1 <= pd의 길이 <= 100,000   => 따라서 매번 뒤집는 것에는 무리가 있어보인다1
1 <= n <= 10,000

p의 길이의 합과 nd의 합은 700,000을 넘지 않음

 - 문제 상황
AC에서 R은 배열 숫자의 순서를 뒤집고, D는 첫번째 숫자를 버린다! 배열이 비어있는데 D를 사용하면 오류가 발생한다!

2. 풀이 계획
매번 뒤집으며 반복을 진행하면 상당히 오래 걸릴것이다!

따라서 is_reversed 변수를 선언하여 뒤집힌 상태인지 똑바로 된 상태인지 를 표시하고

수를 하나 버릴때는 뒤집힌 상태라면 앞에서 하나를 버리고, 뒤집히지 않은 상태라면 뒤에서 하나를 버린다!
 => 앞 뒤에서 모두 삭제가 이루어지므로 deque를 사용하는 것이 효율적일 듯 하다!
마지막에는 뒤집힌 상태라면 뒤집어서 출력한다!

1. 테스트 케이스 변수를 입력받는다.
2. 테스트 케이스 변수의 크기만큼 반복문을 돌리며, AC와 배열을 입력받는다.
3. 배열을 입력받을 때는  2n+1(대괄호와 쉼표를 포함하여) 개의 문자를 읽어 정수면 벡터에 저장하도록 한다.


다음과 같은 과정을 거치자


3. 계획 검증

*/


// KMP 구현
//// 실패함수 구현(접두사와 접미사 최대 일치 길이 비교)
//vector<int> makeTable(string pattern) {
//    int patternSize = pattern.size();
//
//    vector<int> table(patternSize, 0);
//
//    int j = 0;
//    for (int i = 1; i < patternSize; i++) {
//
//        // j 인덱스가 0이상인데, i번째와 j번째 문자가 일치하지 않는다면, 
//        while (j > 0 && pattern[i] != pattern[j]) {
//            j = table[j - 1]; // 한 칸 뒤로 백 
//        }
//
//        if (pattern[i] == pattern[j]) {
//            table[i] = ++j;
//        }
//    }
//
//    return table;
//}
//
//int KMP(string data, string pattern) {
//    int index = -1;
//    vector<int> table = makeTable(pattern);
//
//    int parentSize = data.size();
//    int patternSize = pattern.size();
//
//    int j = 0;
//    for (int i = 0; i < parentSize; i++) {
//        while (j > 0 && data[i] != pattern[j]) {
//            j = table[j - 1]; // 일치 하지 않았을 때, 이전 단계에 있던 값으로 이동 
//        }
//        if (data[i] == pattern[j]) {
//            if (j == patternSize - 1) {
//                index = (i - patternSize + 1);
//
//                data = data.substr(0, index) + data.substr(index + pattern.size());
//                i = ((index - patternSize)>0)? (index - patternSize) : -1;
//                j = ((table[j] - patternSize) > 0) ? (table[j] - patternSize) : 0;
//                parentSize = data.size();
//
//                //cout << "index: " << index << endl;
//                //cout << "parent size:" << parentSize << endl;
//                //cout << "i: " << i << endl;
//                //cout << endl;
//            }
//            else {
//                j++; // 단순히 매칭만 이루어졌기 때문에 j만 증가시켜 매칭 확인 
//            }
//        }
//        parentSize = data.size();
//    }
//
//    if (data.empty()) {
//        cout << "FRULA";
//    }
//    else {
//        cout << data;
//    }
//
//    return index;
//}

void solution(string data, string pattern) {
	string stack;

	for (int i = 0; i < data.size(); i++) {
		stack += data[i];

		if (stack.size() >= pattern.size()) {
			string temp = stack.substr(stack.size() - pattern.size());
			if(temp == pattern) {
				int cnt = 0;
				while (cnt < pattern.size()) {
					stack.pop_back();
					cnt++;
				}
			}
		}
	}
	if (stack.empty()) {
		cout << "FRULA";
	}
	else {
		cout << stack;
	}
}

int main() {
	string data, pattern; // ATM에 줄 서있는 사람의 수

	cin >> data;
    cin >> pattern;

	solution(data, pattern);

	return 0;
}
