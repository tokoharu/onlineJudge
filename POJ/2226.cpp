#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;


const int MAX_V = 5510;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u , int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
bool dfs(int v) {
  used[v] = true;
  for(int i=0; i<G[v].size(); i++) {
    int u = G[v][i] , w  =match[u];
    if(w<0 || !used[w] && dfs(w)) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  //  memset(match , -1,  sizeof(match));
  for(int i=0; i<MAX_V; i++) match[i] = -1;
  for(int v=0; v<V; v++) {
    if(match[v]<0) {
      for(int i=0; i<MAX_V; i++) used[i] = false; 
      //      memest(used,0,sizeof(used));
      if(dfs(v)) res++;
    }
  }
  return res;
}
/*

Vに必ずなにか入れましょう
ICPC形式だと、必ずG[i]をすべて初期化するようにしましょう


ここまでコピペしましょう
*/

int column[55][55];
int row[55][55];

string input[55];

int main() {
  int n,m;
  cin>>n>>m;
  V = 5100;
  int iter = 0;
  for(int i=0; i<V; i++)
    G[i].clear();

  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    input[i] = s;
    for(int j=0; j<m; j++) {
      if(input[i][j]=='.') {
	iter++;
      }
      else column[i][j] = iter;
    }
    iter++;
  }
  for(int j=0; j<m; j++) {
    for(int i=0; i<n; i++) {
      if(input[i][j]=='.')
	iter++;
      else row[i][j] = iter;
    }
    iter++;
  }  
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(input[i][j]=='*')
      add_edge(column[i][j],row[i][j]);
  

  cout<<bipartite_matching()<<endl;
  return 0;
  
}
