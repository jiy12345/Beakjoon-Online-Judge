#include<iostream>
using namespace std;

int N;

bool foxSign[5][5] = {
	{ false, false, true, true, false	},
	{ false, false, false, false, false	},
	{ true, false, false, true, false	},
	{ true, false, true, false, false	},
	{ false, false, false, false, false	}
};

string solution() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int finger1, finger2;
		cin >> finger1 >> finger2;

		if (foxSign[finger1 - 1][finger2 - 1] == false)
			return "Woof-meow-tweet-squeek";
		else
			cnt++;
	}

	if(cnt!=3) 
		return "Woof-meow-tweet-squeek";

	return "Wa-pa-pa-pa-pa-pa-pow!";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();
}