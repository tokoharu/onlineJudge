#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

void solve(int n, int m) {
  vector<int> input;
  for(int i=0; i<n; i++) {
    int p;
    scanf("%d",&p);
    input.push_back(p);
  }
  double ret = 0;
  double k = (double)m/n;
  for(int i=n-1; i>=0; i--) {
    ret += (double) (input[i] - input[n-1-i]) * k ;
    if(i>0) k *= (double)(i-m+1)/(i);
  }
  printf("%.3f\n",ret);
  
}


int main() {
  while(1) {
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0) break;
    solve(n,m);
  }
  return 0;
}
