#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include<vector>
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
	//cout << A[0] <<" "<< A[19999];
	vector<string> H(24000, "");
	vector<string> H2(24000, "");
	//cout << "ZEYAD" << H[0] << H[23999] << "ZEYAD";
	int index;
	int collision = 0, collision2 = 0;
	for (int i = 0; i < 20000; i++) {
		index = secondHashFunction(A[i]);
		while (H[index] != "") {
			index++;
			collision++;
		}
			
		if (index < 24000)
			H[index] = A[i];
	}
	cout << "\nCollision: " << collision << endl;
	for (int i = 0; i < 40; i++) {
		auto start = std::chrono::system_clock::now();
		for (int j = (i * 500); j < (i * 500 + 500); j++) {
			index = secondHashFunction(A[j]);
			while (H2[index] != "") {
				index++;
				collision2++;
			}

			if (index < 24000)
				H2[index] = A[j];
		}
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		cout << "Elapsed time in "<<i+1 <<" 500: " << elapsed_seconds.count() * (10 * 10 * 10) << "ms\n";
	}
	cout << "\nCollision: " << collision2 << endl;
	cout << H[100] << " " << H2[100] << " " << H[1000] << " " << H2[1000] << " " << H[10000]<<" " << H2[10000] << " " << H[15000] << " " << H2[15000];
	for (int i = 0; i < 24000; i++) {
		if (H[i] != H2[i]) {
			cout << "\nWRONG\n" << H[i] << " " << H2[i];
		}
	}
	//cout << "COLLISION: " << collision;
	//string search = A[15000];
	//int prop = 0;
	//int indexSer = secondHashFunction(search);
	//while (H[indexSer] != search) {
	//	indexSer++;
	//	prop++;
	//}
	//	
	//cout << A[15000] << " " << H[indexSer]<<" "<<prop;
	return 0;

	//auto start = std::chrono::system_clock::now();
	//auto end = std::chrono::system_clock::now();
	//std::chrono::duration<double> elapsed_seconds = end - start;
	//std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	//statFile << "Elapsed time: " << elapsed_seconds.count() * (10 * 10 * 10) << "ms\n";

}