#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;



long long maxScore(const vector<vector<long long>>& vec, vector<vector<long long>>& DP, int n) {
  if (n == 0)
    return 0;
  DP[0][0] = vec[0][0];
  DP[1][0] = vec[1][0];
  if (n > 1) {
    DP[0][1] = vec[0][1] + DP[1][0];
    DP[1][1] = vec[1][1] + DP[0][0];
    for (int j = 2; j < n; j++) {
      for (int i = 0; i < 2; i++) {
        if (i == 0)
          DP[i][j] = vec[i][j] + max(DP[1][j - 1], max(DP[0][j - 2], DP[1][j - 2]));
        else if (i == 1)
          DP[i][j] = vec[i][j] + max(DP[0][j - 1], max(DP[0][j - 2], DP[1][j - 2]));
      }
    }
  }

  long long max1 = max(DP[0][n - 1], DP[1][n - 1]);
  if (n - 2 > 0) {
    long long max2 = max(DP[0][n - 2], DP[1][n - 2]);
    return max(max1, max2);
  }
  return max1;

}

int main() {
  int n;
  cin >> n;
  vector<vector<long long>> vec(2,vector<long long>(n));
  vector<vector<long long>> DP(2, vector<long long>(n,-1));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      cin >> vec[i][j];
  cout << maxScore( vec, DP, n);
  return 0;
}
