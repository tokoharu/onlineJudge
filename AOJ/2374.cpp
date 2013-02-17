#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef long long LL;

LL minL(LL a,LL b) {
  if(a<b) return a;
  return b;
}

void generate(vector<int> &apple , int d,int cnt, int mod) {
  int now = apple[0];
  //  apple.pop_back();
  for(int i=1; i<cnt; i++) {
    now = now*58+d;
    now %= mod;
    apple.push_back(now);
  }
  sort(apple.begin() , apple.end());
  reverse(apple.begin() , apple.end()) ;
  //  for(int i=0; i<apple.size(); i++) cout<<apple[i]<<" ";
  //  cout<<endl;
}


int main() {
  int M,N;
  cin>>M>>N;
  vector<int> kiwi;
  vector<int> rng;

  int md,nd;
  {
    int p,r;
    cin>>p>>md>>r>>nd;
    rng.push_back(p);
    kiwi.push_back(r);
  }
  generate(kiwi,nd,N,M+1);
  generate(rng,md,M,N+1);

  LL sumRng = 0;
  LL sumKiwi = 0;
  int plusNum = M;
  for(int i=0; i<N; i++) {
    while(plusNum>0 && rng[plusNum-1]<i+1) plusNum--;
    sumRng += (LL)plusNum;
    sumKiwi += (LL)kiwi[i];
    //   cout<<sumRng<<" "<<sumKiwi<<endl;
    if(sumRng<sumKiwi) {
      //      kiwi[i] -= sumKiwi-sumRng;
      sumKiwi = sumRng;
    }
  }
  cout<<minL(sumRng,sumKiwi)<<endl;


  return 0;
}
