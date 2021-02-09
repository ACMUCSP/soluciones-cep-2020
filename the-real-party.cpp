#include <iostream>
#include <vector>

using namespace std;

vector<int> get_divs(int x){
  vector<int> ans;
  for(int cur = 2; cur * cur <= x; cur++){
    if(x % cur == 0){
      ans.push_back(cur);
      while(x % cur == 0){
        x /= cur;
      }
    }
  }
  if(x > 1){
    ans.push_back(x);
  }
  return ans;
}

int main(){
  int a, b;
  cin >> a >> b;
  vector<int> fa = get_divs(a);
  vector<int> fb = get_divs(b);
  for(int i : fa){
    for(int j : fb){
      if(i != j){
        cout << "Party" << endl;
        cout << i << " " << j <<endl;
        return 0;
      }
    }
  }
  cout << "Sadge" << endl;
}
