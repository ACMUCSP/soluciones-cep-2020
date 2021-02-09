#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  vector<string> v;
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int words = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Horizontal derecha
      if (j <= n - x) {
        string tmp;
        for (int k = j; k < j + x; k++) {
          tmp.push_back(v[i][k]);
        }
        if (tmp == s) {
          words++;
          for (int k = j; k < j + x; k++) {
            ans[i][k]++;
          }
        }
      }
      // Horizontal izquierda
      if (j >= x - 1) {
        string tmp;
        int limite = j - (x - 1);
        for (int k = j; k >= limite; k--) {
          tmp.push_back(v[i][k]);
        }
        if (tmp == s) {
          words++;
          for (int k = j; k >= limite; k--) {
            ans[i][k]++;
          }
        }
      }
      // Abajo
      if (i <= n - x) {
        string tmp;
        for (int k = i; k < i + x; k++) {
          tmp.push_back(v[k][j]);
        }
        if (tmp == s) {
          words++;
          for (int k = i; k < i + x; k++) {
            ans[k][j]++;
          }
        }
      }
      // Arriba
      if (i >= x - 1) {
        string tmp;
        int limite = (i - (x - 1));
        for (int k = i; k >= limite; k--) {
          tmp.push_back(v[k][j]);
        }
        if (tmp == s) {
          words++;
          for (int k = i; k >= limite; k--) {
            ans[k][j]++;
          }
        }
      }
      // Diagonal arriba derecha
      if (i >= x - 1 and j <= n - x) {
        string tmp;
        int limite1 = (i - (x - 1));
        int limite2 = j + x - 1;
        for (int k = i, l = j; k >= limite1 and l <= limite2; k--, l++) {
          tmp.push_back(v[k][l]);
        }
        if (tmp == s) {
          words++;
          for (int k = i, l = j; k >= limite1 and l <= limite2; k--, l++) {
            ans[k][l]++;
          }
        }
      }
      // Diagonal arriba izquierda
      if (i >= x - 1 and j >= x - 1) {
        string tmp;
        int limite1 = (i - (x - 1));
        int limite2 = j - (x - 1);
        for (int k = i, l = j; k >= limite1 and l >= limite2; k--, l--) {
          tmp.push_back(v[k][l]);
        }
        if (tmp == s) {
          words++;
          for (int k = i, l = j; k >= limite1 and l >= limite2; k--, l--) {
            ans[k][l]++;
          }
        }
      }
      // Diagonal abajo derecha
      if (x > 1 and i <= n - x and j <= n - x) {
        string tmp;
        int limite1 = i + (x - 1);
        int limite2 = j + (x - 1);
        for (int k = i, l = j; k <= limite1 and l <= limite2; k++, l++) {
          tmp.push_back(v[k][l]);
        }
        if (tmp == s) {
          words++;
          for (int k = i, l = j; k <= limite1 and l <= limite2; k++, l++) {
            ans[k][l]++;
          }
        }
      }
      // Diagonal abajo izquierda
      if (i <= n - x and j >= x - 1) {
        string tmp;
        int limite1 = i + (x - 1);
        int limite2 = j - (x - 1);
        for (int k = i, l = j; k <= limite1 and l >= limite2; k++, l--) {
          tmp.push_back(v[k][l]);
        }
        if (tmp == s) {
          words++;
          for (int k = i, l = j; k <= limite1 and l >= limite2; k++, l--) {
            ans[k][l]++;
          }
        }
      }
    }
  }
  int max_ = -1;
  for (int i = 0; i < n; i++) {
    int tmp = *max_element(ans[i].begin(), ans[i].end());
    max_ = max(max_, tmp);
  }
  words -= max_;
  cout << words << endl;
}
