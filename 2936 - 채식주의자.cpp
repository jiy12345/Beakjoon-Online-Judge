#include<iostream>
#include<iomanip>
using namespace std;

int x, y;

void solution() {
    float base = 250.0f * 250.0f / 2;
    cout << setprecision(2) << fixed;
    if (x + y == 0) {
        cout << 125.0f << " " << 125.0f;
    }
    else if (x > 0 && y > 0) {
        if (x > y) cout << "0.00 " << 250.0f - base / max(x, y);
        else       cout << 250.0f - base / max(x, y) << " 0.00";
    }
    else if (x < 125 && y == 0) {
        float tmp = 250.0f - base / (250.0f - x);
        cout << tmp << " " << 250.0f - tmp;
    }
    else if (x == 0 && y < 125) {
        float tmp = 250.0f - base / (250.0f - y);
        cout << 250.0f - tmp << " " << tmp;
    }
    else if (y == 0) {
        cout << "0.00 " << base / x;
    }
    else {
        cout << base / y << " 0.00";
    }

}

int main() {
	cin >> x >> y;

    solution();

	return 0;
}