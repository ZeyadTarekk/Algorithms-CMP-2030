#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<cmath>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	//node() {
	//	data = -1;
	//	left = NULL;
	//	right = NULL;
	//}
	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}

};

long long findSum(node* root) {
	if (!root)
		return 0;
	return root->data + findSum(root->left) + findSum(root->right);
}




int main() {
	int n;
	long long r;
	cin >> n >> r;
	node* root;
	vector<node*>vec(n);
	int no;
	for (int i = 0; i < n; i++) {
		cin >> no;
		vec[i] = new node(no);
	}
	root = vec[0];
	int edges;
	cin >> edges;
	char c;
	int parent, child;
	for (int i = 0; i < edges; i++) {
		cin >> c >> parent >> child;
		if (c == 'L')
			vec[parent]->left = vec[child];
		else
			vec[parent]->right = vec[child];
	}
	int no2 = 0;
	for (int i = 0; i < n; i++) {
		long long lSum = findSum(vec[i]->left);
		long long rSum = findSum(vec[i]->right);
		if (abs(lSum - rSum) <= r)
			no2++;
	}
	cout << no2;
	return 0;
}