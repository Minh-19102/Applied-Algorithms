#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;

int n;

int stringToInt(string s) {
  int num = 0;
  for (int j = 0; j < s.length(); j++) {
    num = num * 10 + (int)(s[j] - '0');
  }
  return num;
}
int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    q.push(x);
  }
  string query;
  getline(cin, query);
  while (true) {
    getline(cin, query);
    if (query == "*")
      return 0;
    if (query == "delete-max") {
      cout << q.top() << "\n";
      q.pop();
    } else {
      int num = stringToInt(query.substr(7, query.length() - 7));
      q.push(num);
    }
  }
  return 0;
}
