#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000005;
const int maxNode = 4 * maxN;
int leftIndex[maxNode];
int rightIndex[maxNode];
int minValue[maxNode];
int arr[maxN];
int updateTree(int id, int left, int right) {
  leftIndex[id] = left;
  rightIndex[id] = right;
  if (left > right) {
    return INT_MAX;
  }
  if (left == right) {
    minValue[id] = arr[left];
    return minValue[id];
  } else {
    minValue[id] = min(updateTree(id * 2, left, (left + right) / 2),
                       updateTree(id * 2 + 1, (left + right) / 2 + 1, right));
    return minValue[id];
  }
}
int RMQ(int id, int l, int r) {
  if (leftIndex[id] > r || rightIndex[id] < l)
    return INT_MAX;
  if (l <= leftIndex[id] && rightIndex[id] <= r)
    return minValue[id];
  return min(RMQ(id * 2, l, r), RMQ(id * 2 + 1, l, r));
}
int main() {
  int n, q, l, r;
  //freopen("RangeMinimumQuery.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  updateTree(1, 0, n - 1);
  cin >> q;
  int result = 0;
  while (q--) {
    cin >> l >> r;
    result += RMQ(1, l, r);
  }
  cout << result;
}
