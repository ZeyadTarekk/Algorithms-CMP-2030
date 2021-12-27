#include <iostream>
using namespace std;

int main() {
  long long s, a, b;
  cin >> s >> a >> b;
  long long rems1, countA, countB;
  long long rems2, countA2, countB2;
  countB = s/b;
  countA = 0;
  rems1 = s % b;
  countA2 = countA ;
  while (true) {
    countA2 = countA2 + 1;
    rems2 = s - countA2 * a;

    countB2 = rems2 / b;
    rems2 = s - (countB2 * b + countA2 * a);
    if (rems2 < rems1) {
      if (rems2 < 0)
        break;
      rems1 = rems2;
      countA = countA2;
      countB = countB2;
      //cout << countA << " " << countB << endl;
    }
  }
  cout << countA << " " << countB <<" " << rems1 << endl;


  return 0;
}