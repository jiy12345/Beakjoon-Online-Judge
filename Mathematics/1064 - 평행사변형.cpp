#include<iostream>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

double x_A, y_A, x_B, y_B, x_C, y_C;

void input() {
	cin >> x_A >> y_A >> x_B >> y_B >> x_C >> y_C;
}

double solution() {
	double deltaX_AB = fabs(x_A - x_B);
	double deltaY_AB = fabs(y_A - y_B);
	double deltaX_AC = fabs(x_A - x_C);
	double deltaY_AC = fabs(y_A - y_C);

	if (deltaX_AC * deltaY_AB == deltaX_AB * deltaY_AC) return -1;

	double lineAB = sqrt((x_A - x_B) * (x_A - x_B) + (y_A - y_B) * (y_A - y_B));
	double lineAC = sqrt((x_A - x_C) * (x_A - x_C) + (y_A - y_C) * (y_A - y_C));
	double lineBC = sqrt((x_B - x_C) * (x_B - x_C) + (y_B - y_C) * (y_B - y_C));

	pair<double, double> minMax = minmax({ (lineAB * 2 + lineAC * 2), (lineAB * 2 + lineBC * 2), (lineBC * 2 + lineAC * 2) });

	return minMax.second - minMax.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	
	cout << setprecision(15) << solution();

	return 0;
}
