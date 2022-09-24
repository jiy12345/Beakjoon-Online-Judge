#include<iostream>
#include<vector>
using namespace std;

int N, M, numOfPeople;
int Parent[51];
vector<int> knowTruth;
int party[50][51];

int findParent(int A) { 
	if (A == Parent[A]) 
		return A;
	return Parent[A] = findParent(Parent[A]); 
}

void Union(int A, int B) { 
	A = findParent(A); 
	B = findParent(B); 
	Parent[B] = A;
}

bool sameParent(int A, int B) { 
	A = findParent(A);
	B = findParent(B); 
	if (A == B) 
		return true; 
	return false; 
}

int solution() {
	int answer = 0;
	
	for (int i = 1; i < N; i++) Parent[i] = i;

	for (int i = 0; i < M; i++) {
		numOfPeople = party[i][0];
	
		int curParticipant = party[i][1];
		for (int j = 2; j <= numOfPeople; j++)
			Union(curParticipant, party[i][j]);
	}

	for (int i = 0; i < M; i++) {
		bool canGo = true;
		numOfPeople = party[i][0];
		int j;
		for (j = 1; j <= numOfPeople; j++) {
			int curParticipant = party[i][1];
			for (int k = 0; k < knowTruth.size(); k++) {
				if (sameParent(curParticipant, knowTruth[k])) {
					canGo = false;
					break;
				}
			}
			if (canGo == false)
				break;
		}

		if (canGo == true)
			answer++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> numOfPeople;

	knowTruth.resize(numOfPeople);
	for (int i = 0; i < numOfPeople; i++) {
		cin >> knowTruth[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> numOfPeople;
		party[i][0] = numOfPeople;
		for (int j = 1; j <= numOfPeople; j++)
			cin >> party[i][j];
	}

	cout << solution();
}