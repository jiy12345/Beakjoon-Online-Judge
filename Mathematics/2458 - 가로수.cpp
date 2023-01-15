#include<iostream>
#include<algorithm>
using namespace std;

int N;
int tree_loc[100000];
int tree_distance[100000];

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;

        a = b;
        b = r;
    }
    return a;
}

int solution() {
    sort(tree_loc, tree_loc + N);

	int num_to_plant = 0;

	for (int i = 0; i < N - 1; i++) {
		tree_distance[i] = tree_loc[i + 1] - tree_loc[i];
	}

	int cur_gcd = tree_distance[0];
	for (int i = 1; i < N - 1; i++) {
		cur_gcd = gcd(cur_gcd, tree_distance[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		num_to_plant += (tree_distance[i] / cur_gcd) - 1;
	}

	return num_to_plant;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tree_loc[i];
    }

    cout << solution();
}