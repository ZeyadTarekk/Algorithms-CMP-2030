#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int LIS(const vector<int> &no) {
  vector<pair<int, int>> dp(no.size(), make_pair(1, -1));
  for (int i = 0; i < no.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (no[i] > no[j] && dp[j] >= dp[i]) {
        dp[i].first = dp[j].first + 1;
        dp[i].second = j;
      }
    }
  }
  int max = dp[0].first;
  int maxIndex = 0;
  for (int i = 1; i < dp.size(); i++)
    if (dp[i].first > max) {
      max = dp[i].first;
      maxIndex = i;
    }

  for (int i = 0; i < max; i++) {
    cout << no[maxIndex] << " ";
    maxIndex = dp[maxIndex].second;
  }
  cout << endl;
  return max;
}


int main() {
//    vector<int> vec = { 12,24,9,35,21,50,41,62,82 };

  vector<int> vec = {11, 2, 3, 4, 5, 6, 7, 1, 9, 1, 1, 1, 10};
  cout << LIS(vec);

}
