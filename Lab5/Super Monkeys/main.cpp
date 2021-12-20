#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void superMonkey(const vector<int>& Buckets, const vector<int>& Monkeys) {
  int maxBucket = INT_MIN;
  int minMonkey = INT_MAX;

  for (int i = 0; i < Buckets.size(); i++)
    if (Buckets[i] > maxBucket)
      maxBucket = Buckets[i];
  vector<pair<int, int>>DP(maxBucket + 1);    //first = remaining second = bites
  minMonkey = Monkeys[0];

  if (minMonkey == 0) {
    int i = 1;
    while (i <= Monkeys.size() && minMonkey == 0) {
      minMonkey = Monkeys[i];
      i++;
    }
  }
  //cout << minMonkey << endl;
  for (int i = 0; i < minMonkey; i++) {
    DP[i].first = i;
    DP[i].second = 0;
  }
  for (int i = minMonkey; i < DP.size(); i++) {
    pair<int, int> dumm = make_pair(INT_MAX, INT_MAX);
    for (int j = 0; j < Monkeys.size(); j++) {
      if (Monkeys[j] != 0 && (i - Monkeys[j] >= 0)) {
        if (DP[i - Monkeys[j]].first < dumm.first || (DP[i - Monkeys[j]].first == dumm.first && DP[i - Monkeys[j]].second + 1 < dumm.second)) {
          dumm.first = DP[i - Monkeys[j]].first;
          dumm.second = DP[i - Monkeys[j]].second + 1;
        }
      }
      DP[i] = dumm;
    }

  }
  for (int i = 0; i < Buckets.size(); i++) {
    cout << DP[Buckets[i]].first << " " << DP[Buckets[i]].second << endl;
  }
}
int main() {
  int n;
  cin >> n;
  vector<int>vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  int m;
  cin >> m;
  vector<int>vec2(m);
  for (int i = 0; i < m; i++)
    cin >> vec2[i];
  sort(vec2.begin(), vec2.end());

  superMonkey(vec, vec2);
  //cout << dumm.first << " " << dumm.second;
  return 0;
}
