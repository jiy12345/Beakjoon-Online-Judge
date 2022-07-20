#include<iostream>
#include<string>
using namespace std;

bool isUsed[10];

string A;
int B, C;

void solution(string str_C) {
	if (str_C.size() == A.size()) {
		int cur_C = stoi(str_C);
		if (cur_C < B) C = max(C, cur_C);
		return;
	}

	for (int i = 0; i < A.size(); i++) {
		if (isUsed[i] == false && !(str_C.size() == 0 && A[i] == '0')) {
			isUsed[i] = true;
			solution(str_C + A[i]);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	C = -1;

	solution("");

	cout << C;
}
