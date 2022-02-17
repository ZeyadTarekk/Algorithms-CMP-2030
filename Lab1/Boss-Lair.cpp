#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;


void bossLair(const vector<vector<vector<int>>>& v, int i, int j, int k, int n, int cost, int& minCost) {
    if (i == n - 1 && j == n - 1 && k == n - 1) {
        if (cost +  v[i][j][k] < minCost)
            minCost = cost+v[i][j][k];
        return;
    }
    if (i >= n || j >= n || k >= n)
        return;
    bossLair(v, i + 1, j, k, n, cost + v[i][j][k], minCost);
    bossLair(v, i, j + 1, k, n, cost + v[i][j][k], minCost);
    bossLair(v, i, j, k + 1, n, cost + v[i][j][k], minCost);


}


int main() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> v1(n, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cin >> v1[i][j][k];

    int minCost = INT_MAX;
    bossLair(v1, 0, 0, 0, n, 0, minCost);
    cout << minCost;
     //for(int i=0;i<n;i++){
     //  cout<<"Floor: "<<i<<" ";
     //  for(int j=0;j<n;j++){
     //    cout<<"Row: "<<j<<" ";
     //    for(int k=0;k<n;k++){
     //      cout<<v1[i][j][k]<<" ";
     //    }
     //    cout<<endl;
     //  }
     //  cout<<endl;
     //}


}