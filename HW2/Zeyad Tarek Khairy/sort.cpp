#include<iostream>
#include <iostream>
#include <fstream>
#include<cmath>
#include<ctime>
#include<climits>
#include<vector>
#include<chrono>
using namespace std;
//#pragma warning(suppress : 4996)
//#pragma warning(disable : 4996)

void insertionSort(vector<int> & v) {
	int key , i;
	for (int j = 1; j < v.size(); j++) {
		key = v[j];
		i = j - 1;
		while (i >= 0 && v[i] > key) {
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = key;
	}
}

void merge(vector<int>& v, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> v2; //v2 => L 
	vector<int> v3; // v3 => R
	for (int i = 0; i < n1; i++) {
		v2.push_back(v[p + i - 1]);
	}
	for (int i = 0; i < n2; i++) {
		v3.push_back(v[q + i]);
	}
	v2.push_back(INT_MAX);
	v3.push_back(INT_MAX);
	int i = 0, j = 0;
	for (int k = p - 1; k < r; k++) {
		if (v2[i] <= v3[j])
			v[k] = v2[i++];
		else
			v[k] = v3[j++];
	}
}

void mergeSort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = floor((p + r) / 2.0);
		mergeSort(v, p, q);
		mergeSort(v, q + 1, r);
		merge(v, p, q, r);
	}
}


int partition(vector<int>& v, int p, int r) {
	int x = v[r];
	int i = p - 1;
	for (int j = p ; j < r ; j++) {
		if (v[j] <= x) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[r]);
	return i + 1;
}


void quickSort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void selectionSort(vector<int>& v) {
	//cout << "\nEntered algo\n";
	//cout << "\nSize of vector: "<<v.size()<<endl;
	if (v.size() > 0) {
		for (int i = 0; i < v.size() - 1; i++) {
			//cout << "\nEntered for loop\n";
			int min_index = i;
			int min = v[min_index];
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j] < min) {
					min_index = j;
					min = v[min_index];
				}
			}
			swap(v[i], v[min_index]);
		}
	}

}


void mergeHybrid(vector<int>& v, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> v2; //v2 => L 
	vector<int> v3; // v3 => R
	for (int i = 0; i < n1; i++) {
		v2.push_back(v[p + i - 1]);
	}
	for (int i = 0; i < n2; i++) {
		v3.push_back(v[q + i]);
	}
	v2.push_back(INT_MAX);
	v3.push_back(INT_MAX);
	int i = 0, j = 0;
	for (int k = p - 1; k < r; k++) {
		if (v2[i] <= v3[j])
			v[k] = v2[i++];
		else
			v[k] = v3[j++];
	}
}


void hybridSort(vector<int>& v, int p, int r) {
	if (v.size() > 75) {
		if (p < r) {
			int q = floor((p + r) / 2.0);
			hybridSort(v, p, q);
			hybridSort(v, q + 1, r);
			mergeHybrid(v, p, q, r);
		}
	}
	else if (v.size() <= 75) {
		int key, i;
		for (int j = 1; j < v.size(); j++) {
			key = v[j];
			i = j - 1;
			while (i >= 0 && v[i] > key) {
				v[i + 1] = v[i];
				i--;
			}
			v[i + 1] = key;
		}
	}
}

int main(int argc, char** argv) {
	
		vector<int> v1;

		ifstream inFile;
		ofstream outFile, statFile;

		
		/*string filename, filename2, fileName3;
		cin >> filename >> filename2 >> fileName3;*/

		inFile.open(argv[2]);
		outFile.open(argv[3]);
		statFile.open(argv[4]);
	/*	inFile.open(filename);
		outFile.open(filename2);
		statFile.open(fileName3);*/

		if (!inFile) {
			cout << "CANT OPEN FILE\n";
			return 0;
		}
	


		int no;
		while (inFile >> no)
			v1.push_back(no);


		outFile << "File Size: " << v1.size() << endl;
		statFile << "File Size: " << v1.size() << endl;

		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//for (int i = 0; i < v1.size(); i++)
		//	cout << v1[i] << " ";
		//cout << endl;
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++


		auto start = std::chrono::system_clock::now();
		if (atoi(argv[1]) == 0) {
			selectionSort(v1);
			outFile << "Algorithm: Selection Sort\n";
			statFile << "Algorithm: Selection Sort\n";
		}
		else if (atoi(argv[1]) == 1) {
			insertionSort(v1);
			outFile << "Algorithm: Insertion Sort\n";
			statFile << "Algorithm: Insertion Sort\n";
		}
		else if (atoi(argv[1]) == 2) {
			mergeSort(v1, 1, v1.size());
			outFile << "Algorithm: Merge Sort\n";
			statFile << "Algorithm: Merge Sort\n";
		}
		else if (atoi(argv[1]) == 3) {
			quickSort(v1, 0, v1.size() - 1);
			outFile << "Algorithm: Quick Sort\n";
			statFile << "Algorithm: Quick Sort\n";
		}
		else if (atoi(argv[1]) == 4) {
			hybridSort(v1, 1, v1.size());
			outFile << "Algorithm: Hybrid Sort\n";
			statFile << "Algorithm: Hybrid Sort\n";
		}
		auto end = std::chrono::system_clock::now();
		//for (int i = 0; i < v1.size(); i++)
		//	cout << v1[i] << " ";

		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		statFile << "Elapsed time: " << elapsed_seconds.count() * (10*10*10) << "ms\n";
		for (int i = 0; i < v1.size(); i++)
			outFile << v1[i] << "\n";

		/*std::cout << "finished computation at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";*/

	

	return 0;
}