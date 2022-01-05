#include<iostream>
#include<vector>
using namespace std;

long long obstacle(const vector<vector<long long>>& vec,int i,int j,int r,int c,vector<vector<long long>>& DP){
    if( i>=r ||j>=c ||vec[i][j]==-1)
        return 0;
    if(i==r-1&&j==c-1)
        return 1;
    if(DP[i][j]!=-2)
        return DP[i][j];

    DP[i][j]= obstacle(vec,i+1,j,r,c,DP)+obstacle(vec,i,j+1,r,c,DP);
    return DP[i][j];

}

int main(){
    int r,c;
    cin>>r>>c;

    vector<vector<long long>> vec(r,vector<long long>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>vec[i][j];


    vector<vector<long long>> DP(r,vector<long long>(c,-2));
    cout<<obstacle(vec,0,0,r,c,DP);

    return 0;
}