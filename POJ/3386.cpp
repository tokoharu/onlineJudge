#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool ok() {
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  if(a>e) return false;
  if(c>e) return false;
  if(a+c<=e) return true;
  if(b>=c) return true;
  if(d>=a) return true;
  return false;
}

int main() {
  if(ok()) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
