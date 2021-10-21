#include<iostream>
#include<string>
using namespace std;
void generateString(int n , int h , string s) {

  int no=0;
  if(s.size()==n) {
    for(int i = 0 ; i < s.size(); i++) {
      if(s[i] == '1')
        no++;
    }
    if(no==h)
      cout<<s<<endl;
    no=0;
    return;
  }
  generateString(n,h,s+"0");
  generateString(n,h,s+"1");
}

int main() {
  int h,n;
  cin>>n>>h;
  generateString(n,h,"");
}