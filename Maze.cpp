#include <bits/stdc++.h>
#define maxN 1001
#define maxResult 10000000
using namespace std;
const int d1[4] = {0, 0, 1, -1};
const int d2[4] = {1, -1, 0, 0};
int a[maxN][maxN];
int f[maxN][maxN];
bool visited[maxN][maxN];
int main(){
  int n, m, x, y;
  queue <pair<int, int> > q;
  cin >> n >> m >> x >> y;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
      f[i][j] = maxResult;
      visited[i][j] = false;
    }
  }
  f[x][y] = 0;
  q.push(make_pair(x, y));
  pair<int, int> temp;
  while (!q.empty()){
    temp = q.front();
    q.pop();
    if(visited[temp.first][temp.second])
      continue;
    visited[temp.first][temp.second] = 1;
    for(int i = 0; i < 4; i++){
      int xx = temp.first + d1[i];
      int yy = temp.second + d2[i];
      
      if((xx == 1 || xx == n || yy == 1 || yy == m) && a[xx][yy]==0 ){
        cout<<f[temp.first][temp.second]+2;
        return 0;
      }
      else{
        if(xx != 1 && xx != n && yy != 1 && yy != m && a[xx][yy]==0 && f[xx][yy] > f[temp.first][temp.second]+1){
          f[xx][yy] = f[temp.first][temp.second]+1;
          q.push(make_pair(xx, yy));
        }
      }
    }
  }
  cout << -1;
  return 0;
}
