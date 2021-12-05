#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;

int firstHashFunc(string s) {
	if (s.size() == 1)
		return 39 * (int)s[0];
	else if (s.size() == 2)
		return 39 * (int)s[0] + 392 * (int)s[1];
	else if (s.size() == 3)
		return 39 * (int)s[0] + 392 * (int)s[1] + 393 * (int)s[2];
	else
		return 39 * (int)s[0] + 392 * (int)s[1] + 393 * (int)s[2] + 394 * s[3];
}

int secondHashFunction(string s) {
	return firstHashFunc(s) % 24000;
}


int main() {
	ifstream inp;
	inp.open("words20K.txt");
	if (!inp) {
		cout << "CANT OPEN FILE\n";
		return 0;
	}
	vector<string> A(20000);
	string word;
	for (int i = 0; i < 20000; i++) {
		inp >> word;
		A[i] = word;
	}

	vector<string> H(24000, "");

	int index;
	int collision2 = 0;// , collision = 0;



	for (int i = 0; i < 40; i++) {
		auto start = std::chrono::system_clock::now();
		for (int j = (i * 500); j < (i * 500 + 500); j++) {
			index = secondHashFunction(A[j]);
			while (H[index] != "" && H[index] != "!") {
				index++;
				collision2++;
			}

			if (index < 24000)
				H[index] = A[j];
		}
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		cout << "Elapsed time in "<<i+1 <<" 500: " << elapsed_seconds.count() * (10 * 10 * 10) << "ms\n";
	}
	
	//Deletion from 14000 to 14999
	string searching;
	int index2;
	int propMin = INT_MAX, propMax = INT_MIN, prop;
	vector<int>propVec;
	for (int i = 14000; i < 15000; i++) {
		prop = 0;
		searching = A[i];
		
		index2 = secondHashFunction(searching);
		//cout << H[index2] << " " << searching << endl;
		while (H[index2] != searching) {
			if (H[index2] == "") {
				//cout << endl << "NOT FOUND\n";
				break;
			}
			prop++;
			index2++;
		}
		if (H[index2] != "") {
			propVec.push_back(prop);
			if (prop > propMax)
				propMax = prop;
			if (prop < propMin)
				propMin = prop;
			//cout << H[index2] << " " << searching << endl;
			H[index2] = "!";
		}
	}
	
	cout<<"Max No. Of Probes: " << propMax <<endl;
	cout << "Min No. Of Probes: " << propMin << endl;
	int sum = 0;
	for (int i = 0; i < propVec.size(); i++) {
		sum += propVec[i];
	}
	cout << "Average No. Of Probes: " << (float)sum / propVec.size();
	return 0;


}