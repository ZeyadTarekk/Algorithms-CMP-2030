#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This code is used for guidance (you can change it if you want).

struct Node
{
    int index;
    int rating;
    Node* parent; // this is optional
    vector<Node*> children;
};


long long maximumSum(Node* root) {

  return 0;
}

int main() {

  // Number of nodes in the tree
  int N;
  cin >> N;

  vector<Node*> nodes(N);
  for (int i = 0; i < N; i++) {
    nodes[i] = new Node;
    nodes[i]->index = i;
    cin >> nodes[i]->rating;
  }

  // Iterating over all edges
  int parent, child;
  for (int i = 0; i < N-1; i++) {
    cin >> parent >> child;
    nodes[child]->parent = nodes[parent];
    nodes[parent]->children.push_back(nodes[child]);
  }

  // TODO: Create a vector called 'memo' used for memoization (What is the dimensions of that vector?)
  // then uncomment the following line.
  // cout << maximumSum(nodes[0], memo);

  return 0;
}