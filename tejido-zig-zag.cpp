#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    if(i % 2 == 0){
      for(int j = 0; j < n; ++j){
        cout << i * n + j + 1 << " ";
      }
    }
    else{
      for(int j = 0; j < n; ++j){
        cout << (i + 1) * n - j << " ";
      }
    }
    cout<<endl;
  }
}
