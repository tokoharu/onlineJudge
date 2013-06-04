#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
#define MP make_pair



#define  VI vector<LL>
#define  VVI vector<vector<LL> >

const LL MOD = 1000000009;

VVI matrix_multi(VVI a,VVI b){
  //  cout<<"size"<<a.size()<<" "<<b[0].size()<<endl;
  VVI ret(a.size(),VI(b[0].size(),0));
  for(int k=0;k<a[0].size();k++)
    for(int i=0;i<a.size();i++)
      for(int j=0;j<b[0].size();j++)
	{
	  //	  cout<<i<<" "<<j<<" "<<ret[i][j]<<endl;
	  ret[i][j] += a[i][k]*b[k][j];
	  ret[i][j] %= MOD;
	}
  return ret;
}


VVI matrix_pow(VVI a,LL n){
  VVI ret(a.size(),VI(a.size(),0));
  for(int i=0;i<a.size();i++)ret[i][i]=1;
  if(n==0)return ret;
  
  VVI  tmp=matrix_pow(a,n/2);
  tmp=matrix_multi(tmp,tmp);
  if(n%2==1)
    tmp=matrix_multi(tmp,a);
  
  return tmp;
}




int  solve() {
  LL W,H,N;
  cin>>W>>H>>N;
  if(W==0 && H==0 && N==0) return -1;
  vector<PII> input;
  for(int i=0; i<N;i++) {
    LL p,q;
    cin>>p>>q;
    input.push_back(MP(q,p));
  }
  sort(input.begin() , input.end());
  
  vector<PII> coor[35];
  LL prev = -1;
  LL iter = -1;
  for(int i=0; i<N; i++) {
    if(prev!=input[i].first) iter++;
    coor[iter].push_back(input[i]);
    
    prev = input[i].first;
  }
  iter++;
  
  VVI base(W,VI(W,0));
  for(int i=0; i<W; i++) 
    for(int j=0; j<W; j++) {
      if(abs(i-j)<=1) base[i][j] = 1;
    } 
  
  VVI state(W,VI(1,0));
  state[0][0] = 1;
  
  LL pos = 1;
  for(int i=0; i<=iter; i++) {
    LL pt;
    if(i<iter) pt = coor[i][0].first;
    else pt = H;
    
    //    cout<<pos<<" "<<pt<<endl;
    state = matrix_multi(matrix_pow(base,pt-pos),state);
    for(int j=0; j<coor[i].size(); j++) {
      state[coor[i][j].second-1][0] = 0;
    } 
    /*
    VVI tmp = matrix_pow(base,pt-pos);
    //    cout<<"ouptut"<<endl;
    for(int j=0; j<W; j++, cout<<endl)
      for(int k=0; k<W; k++) {
	cout<<tmp[j][k]<<" ";
      }
    for(int j=0; j<W; j++) {
      cout<<state[j][0]<<" ";
    }
    cout<<endl;
    */
    pos = pt;
  } 
  
  return state[W-1][0];
  
}

int main() {
  for(int i=1; ; i++){
    int ans = solve();
    if(ans<0) break;
    cout<<"Case "<<i<<": "<<ans<<endl;
    
  }
  
  return 0;
}
