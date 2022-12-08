#include<iostream>
#include<map>
using namespace std;

int number_book_sold;
map<string, int> book_sales;

string solution() {
	for (int i = 0; i < number_book_sold; i++) {
		string book_name;
		cin >> book_name;
		book_sales[book_name]++;
	}

	string answer = "";
	int cur_max = 0;

	for (auto cur_pair : book_sales) {
		if (cur_max < cur_pair.second) {
			cur_max = cur_pair.second;
			answer = cur_pair.first;
		}
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> number_book_sold;
	cout << solution();
}