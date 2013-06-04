#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;

#define MP make_pair

const int MAXN = 45;
void solve(int n,int a,int s,int g) {
  vector<pair<int, string> > graph [MAXN];
  
  for(int i=0; i<a; i++) {
    int x,y;
    string s;
    cin>>x>>y>>s;
    graph[y].push_back(MP(x, s));
  }
  string minim[MAXN];
  string next[MAXN];
  string init = "";
  string best ;
  for(int j=0; j<1000; j++) init += "zzzzzzzzzzz";
  for(int i=0; i<n; i++) 
    minim[i] = next[i] = init;
  
  minim[g] = "";
  best = init;
  
  bool ok = true;
  for(int x=0; x<7*n+10; x++) {
    bool isUpdate = false;
    for(int i=0; i<n; i++) {
      for(int j=0; j<graph[i].size(); j++) {
	int to = graph[i][j].first;
	string s = graph[i][j].second;
	if(minim[i]!=init) if(next[to]>s+minim[i]) {
	  next[to] = s+minim[i];
	}
      } 
    }
    for(int i=0; i<n; i++) {
      minim[i] = next[i];
      next[i] = init;
    }
    if(best>minim[s]) {
      //      cout<<x<<" "<<minim[g]<<endl;
      best = minim[s];
      isUpdate = true;
    }
    
    if(isUpdate && x>n+5) ok = false;
  }
  if(best==init) ok = false;
  if(ok) cout<<best<<endl;
  else cout<<"NO"<<endl;
  
}


int main() {
  while(1) {
    int n,a,s,g;
    cin>>n>>a>>s>>g;
    if(n==0 && a==0 && s==0 && g==0)
      break;
    solve(n,a,s,g);
    
    
    
  }
  return 0;
  
}
