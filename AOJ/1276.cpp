#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

const int MAXN = 2000000;
vector<int> prime;
bool isPrime[MAXN];
void init() {
  for(int i=0; i<MAXN; i++) isPrime[i] = true;
  isPrime[0] = isPrime[1] = false;
  for(int i=2; i*i<MAXN; i++) if(isPrime[i]) 
    for(int j=i; i*j<MAXN; j++) {
      isPrime[i*j] = false; 
    }
  for(int i=0; i<MAXN; i++)
    if(isPrime[i])
      prime.push_back(i);

}
bool solve() {
  int n;
  cin>>n;
  if(n==0) return false;
  
  if(binary_search(prime.begin() , prime.end(), n)) {
    cout<<0<<endl;
    return true;
  }
  
  int cur = upper_bound(prime.begin() , prime.end(), n) - prime.begin();
  cout<<prime[cur]-prime[cur-1]<<endl;

  
  return true;
}

int main() {
  init();
  while(1) {
    if(!solve()) break;
    
  }
  
  return 0;
}
