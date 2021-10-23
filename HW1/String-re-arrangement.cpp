#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;


void function(string s, int index, string s2, int& moves,bool &value) {
    if (index == s.size() || s == s2) {
        if (s != s2)
            value = false;
        return;
    }
    // cout<<s<<endl;
    char n = s[0];
    s.erase(s.begin());
    moves++;
    function(s += n, index + 1, s2, moves,value);
}



int main() {
    // string name = "zeyad";
    // for(int i = 0 ; i < name.size(); i++) {
    //   name+=name[0];
    //   name.erase(name.begin());
    //   cout<<name<<endl;
    // }
    int n;
    cin >> n;
    vector<string> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    int minMoves = INT_MAX;
    int moves = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        moves = 0;
        for (int j = 0; j < n ; j++) {
            if (i == j)
                continue;
            function(v1[j], 0, v1[i], moves,flag);
        }
        if (moves < minMoves)
            minMoves = moves;

    }
    if (flag == false)
        cout << -1;
    else
        cout << minMoves;
    return 0;
}