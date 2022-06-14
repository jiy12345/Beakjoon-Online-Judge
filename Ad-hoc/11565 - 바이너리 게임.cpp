#include<iostream>
using namespace std;

string a, b;

string solution() {
	int a_num = 0, b_num = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '1') a_num++;
	for (int j = 0; j < b.length(); j++)
		if (b[j] == '1') b_num++;
	
	if (a_num >= b_num)
		return "VICTORY";
	else if (a_num < b_num) {
		if (a_num % 2 == 1 && a_num + 1 == b_num)
			return "VICTORY";
		else
			return "DEFEAT";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << solution();

	return 0;
}