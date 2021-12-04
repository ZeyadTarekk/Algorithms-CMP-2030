#include<iostream>
#include<vector>
#include<climits>
#include<string>
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




void sumLevel(node* root, int level,int& sum)
{
	if (root == NULL)
		return;
	if (level == 0)
		sum += root->data;
	else if (level > 0) {
		sumLevel(root->left, level - 1,sum);
		sumLevel(root->right, level - 1,sum);
	}
}

void minLevel(node* root, int level, int& min) {
	if (root == NULL)
		return;
	if (level == 0) {
		if (root->data < min)
			min = root->data;
	}
	else if (level > 0) {
		minLevel(root->left, level - 1, min);
		minLevel(root->right, level - 1, min);
	}
}


int findHeight(node* tree) {
	if (tree == nullptr)
		return 0;
	else {
		int lheight = findHeight(tree->left);
		int rheight = findHeight(tree->right);

		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}

int main() {
	int n, edges;
	cin >> n;
	node* root;
	vector<node*> vec(n);
	int no;
	for (int i = 0; i < n; i++) {
		cin >> no;
		vec[i] = new node(no);
	}
	root = vec[0];
	cin >> edges;
	char c;
	int parent, child;
	for (int i = 0; i < edges; i++) {
		cin >> c >> parent >> child;
		if (c == 'L') {
			vec[parent]->left = vec[child];
		}
		else if (c == 'R') {
			vec[parent]->right = vec[child];
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << vec[i]->data << " ";
	}*/
	//printPreorder(root);
	int height = findHeight(root);
	int l = root->data % height;

	int min = INT_MAX;
	minLevel(root, l, min);
	
	int k =	min%height;
	if (k == 0)
		k = 1;

	//cout << endl << "K: " << k << " L: " << l << " Height: " << height << endl;

	int sum = 0;
	string enc = "";
	for (int i = 0; i < height; i+=k) {
		sum = 0;
		sumLevel(root, i , sum);
		enc += to_string(sum);
	}
	cout << enc;
	return 0;
}