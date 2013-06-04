#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

void solve(int w,int h) {
  int field[70][20];
  for(int i=0; i<h; i++) {
    string s;
    cin>>s;
    for(int j=0; j<s.size(); j++) {
      if(s[j]=='.') field[i][j] = -1;
      else field[i][j] = field[i][j]-'0';
    }
  }
  for(int j=0; j<w; j++) field[h][j] = 10;
  
  int parent[11];
  vector<int> child[11];
  for(int i=0; i<11; i++)
    child[i] = -1;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      int cur = field[i][j];
      if(cur!=-1) {
	int base = field[i+1][j];
	if(base==cur) continue;
	if(base==-1) continue;
	parent[cur] = base;
	//	child[base].push_back(cur);
      }
    }
    
  }
  bool isChild[11][11];
  for(int i=0; i<11; i++)
    for(int j=0; j<11; j++)
      isChild[i][j] = false;
  
  for(int i=0; i<11; i++) {
    if(parent[i]!=-1) {
      isChild[parent[i]][i] = true;
    }
  }
    
  for(int j=0; j<11; j++) 
    for(int i=0; i<11; i++)
      for(int k=0; k<11; k++)
	isChild[i][k] |= isChild[i][j] & isChild[j][k];
  
  double EPS = 1e-6;
  
  
  

}


int main() {
  while(1) {
    int w,h;
    cin>>w>>h;
    if(w==0 && h==0) break;
    solve(w,h);
    
  }
  
  return 0;
}
