#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<vector>

using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

#define MP make_pair
void solve() {
  vector<PII> part;
  vector<PII> mizu;
  vector<PII> times;
  
  int N,M,L;
  cin>>N;
  for(int i=0; i<N; i++) {
    int p,q;
    cin>>p>>q;
    part.push_back(MP(q,p));
    
  }

  part.push_back(MP(50,100));
  cin>>M;
  for(int i=0; i<M; i++) {
    int f,a;
    cin>>f>>a;
    int i;
    for(i=0; i<=N; i++) if(f<part[i].second) break;
    
    mizu.push_back(MP(i,a));
    

  }

  sort(part.begin(),  part.end());

  cin>>L;
  for(int z=0; z<L; z++) {
    int P,T;
    cin>>P>>T;
    //    times.push_back(MP(p,q));
    
    vector<double> flow(N+1,0.00);
    for(int i=0; i<=N; i++) flow[i] = 0;
    for(int i=0; i<M; i++) flow[mizu[i].first] += (double) mizu[i].second * (double)T; 
    
    for(int i=0; i<N; i++) {
      
      
    }
    
  }
  
  
  
  

}



int main() {
  int d;
  cin>>d;
  for(int i=0; i<d; i++) solve();
  
  return 0;
}
