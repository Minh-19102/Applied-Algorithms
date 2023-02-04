#include <bits/stdc++.h>
#define maxN 100005
using namespace std;

int n, m, k;
int a[maxN], tSum[maxN];
int result;
int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tSum[i] = tSum[i - 1] + a[i];
  }
  for (int i = k; i <= n; i++) {
    if (tSum[i] - tSum[i - k] == m)
      result++;
  }
  cout << result;
}
