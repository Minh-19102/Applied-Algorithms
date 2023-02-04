#include <bits/stdc++.h>
#define maxN 22
using namespace std;
int n, A, B;
int a[maxN];
int eSum[maxN];
int tempSum, result;
int mark[maxN];
void Try(int i) {
  for (int j = 0; j < 2; j++) {
    tempSum += a[i] * j;
    if (i == n && tempSum <= B && tempSum >= A) {
      result++;
    } else if (tempSum <= B && tempSum + (eSum[i] - eSum[n + 1]) >= A)
      Try(i + 1);
    tempSum -= a[i] * j;
  }
}
int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> A >> B;
  tempSum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i > 0; i--) {
    eSum[i] = eSum[i + 1] + a[i];
  }
  Try(1);
  cout << result;
}
