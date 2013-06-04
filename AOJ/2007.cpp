#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void solve(int n) {
  
  int cand[4];
  int best = 1000000000;
  int p,q,r,s;
  cin>>p>>q>>r>>s;
  for(int i=0; i<=p; i++) {
    for(int j=0; j<=q; j++) {
      for(int k=0; k<=r; k++) {
	for(int l=0; l<=s; l++) {
	  int m = i*10 + j*50 + k*100 + l*500;
	  int nokori = m-n;
	  //	  cout<<m<<" "<<n<<" "<<l<<endl;
	  if(nokori<0) continue;
	  int cnt = 0;
	  cnt += nokori/500; nokori%=500;
	  cnt += nokori/100; nokori%=100;
	  cnt += nokori/50;  nokori%=50;
	  cnt += nokori/10;  nokori%=10;
	  
	  //	  cout<<" hoge"<<m<<" "<<cnt<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
	  
	  int poyo = (cnt-i-j-k-l) * 1000000 + m;
	  if(best>poyo) {
	    best = poyo;
	    cand[0] = i;
	    cand[1] = j;
	    cand[2] = k;
	    cand[3] = l;	    
	  }
	  
	}
      }
    }
  }
  int value[4] = {10,50,100,500};
  for(int i=0; i<4; i++) {
    if(cand[i]!=0) {
      cout<<value[i]<<" "<<cand[i]<<endl;
    }
  }
  
}


int main() {
  int cnt = 0;
  while(1) {
    int n;
    cin>>n;
    if(n==0)break;
    if(cnt!=0)cout<<endl;
    cnt++;
    solve(n);

  }
  return 0;
}

