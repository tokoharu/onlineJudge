#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN = 1000100;
int dpA[MAXN];
int dpB[MAXN];

void init() {
  for(int i=0; i<MAXN; i++) {
    dpB[i] = dpA[i] = 1000000000;
     
    }
  dpA[0] = dpB[0] = 0;
  for(int i=1; ; i++) {
    int diff = i*(i+2)*(i+1)/6;
    if(diff>=MAXN) break;
    
    for(int x=0; x<MAXN-diff; x++) {
      dpA[x+diff] = min(dpA[x+diff], dpA[x]+1 );
    }
    if(diff%2==1)
      for(int x=0; x<MAXN-diff; x++)
	dpB[x+diff] = min(dpB[x+diff], dpB[x]+1);
    
  }
  
}


int main() {
  init();
  while(1) {
    int n;
    cin>>n;
    if(n==0)  break;
    cout<<dpA[n]<<" "<<dpB[n]<<endl;

  }
  
  return 0;
}
