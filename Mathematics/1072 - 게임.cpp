#include<iostream>
using namespace std;

long long X, Y;

int solution() {
    int Z = (Y * 100) / X;
	if (Z >= 99) {
		return -1;
	}

    int low = 0, high = 1000000000;
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        int tempZ = (100 * (Y + mid)) / (X + mid);

        if (Z >= tempZ) {
            result = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X >> Y;

	cout << solution();
}