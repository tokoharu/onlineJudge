#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

bool solve(int casenum) {
  int n,t,s;
  cin>>n>>t>>s;
  if(n==0 && t==0 && s==0 ) return false;
  int ans = 0;
  for(int i=0; i<n; i++) {
    int p,q,r;
    cin>>p>>q>>r;
    if(q==1) ans++;
    if(r==1) ans++;
  }
  bool data[1000];
  for(int i=0; i<=n; i++)
    data[i] = false;
  for(int i=0; i<t; i++) {
    int p,q;
    cin>>p>>q;
    if(q>=s)
      data[p] = true;
    
  }
  
  for(int i=0; i<=n; i++)
    if(data[i])
      ans++;
  cout<<"Case "<<casenum<<": "<<ans<<endl;
  return true;
}


int main() {
  for(int i=0;;i++)
    if(!solve(i+1))
      break;
  
  return 0;
}
