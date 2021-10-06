#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

/*
1. 문제 분석

- 변수
N: 지도의 크기(정사각형이므로 가로와 세로의 크기 같음

지도에서 0: 집이 없는 곳
지도에서 1: 집이 있는 곳

- 변수 제한 사항
N: 5~25

- 문제 상황
 집이 상, 하, 좌, 우로 연결되어 있을 때를 같은 단지라고 본다.

이 때, 첫 줄에는 총 단지수를 출력하고, 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력한다!

2. 풀이 계획
 일단 25 * 25이고 선택할 수 있는 방향이 적어도 4가지이므로, DFS로 구현할 시 시간초과가 발생할 것 같다.

 따라서 BFS로 각각의 단지의 집 수를 세야 할것 같다.

 이미 수를 센 집은 더이상 의미가 없고 중복으로 방문되어서도 안되므로, 방문이 예정되어 BFS의 큐에 푸시되는 순간 더이상 집이 없다고 나타내면 될 듯 하다.


3. 계획 검증


*/
int N;
vector<string> map;

//         down,right,up,left => 꺾여있거나 할 수도 있으므로 위쪽과 왼쪽도 체크해야!
int di[4] = { 0, +1, 0, -1 };
int dj[4] = { +1, 0, -1, 0 };


int solution(int start_i, int start_j) {
	int num_of_houses = 0; 
	map[start_i][start_j] = '0'; // 현재노드 방문했다는 표시하기

	queue<vector<int>> bfs_queue; // 방문할 좌표를 가지고 있는 큐

	bfs_queue.push({ start_i, start_j}); // 첫 좌표 푸시

	while (!bfs_queue.empty()) {

		vector<int> cur_node = bfs_queue.front();
		bfs_queue.pop();
		num_of_houses++; // pop할때마다 집 하나씩 세기

		int cur_i = cur_node[0];
		int cur_j = cur_node[1];

		// 위, 아래, 왼쪽, 오른쪽 탐색
		// 갈 수 있는 방향인 1이 있는 방향으로만 탐색
		for (int i = 0; i < 4; i++) {
			if (map[cur_i + di[i]][cur_j + dj[i]] == '1') {
				map[cur_i + di[i]][cur_j + dj[i]] = '0'; // 중복 방문 방지를 위해 미리 방문 표시하기
				bfs_queue.push({ cur_i + di[i], cur_j + dj[i]});
			}
		}
	}
	return num_of_houses;
}

int main() {

	cin >> N;

	string map_row; // 미로의 각 한 행을 입력받기 위한 변수
	vector<int> num_of_houses_list;

	string wall = ""; // 위와 아래 벽 만들기
	for (int i = 0; i < N + 2; i++) {
		wall += "0";
	}

	map.push_back(wall); // 미로의 위 벽 표시

	for (int i = 0; i < N; i++) {
		cin >> map_row;
		map.push_back("0" + map_row + "0"); // 왼쪽과 오른쪽 벽을 붙여서 입력
	}

	map.push_back(wall); // 미로의 아래쪽 벽 표시

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1') {
				num_of_houses_list.push_back(solution(i, j));
			}
		}
	}

	cout << num_of_houses_list.size() << endl;

	sort(num_of_houses_list.begin(), num_of_houses_list.end());

	for (int i = 0; i < num_of_houses_list.size(); i++) {
		cout << num_of_houses_list[i] << endl;;
	}
	
	return 0;
}