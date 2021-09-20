#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
using namespace std;

void solution() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string temp = "";

	map<string, int> trees;

	// 같은 이름의 키에 해당하는 값 하나 증가시키기
	while(getline(cin, temp)) {
		trees[temp]++;
	}

	float sum = 0;
	map<string, int>::iterator it;
	// 합 구하기
	for (it = trees.begin(); it != trees.end(); ++it) {
		sum+=it->second;
	}

	// 소수점 밑 4자리로 고정 
	cout << fixed;
	cout.precision(4);
	for (it = trees.begin(); it != trees.end(); ++it) {
		cout << it->first << " " << it->second / sum * 100 << "\n";
	}

}

int main() {

	solution();

	return 0;
}
