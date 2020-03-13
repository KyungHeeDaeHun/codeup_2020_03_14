#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> MAP;
vector<vector<int>> Log;
int num;
int MAP_X = 0;
int MAP_Y = 0;

int main() {
	cin >> num;
	Log.resize(num);

	for (int i = 0; i < num; i++) {
		Log[i].resize(3);
		cin >> Log[i][0] >> Log[i][1] >> Log[i][2];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 2; j++) {
			if (MAP_X < Log[i][j]) { MAP_X = Log[i][j]; }
		}
		if (MAP_Y < Log[i][2]) { MAP_Y = Log[i][2]; }
	}

	MAP.resize(MAP_Y + 1);
	for (int i = 0; i < MAP_Y + 1; i++) {
		MAP[i].resize(MAP_X + 1);
	}

	for (int i = 0; i < num; i++) {
		for (int p = Log[i][0]; p < Log[i][1] + 1; p++) {
			MAP[Log[i][2]][p] = 1;
		}
	}
	int Max = 0;
	for (int i = 1; i < MAP_X + 1; i++) {
		int num = 0;
		for (int j = 1; j < MAP_Y + 1; j++) {
			if (MAP[j][i] == 1) { num++; }
		}
		if (Max < num) { Max = num; }
	}
	cout << Max << endl;

}