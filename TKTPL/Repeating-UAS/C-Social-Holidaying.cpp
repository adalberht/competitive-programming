/*
 * Albertus Angga Raharja
 * 1606918401
 * 
 * C - Social Holidaying
 * Solved using Edmond's Blossom algorithm (classical)
 * 
 * Credits:
 * ImproveBySubmission Cheatsheet
 * (Same cheatsheet as Ahmad Hasan Siregar and Kautsar Fadlillah)
 *
*/
#include <bits/stdc++.h>

using namespace std;

int lca(vector<int>&match, vector<int>&base, vector<int>&p,int a,int b){
  vector<bool> used(match.size());
  while(true){
    a = base[a];
    used[a]=true;
    if(match[a]==-1)break;
    a = p[match[a]];
  }
  while(true){
    b = base[b];
    if(used[b])return b;
    b = p[match[b]];
  }
  return-1;
}
 
void markPath(vector<int>&match, vector<int>&base, vector<bool>&blossom, vector<int>&p,int v,int b,int children){
  for(; base[v]!= b; v = p[match[v]]){
    blossom[base[v]]= blossom[base[match[v]]]=true;
    p[v]= children;
    children = match[v];
  }
}
 
int findPath(vector<vector<int>>&graph, vector<int>&match, vector<int>&p,int root){
  int n = graph.size();
  vector<bool> used(n);
  for (auto it = p.begin(); it != p.end(); ++it) *it =-1;
  vector<int> base(n);
  for(int i =0; i < n;++i) base[i]= i;
 
  used[root]=true;
  int qh =0;
  int qt =0;
  vector<int> q(n);
  q[qt++]= root;
  while(qh < qt){
    int v = q[qh++];
    for (auto it = graph[v].begin(); it != graph[v].end(); ++it){
      int to =*it;
      if(base[v]== base[to]|| match[v]== to)continue;
      if(to == root || match[to]!=-1&& p[match[to]]!=-1){
        int curbase = lca(match, base, p, v, to);
        vector<bool> blossom(n);
        markPath(match, base, blossom, p, v, curbase, to);
        markPath(match, base, blossom, p, to, curbase, v);
        for(int i =0; i < n;++i){
          if(blossom[base[i]]){
            base[i]= curbase;
            if(!used[i]){
              used[i]=true;
              q[qt++]= i;
            }
          }
        }
      }else if(p[to]==-1){
        p[to]= v;
        if(match[to]==-1)return to;
        to = match[to];
        used[to]=true;
        q[qt++]= to;
      }
    }
  }
  return-1;
}
 
int maxMatching(vector<vector<int>> graph){
  int n = graph.size();
  vector<int> match(n,-1);
  vector<int> p(n);
  for(int i =0; i < n;++i){
    if(match[i]==-1){
      int v = findPath(graph, match, p, i);
      while(v !=-1){
        int pv = p[v];
        int ppv = match[pv];
        match[v]= pv;
        match[pv]= v;
        v = ppv;
      }
    }
  }
 
  int matches = 0;
  for(int i = 0; i < n;++i){
    if(match[i]!=-1){
      ++matches;
    }
  }
  return matches/2;
}

vector<vector<int>> adj;
int val[500];
int n, m;

int main() {
  int TC;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> TC;
  while (TC--) {
    cin >> n >> m;
    memset(val, 0, sizeof(val));
    adj.clear();
    adj.resize(n+1);

    for (int i = 1; i <= n; ++i) {
      cin >> val[i];
    }
    set<int> s;
    s.clear();
    int sz;

    for (int j = 1; j <= m; ++j) {
      cin >> sz;
      s.insert(sz);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (s.find(val[i] + val[j]) != s.end()) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    cout << maxMatching(adj) << endl;
  }
}