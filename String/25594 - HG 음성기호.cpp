#include<iostream>
#include<unordered_map>
using namespace std;

string S;
unordered_map<char, string> HG = {
	{ 'a', "aespa" },
	{ 'b', "baekjoon" },
	{ 'c', "cau" },
	{ 'd', "debug" },
	{ 'e', "edge" },
	{ 'f', "firefox" },
	{ 'g', "golang" },
	{ 'h', "haegang" },
	{ 'i', "iu" },
	{ 'j', "java" },
	{ 'k', "kotlin" },
	{ 'l', "lol" },
	{ 'm', "mips" },
	{ 'n', "null" },
	{ 'o', "os" },
	{ 'p', "python" },
	{ 'q', "query" },
	{ 'r', "roka" },
	{ 's', "solvedac" },
	{ 't', "tod" },
	{ 'u', "unix" },
	{ 'v', "virus" },
	{ 'w', "whale" },
	{ 'x', "xcode" },
	{ 'y', "yahoo" },
	{ 'z', "zebra" }
};

void solution() {
	string answer = "";
	bool isHG = true;

	int curIndex = 0;
	while (true) {
		if (curIndex == S.length()) break;
		string compareStr = HG[S[curIndex]];

		if (compareStr != S.substr(curIndex, compareStr.size())) {
			isHG = false;
			break;
		}

		answer += S[curIndex];
		curIndex += compareStr.size();
	}

	if (isHG) {
		cout << "It's HG!\n";
		cout << answer;
	}
	else {
		cout << "ERROR!";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;
	solution();
}
