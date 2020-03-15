#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> MAP;
vector<vector<bool>> Visited;
int row;
int column;
vector<int> result;
int area = 0;

void DFS(int y, int x, bool first) {
	if (Visited[y][x]) { return; }

	Visited[y][x] = true;

	if (MAP[y][x] != 0) { return; }
	area++;
	if (first) { first = false;}

	//위쪽
	if(!(y-1 < 0)){ DFS(y - 1, x, first); }
	//아래쪽
	if(!(y+1>column - 1)){ DFS(y + 1, x, first); }
	//왼쬑
	if(!(x-1<0)){ DFS(y, x - 1, first); }
	//오른쪽
	if(!(x+1>row -1)){ DFS(y, x + 1, first); }

}

void InputBlock(vector<int> vec1, vector<int> vec2) {
	for (int i = vec1[0]; i < vec2[0]; i++) {
		for (int j = vec1[1]; j < vec2[1]; j++) {
			MAP[j][i] += 1;
		}
	}
}

int main() {
	cin >> column >> row;

	MAP.resize(column);
	Visited.resize(column);

	for (auto& elem : MAP) {
		elem.resize(row);
	}
	for (auto& elem : Visited) {
		elem.resize(row);
	}

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		vector<int> vec1(2);
		vector<int > vec2(2);
		cin >> vec1[0] >> vec1[1];
		cin >> vec2[0] >> vec2[1];
		InputBlock(vec1, vec2);
	}



	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			area = 0;
			DFS(i, j, true);
			if(area != 0){ result.push_back(area); }
			
		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (auto elem : result) {
		cout << elem << " ";
	}
	cout << endl;

}