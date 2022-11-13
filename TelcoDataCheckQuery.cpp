#include <bits/stdc++.h>
using namespace std;

map<int, int> call_from;
map<int, int> call_count_from;

int calculate_call_duration(string start, string end) {
  return 3600 * (stoi(end.substr(0, 2)) - stoi(start.substr(0, 2))) +
         60 * (stoi(end.substr(3, 2)) - stoi(start.substr(3, 2))) +
         (stoi(end.substr(6, 2)) - stoi(start.substr(6, 2)));
}

int main() {
  freopen("TelcoDataCheckQuery.in", "r", stdin);
  int call_count = 0;
  int mode = 0;
  int allNumberCorrect = 1;
  while (true) {
    string tmp;
    getline(cin, tmp);
    if (mode == 0) {
      if (tmp == "#")
        mode = 1;
      else {
        int j = 0;
        int start = 0, end = 0;
        string data[6];
        for (end = 0; end < tmp.length(); end++) {
          if (tmp[end] == ' ') {
            data[j++] = tmp.substr(start, end - start);
            start = end + 1;
          }
        }
        data[j] = tmp.substr(start, end - start);
        if (data[1].length() != 10 || data[2].length() != 10)
          allNumberCorrect = 0;
        else {
          call_count_from[stoi(data[1])] +=
              calculate_call_duration(data[4], data[5]);
        }
        call_count++;
        call_from[stoi(data[1])]++;
      }
    } else {
      int j = 0;
      int start = 0, end = 0;
      string data[2];
      for (end = 0; end < tmp.length(); end++) {
        if (tmp[end] == ' ') {
          data[j++] = tmp.substr(start, end - start);
          start = end + 1;
        }
      }
      data[j] = tmp.substr(start, end - start);
      if (data[0].compare("?check_phone_number") == 0) {
        printf("%d\n", allNumberCorrect);
      } else if (data[0].compare("?number_calls_from") == 0) {
        printf("%d\n", call_from[stoi(data[1])]);
      } else if (data[0].compare("?number_total_calls") == 0) {
        printf("%d\n", call_count);
      } else if (data[0].compare("?count_time_calls_from") == 0) {
        printf("%d\n", call_count_from[stoi(data[1])]);
      } else
        break;
    }
  }
}
