#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main() {
	unordered_map<int, int> myMap;
	int n, d, m;
	cin >> n >> d >> m;
	int no;
	
	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> no;
		if (myMap[no] == 0)
			myMap[no] = 1;
		else
			myMap[no]++;
		numbers[i] = no;
	}

	//for (auto m:myMap) {
	//	cout << m.first << " " << m.second << endl;
	//}
	unordered_map<int, int>::iterator it;
	it = myMap.begin();
	//cout << myMap.size();
	//vector<vector<int>> ways;
	vector<int> ways;
	vector<int>dummyV;
	int dummy;
	for (auto it:myMap) {
		int no1 = 0;
		vector<int>dummyV;
		dummy = (it).first;
		//cout << (*it).first << endl;
		for (int j = 0; j < m; j++) {
			dummyV.push_back(dummy);
			dummy += d;
		}
		//ways.push_back()

		bool flag = true;
		for (int j = 0; j < dummyV.size(); j++) {
			if (myMap[dummyV[j]] == 0) {
				flag = false;
				break;
			}
				
		}
		if (flag) {
			for (int j = 0; j < dummyV.size(); j++) {
				if (myMap[dummyV[j]] != 0) {
					if (no1 == 0)
						no1 += myMap[dummyV[j]];
					else
						no1 *= myMap[dummyV[j]];
				}
			}
			ways.push_back(no1);
		}
		
		// it++;

	}

	int sum = 0;
	for (int i = 0; i < ways.size(); i++) {
		sum += ways[i];
	}
	cout << sum;
	return 0;
}