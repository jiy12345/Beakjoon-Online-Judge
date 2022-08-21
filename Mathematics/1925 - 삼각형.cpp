#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

//
// 각을 어떻게 체크해야 할까?
// 소수의 오차에 대한 언급이 없는 것을 보니
// => 피타고라스의 정리로 체크할 수 있다!
// 
// 
//

int x_1, y_1, x_2, y_2, x_3, y_3;

int distanceSquared(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

string solution() {
	string answer = "";

	if (abs(x_2 - x_3) * abs(y_1 - y_2) == abs(x_1 - x_2) * abs(y_2 - y_3)) 
		answer += "X";
	else {
		int numOfSame = 1;
		int sidesSquared[3];

		sidesSquared[0] = distanceSquared(x_1, y_1, x_2, y_2);
		sidesSquared[1] = distanceSquared(x_2, y_2, x_3, y_3);
		sidesSquared[2] = distanceSquared(x_1, y_1, x_3, y_3);

		sort(sidesSquared, sidesSquared + 3);

		if (sidesSquared[0] == sidesSquared[1]) numOfSame++;
		if (sidesSquared[1] == sidesSquared[2]) numOfSame++;

		if (numOfSame == 3) 
			answer += "Jung";
		else {
			if (sidesSquared[0] + sidesSquared[1] < sidesSquared[2])
				answer += "Dunkak";
			else if (sidesSquared[0] + sidesSquared[1] == sidesSquared[2])
				answer += "Jikkak";
			else
				answer += "Yeahkak";

			answer += (numOfSame == 2) ? "2" : "";
		}
		answer += "Triangle";
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;

	cout << solution();
}