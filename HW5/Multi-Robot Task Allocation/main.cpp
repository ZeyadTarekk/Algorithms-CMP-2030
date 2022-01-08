#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void DFS(int node, vector<bool>&visited, stack<int> &st, vector<vector<int>> &vec) {

  //cout << node << " ";

  visited[node] = true;
  for (int i = 0; i < vec[node].size(); i++) {
    if (visited[vec[node][i]] != true) {
      DFS(vec[node][i], visited, st,vec);
    }
  }

  //cout << node << " ";
  st.push(node);

}
int main() {


  int v ;
  cin >> v;
  vector<vector<int>> vec(v);
  vector<bool> visited(v);
  stack<int> st;

  int x1, x2;
  for (int i = 0; i < v; i++) {
    cin >> x1 >> x2;
    if (x1 != -1)
      vec[x1].push_back(i);
    if (x2 != -1)
      vec[x2].push_back(i);
  }


  //vec[0].push_back(1);
  //vec[0].push_back(6);
  //vec[1].push_back(2);
  //vec[1].push_back(6);
  //vec[2].push_back(5);
  //vec[3].push_back(2);
  //vec[3].push_back(4);
  //vec[4].push_back(5);
  //vec[7].push_back(6);



  for (int i = 0; i < vec.size(); i++) {
    if (visited[i] != true)
      DFS(i,visited,st,vec);
  }


  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }


  return 0;
}