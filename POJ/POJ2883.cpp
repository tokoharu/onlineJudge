#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
#define MP make_pair
const int NUM = 511;

int parent[NUM];
int getParent(int n) {
  if(n==parent[n]) return n;
  return parent[n] = getParent(parent[n]);
}
void appendParent(int n , int m) {
  int x = getParent(n);
  int y = getParent(m);
  if(x!=y) parent[x] = y;
}
bool heiro(int n , vector<PII> data , vector<PII> equal){
  for(int i=0; i<n; i++) parent[i] = i;
  for(int i=0; i<equal.size(); i++) {
    appendParent(equal[i].first , equal[i].second);
    //  cout<<"nya"<<equal[i].first<<" "<<equal[i].second<<endl;
    
  }
  vector<int> edge[NUM];
  for(int i=0; i<data.size(); i++) {
    edge[getParent(data[i].first)].push_back(getParent(data[i].second));
  }
  int nums[NUM];
  for(int i=0; i<n; i++) nums[i] = 0;

  for(int x=0; x<n+5; x++) {
    int next[NUM];
    for(int i=0; i<n; i++) next[i] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<edge[i].size(); j++) {
	int dest = edge[i][j];
	next[dest] = max(nums[dest],nums[i]+1);
    }
    for(int i=0; i<n; i++) nums[i] = next[i];
  }
  for(int i=0; i<n; i++) {
    //        cout<<nums[i]<<endl;
    if(nums[i]>n) return true;
  }
  return false;
}

void solve() {
  bool ok = true;
  int n,m;
  cin>>n>>m;
  vector<PII> dataW;
  vector<PII> equalW;
  vector<PII> equalN;
  vector<PII> dataN;
  for(int i=0; i<m; i++) {
    int p,q;
    char s[5];
    scanf ("%d %s %d",&p,s,&q);
    int k = strlen(s);
    if(p==q) ok = false;
    p--;q--;
    for(int j=0; j<k; j++) {
      if(s[j]=='W') dataW.push_back(MP(p,q));
      if(s[j]=='E') dataW.push_back(MP(q,p));
      if(s[j]=='N') dataN.push_back(MP(p,q));
      if(s[j]=='S') dataN.push_back(MP(q,p));
    }
    if(p>q) swap(p,q);
    if(k==1) {
      if(s[0]=='N' || s[0]=='S') equalW.push_back(MP(p,q));
      if(s[0]=='W' || s[0]=='E') equalN.push_back(MP(p,q));
    }
  }
  set<PII> eq;
//  bool ok = true;
  for(int i=0; i<equalW.size(); i++) eq.insert(equalW[i]);
  sort(equalN.begin() , equalN.end());
  //  unique(equalN.begin() , equalN.end());
  for(int j=0; j<equalN.size(); j++) if(j==0 || equalN[j]!=equalN[j-1]){
    int bef = eq.size();
    eq.insert(equalN[j]);
    int aft = eq.size();
    if(bef==aft)  ok = false;
  }
  //    cout<<ok<<endl;
  if(heiro(n,dataW,equalW)) ok= false;
  //    cout<<ok<<endl;
  if(heiro(n,dataN,equalN)) ok= false;
  if(ok) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  return ;

}


int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++) solve();
  return 0;
}
