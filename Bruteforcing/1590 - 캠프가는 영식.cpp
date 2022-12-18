#include<iostream>
#include<limits.h>
using namespace std;

int N, T;

int solution() {
	int departure_time = INT_MAX;
	
	for (int i = 0; i < N; i++) {
		int S, I, C;
		cin >> S >> I >> C;
		
		if (T <= S) {
			departure_time = min(departure_time, S - T);
			continue;
		}

		int time_from_bus_start_time = T - S;

		int quotient = time_from_bus_start_time / I;
		int remainder = time_from_bus_start_time % I;

		if (quotient >= C) {
			continue;
		}
		else if(quotient == C - 1) {
			if (remainder == 0) departure_time = 0;
		}
		else {
			if (remainder == 0) departure_time = 0;
			else				departure_time = min(departure_time, I - remainder);
		}
	}

	return (departure_time == INT_MAX) ? -1 : departure_time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T;
	cout << solution();
}