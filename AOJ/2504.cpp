#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>


using namespace std;

const int MAXN = 600;

map<string,int> data;
int iterTra = 0;

bool ans[MAXN][2];

vector<int>  graph[MAXN*2];


//事前入力が必要なもの:V,MAX_V

//入力のために使うもの：add_edge()

//入力するもの:G,rG(有向グラフの順向き、逆向き)

//出力：k   強連結成分の個数
//     cmp 点の番号に対して、強連結成分でトポロジカルソートした形
//　　 
//注意:　　add_edgeでは入れられた数の数字に隣接する数がどんどん入れられることになる
//	したがって、1,2,3,と、0が出てこない場合に関しては十分に注意しておくこと。

//その他：SEC(Strongly Connected Component):強連結成分

#define MAX_V 1005
int V;
vector<int>G[MAX_V];
vector<int> rG[MAX_V];
vector<int>vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from,int to){
  if(from==to) return;
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]])dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v,int k){
  used[v]=true;
  cmp[v]=k;
  for(int i=0;i<rG[v].size();i++){
    if(!used[rG[v][i]])rdfs(rG[v][i],k);
  }
}

int sec(){
  //  memset(used,0,sizeof(used));
  for(int i=0; i<MAX_V; i++) used[i] = false;
  vs.clear();
  for(int v=1;v<=V;v++){
    if(!used[v])dfs(v);
  }
  //  memset(used,0,sizeof(used));
  for(int i=0; i<MAX_V; i++) used[i] = false;
  int k=0;
  for(int i=vs.size()-1;i>=0;i--){
    if(!used[vs[i]])rdfs(vs[i],k++);
  }
  return k;
}




int trans(string s) {
  if(data[s]!=0) return data[s];
  iterTra++;
  return data[s] = iterTra;
  
}


void oneNode(string nameA , int k) {
  int x = trans(nameA);
  ans[x][k] = true;
  //  cout<<x<<" "<<k<<endl;
}
void twoNode(string nameA, string nameB, int opr, int b,int c ) {
  int x = trans(nameA);
  int y = trans(nameB);
  
  if(opr==0) {
    ans[x][b] = true;
    ans[y][c] = true;
  }
  /*
  graph[x*2+b^1].push_back(y*2+c);
  graph[y*2+c^1].push_back(x*2+b);
  */
  add_edge(x*2+b^1, y*2+c);
  add_edge(y*2+c^1, x*2+b);
  

  //  cout<<(x*2+b^1)<<" "<<(y*2+c^1)<<endl;
}



bool isAlphabet(char c) {
  if(c>='a' && c<='z' || c>='A' && c<='Z')
    return true;
  return false;

}



void simplify(string s) {
  int n = s.size();
  int level = 0;
  int cnt[MAXN];
  int allcnt = 0;
  for(int i=0; i<MAXN; i++) cnt[i] = 0;
  
  for(int i=0; i<n; i++)
    if(s[i]=='~')
      allcnt ++ ;
  
  int a=0,b=0,c=0;
  int opr = 0;
  for(int i=0; i<n; i++) {
    if(s[i]=='~')
      cnt[level]++;
    if(s[i]=='(') 
      level++;
    if(s[i]==')')
      level--;
    if(s[i]=='&' || s[i]=='|') {
      if(s[i]=='|')
	opr = 1;
      int k = 0;
      for(int x=0; x<level; x++)
	a += cnt[x];
      for(int x=level; x<MAXN; x++)
	b += cnt[x];
      c = allcnt-a-b;
      //      cout<<a<<" "<<b<<" "<<c<<endl;
      a%=2 ,b%=2, c%=2;
      
      break;
    }
  }
  string nameA="", nameB="";
  for(int iter=0; iter<n; iter++) {
    if(isAlphabet(s[iter])) {
      string tmp;
      while(isAlphabet(s[iter])) {
	tmp += s.substr(iter,1);
	iter++;
      }
      if(nameA=="") nameA = tmp;
      else          nameB = tmp; 
    }
  }
  //  cout<<nameA<<" "<<nameB<<" "<<opr<<" "<<a<<" "<<b<<" "<<c<<endl;
  
  if(nameB=="")
    oneNode(nameA, allcnt%2);
  
  if(a==1) {
    b^=1, c^=1, opr^=1;
  }
  twoNode(nameA,nameB, opr,b,c);
  
}


int main() {
  
  for(int i=0; i<MAXN; i++) {
    ans[i][0] = ans[i][1] = false;
  }
  for(int i=0; i<MAXN*2; i++)
    graph[i].clear();

  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    simplify(s);
  }
  bool finalAns = true;
  
  for(int i=0; i<=m; i++){ 
    //    cout<<i<<"   "<<ans[i][0]<<" "<<ans[i][1]<<endl;;
    if(ans[i][0] && ans[i][1])
      finalAns = false;
  }
  V  = 2*m+2;
  sec();  
  vector<int> nums[2*MAXN];
  for(int i=0; i<=V; i++) {
    nums[cmp[i]].push_back(i);
  }
  //  cout<<"final"<<finalAns<<endl;
  for(int x=0; x<2*MAXN; x++) {
    int sz = nums[x].size();
    for(int i=0; i<sz; i++) {
      //    cout<<x<<" "<<nums[x][i]<<endl;
      for(int j=i+1; j<sz; j++ ) {
	int v = nums[x][i];
	int u = nums[x][j];
	//	cout<<v<<" "<<u<<"   "<<ans[v/2][v%2]<<" "<<ans[u/2][(u%2)^1]<<endl;
	if(u==(v^1)) finalAns = false;
	if(ans[v/2][v%2] && ans[u/2][(u%2)^1]) finalAns = false;
      }
    }
  }
  /*
  for(int i=0; i<2*m+2; i++) {
    cout<<i<<":";
    for(int j=0; j<graph[i].size(); j++) cout<<graph[i][j]<<" ";
    cout<<endl;
    }*/
    

  if(finalAns) cout<<"accept"<<endl;
  else cout<<"reject"<<endl;
  
  return 0;
}
