#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generateStrings(vector<string> arrayChars, int n ,string s , vector<string> &generatedStrings  ){
      if(s.size() == n) {
    generatedStrings.push_back(s);
    // cout<<s<<endl;
    s="";
    return;
  }
for(int i = 0 ; i< 5 ; i++) {

  generateStrings(arrayChars,n, s +arrayChars[i], generatedStrings );
}
}


int main() {
  vector<string> ArrayCharacters = {"A","B","C","D","E"};
  // for(int i = 0 ; i < ArrayCharacters.size();i++) {
  //   cout<<ArrayCharacters[i]<<" ";
  // }
  vector<string> generated;
  int n , m , k;
  cin>>m>>n>>k;
  vector<string> toMatch(m);
  for(int i = 0 ; i < m ; i++)
    cin>>toMatch[i];

  // for(int i = 0 ; i < m ; i++)
  //   cout<<toMatch[i];

    int no=0;
    int no2=0;
  generateStrings (ArrayCharacters, n , "" ,generated);
  // cout<<"Length"<<generated.size()<<endl;
  for(int i = 0 ; i < generated.size();i++){
        for(int j = 0 ; j < m; j++) {
      if((generated[i].find(toMatch[j]))!=string::npos)
      no2++;
    }
    if(no2>=k)
      no++;
    no2=0;
  }
  cout<<no;
  return 0;
}