#include<iostream>
#include<string>
#include<vector>
using namespace std;

void arrangeSeats(const vector<string>& v1, vector<bool> &visited, int index, vector<string>& formed, int& count) {
    if (index == v1.size()) {
        for (int i = 0; i < formed.size() - 1; i++) {
            if ((formed[i][(formed[i]).size() - 1]) == formed[i + 1][0])
                return;
        }
        // cout << "HERE\n";
        count++;
        return;
    }
    for (int i = 0; i < v1.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            formed.push_back(v1[i]);
            arrangeSeats(v1, visited, index + 1, formed, count);
            visited[i] = false;
            formed.pop_back();
        }
    }
}




int main() {
    string s = "AB";
    //cout << (s[s.size() - 1]);

    int n;
    cin >> n;
    vector<string> v1(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    //cout <<endl<< (v1[0][(v1[0]).size() - 1])<<endl<< v1[ 1][0];

    int count = 0;
    vector<string> dummy;
    arrangeSeats(v1, visited, 0, dummy, count);
    cout << count;
}