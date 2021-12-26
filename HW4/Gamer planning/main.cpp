#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<long long,long long>a, pair<long long,long long>b) {
  return b.first < a.first;
}


int main() {
  int n;
  cin>>n;
  vector<pair<long long,long long>> vec(n); //first: Penalty , second: deadline
  for(int i=0;i<n;i++)
    cin>>vec[i].second;
  for(int i=0;i<n;i++)
    cin>>vec[i].first;
  sort(vec.begin(),vec.end(),cmp);
//  for(int i=0;i<n;i++)
//    cout<<vec[i].first<<" ";
//  cout<<endl;
//  for(int i=0;i<n;i++)
//    cout<<vec[i].second<<" ";
long long sum=0;
vector<long long> timeTable(n,-1);
for(int i =0; i<vec.size();i++){
    int j=vec[i].second-1;
    while (timeTable[j]!=-1 && j>0)
      j--;
    if(j==0&&timeTable[j]!=-1)
      sum+=vec[i].first;
    else{
      if(timeTable[j]==-1)
        timeTable[j]=vec[i].first;
    }
}
cout<<sum;


  return 0;
}
