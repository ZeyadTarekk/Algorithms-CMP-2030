#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

bool func(int index, const vector<int>& vec) {
	bool flag = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > index) {
			flag = true;
		}
	}
	return flag;
}

int main() {

	//vector<int> vec({ 1,2,3,4 ,7});
	//cout << func(8, vec);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_map<int, int> myMap;
	unordered_map<int, int> myMap2;
	int n, d, m;
	cin >> n >> d >> m;
	int read;
	
	int no = 0;
	for (int i = 0; i < n; i++) {
		cin >> read;
		if (myMap.find(read) == myMap.end())
			myMap[read] = 1;
		else
			myMap[read]++;
		if (m == 2) {
			if (myMap[read - d] != 0)
				no += myMap[read - d];
		}
		else if (m == 3) {
			if (myMap[read - d] != 0) {
				myMap2[read] += myMap[read - d];
				if (myMap2[read - d] != 0)
					no += myMap2[read - d];
			}
		}
	}
	cout << no;





	return 0;
}