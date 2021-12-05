#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

bool func(int index, const vector<int>& vec, int& no) {
    bool flag = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > index) {
            no++;
            flag = true;
        }    
    }
    return flag;
}

int main() {

    //vector<int> vec({ 1,2,3,4 ,7});
    //cout << func(8, vec);

    unordered_map<int, vector<int>> myMap;
    int n, d, m;
    cin >> n >> d >> m;
    int read;
    for (int i = 0; i < n; i++) {
        cin >> read;
        myMap[read].push_back(i);
    }
    //for (auto m:myMap) {
    //    cout << m.first << " ";
    //    for (int i = 0; i < m.second.size(); i++)
    //        cout << m.second[i] << " ";
    //    cout << endl;
    //}
    int no = 0;
    int dummy;
    vector<int>waysNo;
    for (auto mm : myMap) {
        
        for (int i = 0; i < mm.second.size(); i++) {
            int no2 = 0;
            dummy = mm.first;
            bool flag = true;
            for (int j = 0; j < m-1; j++) {
                if (myMap.find( dummy + d) == myMap.end())
                    flag = false;
                dummy += d;
            }
            dummy = mm.first;
            if (flag) {
                vector<int> numbers;
                bool flag2 = true;
                for (int j = 0; j < m - 1; j++) {
                    no2 = 0;
                    if (!func(mm.second[i], myMap[dummy + d], no2))
                        flag2 = false;
                    else
                        numbers.push_back(no2);
                    dummy += d;
                }
                if (flag2) {
                    no = 1;
                    for (int i = 0; i < numbers.size(); i++)
                        no *= numbers[i];
                    waysNo.push_back(no);
                }
                    
            }

        }
    }
    int sum = 0;
    for (int i = 0; i < waysNo.size(); i++)
        sum += waysNo[i];
    cout << sum;

    return 0;
}