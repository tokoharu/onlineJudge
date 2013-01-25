#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/*
void solve(int n) {
  if(n<=4) {
    for(int i=0; i<n-1; i++) cout<<"1 1 "<<n-i-1<<endl;
    return ;
  }
  cout<<"1 2 "<<n-3<<endl;
  cout<<n-3<<" 2 "<<n-2<<endl;
  solve(n-4);
  cout<<"1 "<<n-3<<" "<<2<<endl;  
}
int main() {
  int n;
  cin>>n;
  cout<<n*3/4<<endl;
  solve(n);
  return 0;

}
*/

int main() {
  int n;
  cin>>n;
  if(n<=4) {
    cout<<n-1<<endl;
    for(int i=0; i<n-1; i++) cout<<"1 1 "<<n-1-i<<endl;
    return 0;
  }
  cout<<n/2+1<<endl;
  int k = (n+1)/2-1;
  for(int i=0; i<n/2; i++) {
    cout<<i+k+1<<" 2 "<<i<<endl;
  }
  cout<<1<<" "<<n/2<<" "<<n/2<<endl;
  return 0;
}

