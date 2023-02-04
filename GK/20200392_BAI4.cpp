#include <bits/stdc++.h>
#define maxN 100005
using namespace std;
int n;
int a[maxN];
int f[maxN];
int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1] = a[1];
  f[2] = a[2];
  f[3] = a[1] + a[3];
  for (int i = 4; i <= n; i++) {
    f[i] = a[i] + max(f[i - 2], f[i - 3]);
  }
  cout << max(f[n], f[n - 1]);
}
