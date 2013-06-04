#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<utility>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int input[100][100];

int parent[100];
int opr[100];
int V;
string node[100];

void makeTree(string s, int v, int pr ) {
  parent[v] = pr;
  //  cout<<s<<" "<<v<<" "<<pr<<endl;
  
  int sz = s.size();
  int cntLevelZero = 0;
  int level = 0;
  int inf = -1;
  int posPlus = inf;
  int plusOpr  = 0;
  int posMult = inf;
  int multOpr = 0;
  
  for(int i=0; i<sz; i++) {
    if(s[i]=='(') {
      level++;
      continue;
    }
    if(s[i]==')') {
      level--;
      continue;
    }
    if(level==0) {
      cntLevelZero++;
      if(s[i]=='+' || s[i]=='-')  {
	posPlus = max(i, posPlus);
	if(s[i]=='-') plusOpr = 1;
      }
      if(s[i]=='*' || s[i]=='/') {
	posMult = max(i, posMult);
	if(s[i]=='*') multOpr = 0;
	if(s[i]=='/') multOpr = 1;
      } 
    }
  }
  //  cout<<plusOpr<<" "<<multOpr<<endl;
  if(posPlus!=inf) {
    opr[v] = plusOpr; // plus
    V+=2;
    int k =V;
    makeTree(s.substr(0,posPlus), k-2, v );
    makeTree(s.substr(posPlus+1, sz-posPlus-1), k-1, v);
    return ;
  }
  if(posMult!=inf) {
    opr[v] = multOpr + 2;
    V+=2;
    int k = V;
    makeTree(s.substr(0,posMult), k-2, v);
    makeTree(s.substr(posMult+1, sz-posMult-1), k-1, v);
    return;
  }
  if(cntLevelZero==0 && s[0]=='(') {
    opr[v] = -1;
    V++;
    makeTree(s.substr(1,sz-2), V-1, v );
    return ;
  }
  node[v] = s;
  
  
}


bool solve() {
  int n,m,p;
  cin>>n>>m>>p;
  if(n==0 && m==0 && p==0) return false;
  map<string, vector<int> > trans;
  vector<string> var;
  vector<vector<int> > deg;
  for(int i=0; i<m; i++) {
    string s;
    cin>>s;
    vector<int> tmp;
    var.push_back(s);
    for(int j=0; j<n; j++) {
      cin>>input[i][j];
      tmp.push_back(input[i][j]);
    }
    trans[s] = tmp;
    deg.push_back(tmp);
  }
  
  string formula;
  cin>>formula;
  map<string,string> mapping;
  for(int i=0; i<p; i++) {
    string s,t;
    cin>>s>>t;
    mapping[s] = t;
  }
    
  
  //  cout<<formula<<endl;
  V = 1;
  for(int i=0; i<100; i++) node[i] = "";
  makeTree(formula,0,-1);
  
  
  vector<int> child[100];
  vector<int> calc[100];
  for(int i=0; i<100; i++) {
    calc[i].resize(n);
    child[i].clear();
  }
  /*
  for(int i=0; i<V; i++) {
    cout<<i<<" "<<node[i]<<" "<<opr[i]<<endl;
    
    }
  */
  bool isError = false;
  for(int i=V-1; i>=0; i--) {
    if(i!=0)
      child[parent[i]].push_back(i);
    if(node[i]!="") {
      string vA = node[i];
      string vB = mapping[vA];
      vector<int> tmp = trans[vB];
      calc[i] = tmp;
    }
    else {
      if(opr[i]==-1)
	calc[i] = calc[child[i][0]];
      
      if(opr[i]==0 || opr[i]==1) {
	if(calc[child[i][0]] != calc[child[i][1]]) {
	  isError = true;
	  //	  cout<<i<<endl;
	}
	calc[i] = calc[child[i][0]];
      }
      if(opr[i]==2 || opr[i]==3) {
	calc[i] = calc[child[i][1]];
	//	cout<<i<<" "<<child[i][0]<<" "<<child[i][1]<<" "<<opr[i]<<endl;
	for(int x=0; x<n; x++) {
	  if(opr[i]==2) calc[i][x] += calc[child[i][0]][x];
	  if(opr[i]==3) calc[i][x] -= calc[child[i][0]][x];
	}
      }
    }
    /*  cout<<"   "<<i<<"  ";
      for(int x=0; x<n; x++)
	cout<<calc[i][x]<<" ";
      cout<<endl;
    */
  }
  if(isError) {
    cout<<"error"<<endl;
    return true;
  }
  string answer = "undefined";
  for(int i=0; i<m; i++) {
    if(calc[0] == deg[i])
      answer = var[i];
    
  }
  cout<<answer<<endl;
  return true;
}

int main() {
  while(true) if(!solve()) break;
  return 0;
  
}
