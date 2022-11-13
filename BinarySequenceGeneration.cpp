#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int x = 0; x < 1 << n; x++) {
    for (int i = n - 1; i >= 0; i--) {
      cout << ((x >> i) & 1);
    }
    cout << '\n';
  }
}
