#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;
void maxPathBruteForce(int i,int j,const vector<vector<long long>>& vec, long long & max,long long cost,int n,int m){
    if(i==n-1&&j==m-1){
        if(cost+vec[i][j]>max)
            max=cost+vec[i][j];
    }
    else if(i<n && j<m){
        cost+=vec[i][j];
        maxPathBruteForce(i+1,j,vec,max,cost,n,m);
        maxPathBruteForce(i,j+1,vec,max,cost,n,m);
        maxPathBruteForce(i+1,j+1,vec,max,cost,n,m);
    }
}
long long maxPathDP(int i,int j,const vector<vector<long long>>& vec,vector<vector<pair<long long,bool>>> &vecDP,int n,int m){
    if(i>=n|| j>=m)
        return LONG_LONG_MIN;
    if(i==n-1&&j==m-1)
        return vec[i][j];
    if(vecDP[i][j].second)
        return vecDP[i][j].first;
    long long down = maxPathDP(i+1,j,vec,vecDP ,n,m);
    long long right = maxPathDP(i,j+1,vec,vecDP ,n,m);
    long long rightDown = maxPathDP(i+1,j+1,vec,vecDP ,n,m);
    vecDP[i][j].second=true;
    vecDP[i][j].first=max(down,max(right,rightDown))+vec[i][j];
    return vecDP[i][j].first;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> vec(n,vector<long long>(m));
    vector<vector<pair<long long,bool>>> vecDP(n,vector<pair<long long,bool>>(m, make_pair(0,false)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>vec[i][j];
    }
//    vecDP[n-1][m-1].first=vec[n-1][m-1];
//    vecDP[n-1][m-1].second=true;
//    long long max = LONG_LONG_MIN;
    long long max = maxPathDP(0,0,vec,vecDP,n,m);
//    maxPathBruteForce(0,0,vec,max,0,n,m);
    cout<<max;
    return 0;
}
