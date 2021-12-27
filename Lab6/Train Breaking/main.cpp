#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

// Note: you won't need long long in this problem

int solve(vector<int>& L, int i, int j, vector<vector<int>>&memo){   ///*, add memo here */) {

    // TODO: check if you solved the problem before (memoization) (add this part after you implement the whole function)

    // TODO: step 2: add base case

    // TODO: step 1: write the optimal structure for the solution using subproblems to get the minimum total cost

    // TODO: save the minimum total cost in memo (add this part after you implement the whole function)

    // TODO: return the minimum total cost

    if (i + 1 == j)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int minimum = INT_MAX;
    int minimum2;
    int end = L[j];
    int beginn = L[i];
    for (int k = i+1; k < j; k++) {
        minimum2 = solve(L, i, k, memo) + solve(L, k, j, memo);
        if (minimum2  < minimum)
            minimum = minimum2 ;
    }
    memo[i][j] = (end - beginn) + minimum;
    return memo[i][j];

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(M);

    for (int i = 0; i < M; i++)
    {
        cin >> L[i];
    }



    // TODO: uncomment the following if they help you solve the problem
    L.insert(L.begin(), 0);
    L.push_back(N);

    vector<vector<int>>memo (L.size(), vector<int>(L.size(), -1));
    // TODO: declare DP storage and call it memo

    // This function call is for guidance and you can change it if you want
    cout << solve(L, 0, L.size() - 1, memo) << endl;

    return 0;
}