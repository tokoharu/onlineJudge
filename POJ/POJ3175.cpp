#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;

LL getSeisu(LL n , LL L , LL kijun) {

    LL seisu = n*n;
    LL shosu = L*L;
    LL yobi =  2*n*L;
    //   cout<<seisu<<" "<<shosu<<" "<<yobi<<endl;
    seisu += yobi/kijun;
    //   cout<<seisu<<endl;
    yobi%=kijun;
    shosu += yobi*kijun;
    seisu += shosu/(kijun*kijun);
    //    cout<<seisu<<endl;
    if(shosu%(kijun*kijun)==0) seisu--; 
    return seisu;

}

void solve() {
   LL T , L;
  cin>>T>>L;
  if(L==0) {
    cout<<1<<endl;
    return ;
  }
  if(L==1 && T>=3) {
    cout<<625;
    T -= 2;
    T = T*2+1;
    for(int i=0; i<T; i++) cout<<0;
    cout<<1<<endl;
    return ;
  }
  LL R = L+1;

  LL kijun = 1;
  for(int i=0; i<T; i++) kijun *= 10;
  for(LL n=1;; n++) {
    LL a = getSeisu(n,L,kijun);
    LL b = getSeisu(n,R,kijun);
    //    cout<<n<<" " <<a<<" "<<b<<endl;
    if(a!=b) {
      cout<<b<<endl;
      return ;
    }
  }
}

void calc() {


}

int main() {

  calc();

  solve();
  return 0;
}
