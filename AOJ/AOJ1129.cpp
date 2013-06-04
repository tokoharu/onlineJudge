#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
#define MP make_pair

int solve() {
  int n,m;
  cin>>n>>m;
  if(n==0 && m==0) return -1;
  vector<PII> input;
  for(int i=0; i<m; i++) {
    int p,q;
    cin>>p>>q;
    p--;
    input.push_back(MP(p,q));
  }
  
  int pos = 0;
  reverse(input.begin() , input.end());
  
  for(int i=0; i<m; i++) {
    int p = input[i].first;
    int q = input[i].second;
    if(pos<q) pos +=p; 
    else if(pos<p+q) pos-=q;
    
  }
  return n-pos;
  
}


int main() {
  while(1) {
    int ans = solve();
    if(ans<0) break;
    cout<<ans<<endl;
  }
  return 0;
  
}

