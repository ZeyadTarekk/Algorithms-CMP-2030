#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void generateSigns(string s,vector<string>& v1 ) {
  if(s.size()==4) {
    v1.push_back(s);
    // cout<<s<<endl;
    return;
  }
  generateSigns(s+'+',v1);
  generateSigns(s+'-',v1);
  generateSigns(s+'*',v1);
}



int main() {
  vector<string> v1;
  generateSigns("", v1);
  // cout<<v1.size();
  vector<int> arr(5);
  for(int i = 0 ;i <5 ; i++) 
    cin>>arr[i];
  bool status = false;
  int sum;

  sort(arr.begin(),arr.end());

  do {
    sum = arr[0];
    for(int i=0;i<v1.size();i++) {
      for(int j = 0; j<4;j++) {
        if((int)v1[i][j]==(int)'+')
          sum+=arr[j+1];
        else if((int)v1[i][j]==(int)'*')
          sum*=arr[j+1];
        else if((int)v1[i][j]==(int)'-')
          sum-= arr[j+1];
      }
      if(sum == 27){
        status = true;
        break;
      }
      sum = arr[0];
    }
  }
  while (next_permutation(arr.begin(),arr.end()));
  if(status)
    cout<<"Possible";
  else
    cout<<"Impossible";

  // cout<<endl<<(int)'+';
  
}