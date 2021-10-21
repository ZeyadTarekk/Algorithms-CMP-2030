#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generateStrings(vector<string> arrayChars,int k,int n ,string s , vector<string> toMatch , int & no){
  if(s.size() == n) {
    int no2 = 0;
  for(int i = 0; i<toMatch.size() ; i++) {
    if(s.find(toMatch[i])!=string::npos) {
      no2++;
    }
  }
  if(no2>=k) no++;
  s="";
  return;
}
for(int i = 0 ; i < 5 ; i++) {
  generateStrings(arrayChars,k,n, s +arrayChars[i], toMatch,no );
}
}


int main() {
  vector<string> ArrayCharacters = {"A","B","C","D","E"};
  int n , m , k;
  cin>>m>>n>>k;
  vector<string> toMatch(m);
  for(int i = 0 ; i < m ; i++)
    cin>>toMatch[i];
  int no=0;
  generateStrings (ArrayCharacters,k, n , "" ,toMatch ,no);
  cout<<no;
  return 0;
}