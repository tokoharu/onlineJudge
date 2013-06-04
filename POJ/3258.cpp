#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
  int L,N,M;
  cin>>L>>N>>M;
  vector<int> input;
  input.push_back(0);
  input.push_back(L);
  for(int i=0; i<N; i++) {
    int p;
    cin>>p;
    input.push_back(p);
  }
  sort(input.begin() , input.end());
  
  int right = 1000000000;
  int left = 0;
  int sz = input.size();
  while(right-left>1) {
    int mid = (right+left) /2;
    
    int cnt = 0;
    int prev = 0;
    for(int i=1; i<sz; i++) {
      if(input[i]-prev>=mid) {
	prev = input[i];
      }
      else cnt++;
      
    }
  
    if(cnt>M) {
      right = mid;
      //    cout<<mid<<" "<<cnt<<endl;
    }
    else left = mid;
  }
  
  cout<<left<<endl;
  
  return 0;
}
