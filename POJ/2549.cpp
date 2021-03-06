#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<utility>
using namespace std;
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PII;
bool solve() {
  int n;
  scanf("%d",&n);
  if(n==0) return false;
  vector<int> input;
  for(int i=0; i<n; i++) {
    int p;
    scanf("%d",&p);
    input.push_back(p);
  }
  
  vector<LL> A;
  vector<PII> B;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      A.push_back((LL)input[i] + input[j]);
      B.push_back(MP( (LL) input[i] - input[j] ,(LL) input[i] ) );
    }
  }
  sort(A.begin() , A.end());  

  LL INF = 10000007;
  int sz = B.size();
  bool ans = false;
  LL nums = -INF * INF;
  for(int i=0; i<sz; i++) {
    if(binary_search(A.begin() , A.end(), B[i].first)) {
      ans = true;
      nums = max(nums,(LL) B[i].second);
    }
  }
  if(ans) cout<<nums<<endl;
  else cout<<"no solution"<<endl;
  return true;
}


int main() {
  while(1) {
    if(!solve()) break;
  }
  return 0;
}
