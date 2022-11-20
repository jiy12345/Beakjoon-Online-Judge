#include<iostream>
#include<algorithm>
using namespace std;

int Array[1000000];
int N;

void solution() {
	sort(Array, Array + N);

	for (int i = N - 1; i >= 0; i--)
		cout << Array[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Array[i];

	solution();
}