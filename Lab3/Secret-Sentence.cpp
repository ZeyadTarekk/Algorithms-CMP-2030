#include <unordered_map> 
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include<utility>
#include <vector>
using namespace std;

// Helper function
void preprocess(string& str) {
    // Removing punctuation
    for (int i = 0, len = str.size(); i < len; i++)
    {
        // Check whether parsing character is punctuation or not 
        if (ispunct(str[i]))
        {
            str.erase(i--, 1);
            len = str.size();
        }
    }

    // Converting to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Helper function
vector<string> readFile() {
    ifstream f("two-cities.txt"); //taking file as inputstream

    string file;

    if (f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();

        // Removes punctuation and converts to lower case
        preprocess(file);

        // Split into tokens on space
        istringstream iss(file);
        vector<string> tokens{ istream_iterator<string>{iss},
                          istream_iterator<string>{} };

        return tokens;
    }

    vector<string> empty;
    return empty;
}


bool cmp(pair<string, int>a, pair<string, int>b) {
    return b.second < a.second;
}



// TODO: IMPLEMENT THIS FUNCTION
string findSecret(const vector<string>& tokens) {
    // Hint: you can use std::unordered_map and std::sort
    // unordered_map<string, int>

    unordered_map<string, int> myMap;
    for (int i = 0; i < tokens.size(); i++) {
        if (myMap[tokens[i]] == 0)
            myMap[tokens[i]] = 1;
        else
            myMap[tokens[i]]++;
    }

    vector<pair<string, int>> vec(myMap.begin(), myMap.end());

    sort(vec.begin(), vec.end(), cmp);

  /*  for (auto m: vec) {
        cout << m.first << " " << m.second<<endl;
    }*/

    string result = "";
    result = vec[10].first + " " + vec[22].first + " " + vec[21].first + " " + vec[42].first + " " + vec[2].first + " " + vec[46].first;

    return result;
}

int main() {

    vector<string> tokens = readFile();

    cout << findSecret(tokens) << endl;

    return 0;
}
