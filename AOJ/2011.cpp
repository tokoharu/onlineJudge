#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int solve(int n) {
  vector<int> meeting[31];
  
  for(int i=0; i<n; i++) {
    int m;
    cin>>m;
    for(int j=0; j<m; j++) {
      int p;
      cin>>p;
      meeting[p].push_back(i);
    }
  }
  
  int res[50][50];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
      if(i==j) res[i][j] = 1;
      else res[i][j] = 0;
    }
  for(int days=1; days<31; days++) {
    int tmp[50][50];
    for(int i=0; i<50; i++) for(int j=0; j<50; j++) tmp[i][j] = res[i][j];
    int m = meeting[days].size();
    for(int person=0; person<n; person++) {
      for(int i=0; i<m; i++) {
	for(int j=0; j<m; j++) {
	  tmp[person][meeting[days][i]] |= res[person][meeting[days][j]];
	}
      }
    }
    for(int i=0; i<n; i++)  {
      bool ok = true;
      for(int j=0; j<n; j++) {
	if(tmp[j][i]==0) ok= false; 
      }
      if(ok) return days;
    }
    
    //    cout<<days<<endl;
    for(int i=0; i<n; i++) { 
      for(int j=0; j<n; j++) {
	res[i][j] = tmp[i][j];
	//	cout<<res[i][j]<<" ";
      }
      //      cout<<endl;
    }
    
  }
  
  return -1;
  
}

int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==0) break;
    int ans = solve(n);
    cout<<ans<<endl;
  }
  return 0;
  
  
}
