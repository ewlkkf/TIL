#include <iostream>
//#include <algorithm>

using namespace std;

int main() {
  int n, m;
  static int table[101][100001] = {0, };
  int item[101][2];

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> item[i][0] >> item[i][1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (item[i][0] <= j) {
        if ((item[i][1] + table[i-1][j - item[i][0]]) > table[i-1][j]) 
          table[i][j] = item[i][1] + table[i-1][j-item[i][0]];
        else
          table[i][j] = table[i-1][j];
      }
      else 
        table[i][j] = table[i-1][j];
    }
  }
  
  cout << table[n][m] << endl;

  return 0;
}
