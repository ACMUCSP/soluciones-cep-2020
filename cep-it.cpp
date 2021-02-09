#include <iostream>
#include <map>

using namespace std;

int main(){
  int n, m;
  cin >> n;
  map<string, string> alias;
  for(int i = 0; i < n; ++i){
    string a, b;
    cin >> a >> b;
    alias[a] = b;
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    string a, b;
    cin >> a >> b;
    if(alias.count(b)){
      cout << a << " " << alias[b] <<endl;
    }
    else{
      cout << a << " 0.0.0.0" << endl;
    }
  }
}
