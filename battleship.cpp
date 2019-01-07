// https://open.kattis.com/problems/battleship

#include <bits/stdc++.h>
using namespace std;
#define MAX 32
#define MAXCMD 2010
typedef pair<int, int> ii;

class DeploymentMap {
   public:
	int w, h;
	char grid[MAX][MAX];
	int ships;
	DeploymentMap(char _grid[MAX][MAX], int _w, int _h) {
		w = _w;
		h = _h;
		ships = 0;
		for (int i = 0; i < _h; i++) {
			for (int j = 0; j < _w; j++) {
				grid[i][j] = _grid[i][j];
				if (grid[i][j] == '#') {
					ships++;
				}
			}
		}
	}
	bool shoot(int x, int y) {
		if (grid[y][x] == '#') {
			grid[y][x] = '_';
			ships--;
			return true;
		}
		return false;
	}
	bool isAllShipsDestroyed() {
		if (ships == 0) return true;
		return false;
	}
};

int findWinner(DeploymentMap playerOne, DeploymentMap playerTwo, ii cmd[MAXCMD], int n) {
	int gameEnd = 0;
	int playerOneTurn = 0;
	int playerTwoTurn = 0;
	for (int i = 0; i < n; i++) {
		if (playerOneTurn == playerTwoTurn) {
			bool hit = playerTwo.shoot(cmd[i].first, cmd[i].second);
			if (hit && !playerTwo.isAllShipsDestroyed())
				continue;

			else {
				playerOneTurn++;
				if (playerTwo.isAllShipsDestroyed()) gameEnd = 1;
			}
		} else {
			bool hit = playerOne.shoot(cmd[i].first, cmd[i].second);
			if (hit && !playerOne.isAllShipsDestroyed())
				continue;

			else {
				// cout << "here22" << endl;
				playerTwoTurn++;
				if (playerOne.isAllShipsDestroyed()) {
					if (gameEnd == 1)
						gameEnd = 0;
					else
						gameEnd = 2;
					break; // Game ends, ignore the command
				}
			}
		}
	}
	// 0 is incomplete action
	// 1 is player 1 wins
	// 2 is player 2 wins
	return gameEnd;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int w, h, n;
		cin >> w >> h >> n;
		char grid[MAX][MAX];
		memset(grid, 0, sizeof(grid));
		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
			}
		}
		DeploymentMap playerOne(grid, w, h);

		memset(grid, 0, sizeof(grid));
		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
			}
		}
		DeploymentMap playerTwo(grid, w, h);

		ii command[MAXCMD];
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			command[i] = ii(a, b);
		}

		int winner = findWinner(playerOne, playerTwo, command, n);

		if (winner == 1)
			cout << "player one wins" << endl;
		else if (winner == 2)
			cout << "player two wins" << endl;
		else
			cout << "draw" << endl;
	}
	return 0;
}
