#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;


struct node {
	int data;
	node* left;
	node* right;
	int nodeNo;
	node(int val,int noNo)
	{
		data = val;
		left = NULL;
		right = NULL;
		nodeNo = noNo;
	}

};

struct BST {
	node* root;
	int no;
	BST() {
		root = nullptr;
		no = 0;
	}
	void insert(node*& subroot, int dataa) {
		if (subroot == nullptr) {
			subroot = new node(dataa, no);
			no++;
		}
		else if (subroot->data < dataa)
		{
			//no++;
			insert(subroot->right, dataa);
		}
		else if(subroot->data > dataa)
		{
			//no++;
			insert(subroot->left, dataa);
		}
	}
	void insertBST(int dataa) {
		insert(root, dataa);
	}
};

struct nsetedBST {
	node* root;
	int no;
	nsetedBST() {
		root = nullptr;
		no = 0;
	}
	void insert(node*& subroot, int dataa) {
		if (subroot == nullptr) {
			subroot = new node(dataa, no);
			no++;
		}
		else if (subroot->data < dataa)
		{
			//no++;
			insert(subroot->right, dataa);
		}
		else
		{
			//no++;
			insert(subroot->left, dataa);
		}
	}
	void insertBST(int dataa) {
		insert(root, dataa);
	}
};



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	//node* root = new node;
	//root->left = nullptr;
	//root->right = nullptr;
	//root->tree = nullptr;

	BST	mainTree;
	vector<pair<int, int>> vec1(n);
	vector<pair<int, int>> vec2(q);


	for (int i = 0; i < n; i++) {
		cin >> vec1[i].first >> vec1[i].second;
		mainTree.insertBST(vec1[i].first);
	}
	vector<nsetedBST> subtrees(mainTree.no);
	//cout << "\nNO " << mainTree.no << endl;
	for (int i = 0; i < q; i++) {
		cin >> vec2[i].first >> vec2[i].second;
	}

	

	for (int i = 0; i < n; i++) {
		node* trav = mainTree.root;
		while (trav!=nullptr && vec1[i].first != trav->data) {
			if (vec1[i].first > trav->data)
				trav = trav->right;
			else if (vec1[i].first < trav->data)
				trav = trav->left;
		}
		if (trav != nullptr) {
			subtrees[trav->nodeNo].insertBST(vec1[i].second);
		}
	}
	//cout << subtrees[0].root->data << " " << subtrees[1].root->data << " " << subtrees[2].root->data;
	int visited = 1, flag = 0;
	for (int i = 0; i < q; i++) {
	
		int visited = 1;
		node* trav = mainTree.root;
		while (trav!=nullptr && trav->data!=vec2[i].first){
			if (vec2[i].first > trav->data) {
				visited++;
				trav = trav->right;
			}
			else {
				visited++;
				trav = trav->left;
			}
		}
		if (trav == NULL)
			cout << visited -1<< " " << 0 << endl;
		else {
			visited++;
			node* travSub = subtrees[trav->nodeNo].root;
			while (travSub!=nullptr&&vec2[i].second!=travSub->data)
			{
				if (vec2[i].second > travSub->data) {
					visited++;
					travSub = travSub->right;
				}
				else {
					visited++;
					travSub = travSub->left;
				}
			}
			if (travSub == nullptr) {
				cout << visited-1 << " " << 0 << endl;
			}
			else
				cout << visited << " " << 1 << endl;
		}
	}
	return 0;
}