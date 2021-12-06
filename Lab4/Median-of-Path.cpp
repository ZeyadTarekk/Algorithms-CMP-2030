#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<cmath>
#include<set>
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

void func(node* root, multiset<int>myset, int& no,int level) {
	if (root) {
		myset.insert(root->data);

		if (level % 2 != 0) {
			multiset<int>::iterator it = myset.begin();
			advance(it, myset.size() / 2);
			if (root->data == (*it))
				no++;
		}
		func(root->left, myset, no, level + 1);
		func(root->right, myset, no, level + 1);
	}
}

int main() {
	int n;
	cin >> n;
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
	multiset<int> mySet;
	int no2 = 0;
	func(root, mySet, no2, 1);
	cout << no2;
	return 0;
}