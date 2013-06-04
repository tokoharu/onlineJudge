#include<iostream>
#include<cstdio>
using namespace std;

void solve(int n) {
  int x[300], y[300];
  x[0] = 0,  y[0] =0;
  for(int i=0; i<n-1; i++) {
    int p,d;
    cin>>p>>d;
    
    x[i+1] = x[p];
    y[i+1] = y[p];
    if(d==0) x[i+1]--;
    if(d==1) y[i+1]++;
    if(d==2) x[i+1]++;
    if(d==3) y[i+1]--;
    
    
  }
  int ansx,ansy;
  int minim = 0 , maxim = 0;
  for(int i=0; i<n; i++) {
    minim = min(minim, x[i]);
    maxim = max(maxim, x[i]);
  }
  ansx = maxim - minim;
  minim = maxim = 0;
  for(int i=0; i<n; i++) {
    minim = min(minim, y[i]);
    maxim = max(maxim, y[i]);

  }
  ansy = maxim - minim;
  cout<<ansx+1<<" "<<ansy+1<<endl;
}


int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==0) break ;
    solve(n);
    
  }
  return 0;

}
