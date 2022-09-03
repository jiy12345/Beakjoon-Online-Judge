#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define HORIZONTAL 0
#define VERTICAL   1

int totalLength[2];
int numOfwhereToCut;
vector<int> lengths[2];
vector<int> whereToCut[2];

int solution() {
	int maxLengths[2];
	int prevCoord[2] = { 0, };

	for (int i = 0; i < numOfwhereToCut; i++) {
		bool HORorVER;
		int coord;
		cin >> HORorVER >> coord;

		whereToCut[HORorVER].push_back(coord);
	}

	for (int i = 0; i < 2; i++) {
		sort(whereToCut[i].begin(), whereToCut[i].end());
		for (int curCoord : whereToCut[i]) {
			lengths[i].push_back(curCoord - prevCoord[i]);
			prevCoord[i] = curCoord;
		}
		lengths[i].push_back(totalLength[i] - prevCoord[i]);
		maxLengths[i] = *max_element(lengths[i].begin(), lengths[i].end());
	}

	return maxLengths[0] * maxLengths[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> totalLength[1] >> totalLength[0];
	cin >> numOfwhereToCut;

	cout << solution();
}