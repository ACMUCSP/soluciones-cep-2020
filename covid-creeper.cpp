#include <iostream>
#include <vector>

using namespace std;

const int ms = 100005;

int n, m, vis[ms];
vector<int> edges[ms];

void dfs(int u){
  vis[u] = true;
  for(int e : edges[u]){
    if(!vis[e]) dfs(e);
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int a,b;
    cin>>a>>b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(!vis[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans << endl;
}
