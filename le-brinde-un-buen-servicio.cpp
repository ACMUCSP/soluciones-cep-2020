#include <iostream>
#include <algorithm>

using namespace std;

const int ms = 1e5 + 5;

int n, a[ms], sum[ms];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  sort(a, a+n);
  int cur = 0, ans = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] >= cur){
      cur += a[i];
      ans++;
    }
  }
  cout << ans << endl;
}
