#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
  int n, m;
  string map[1500];
  vector<pair<int, int> > swan;
  queue<pair<int, int> > water;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> map[i];

    for (int j = 0; j < m; j++) {
      if (map[i][j] == 'L') swan.push_back({i, j});
      if (map[i][j] == '.' || map[i][j] == 'L') water.push({i, j});
    }
  }

  queue<pair<int, int> > q;
  q.push(swan[0]);

  bool visited[1500][1500] = {false, };
  visited[swan[0].first][swan[0].second] = true;

  int day = 0;
  while (1) {
    queue<pair<int, int> > next;

    bool flag = false;
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      if(y == swan[1].first && x == swan[1].second) {
        flag = true;
        break;
      }
      
      for (int i = 0; i < 4; i ++) {
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;

        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || visited[nextY][nextX]) continue;
        visited[nextY][nextX] = true;

        if (map[nextY][nextX] == 'X') {
          next.push({nextY, nextX});
          continue;
        }

        q.push({nextY, nextX});
      }
    }

    if (flag) break;

    q = next;

    int waterSize = water.size();
      
    while (waterSize--) {
      int y = water.front().first;
      int x = water.front().second;
      water.pop();

      for (int i = 0; i < 4; i++) {
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

        if (map[nextY][nextX] == 'X') {
          map[nextY][nextX] = '.';
          water.push({nextY, nextX});
        }
      }
    }

    day++;
  }

  cout << day << endl;
  
  return 0;
}
