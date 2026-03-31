#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*
 Expected format (based on typical deque problems in this series):
 - First line: integer q — number of operations
 - Next q lines: commands among
   push_front x, push_back x, pop_front, pop_back,
   front, back, size, clear, empty
 Output:
 - For operations that return value (pop_*, front, back) print value or "error" if empty
 - For size print integer
 - For empty print "true"/"false"
 This mirrors common judge for deque interactive tasks.
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  deque<long long> dq;
  int q;
  if (!(cin >> q)) {
    // If unspecified, read until EOF processing commands
    cin.clear();
    q = -1; // unknown count
  }
  string cmd;
  long long x;
  auto proc = [&](const string &c)->bool{
    if (c == "push_front") {
      if (!(cin >> x)) return false;
      dq.push_front(x);
      cout << "ok\n";
    } else if (c == "push_back") {
      if (!(cin >> x)) return false;
      dq.push_back(x);
      cout << "ok\n";
    } else if (c == "pop_front") {
      if (dq.empty()) cout << "error\n";
      else { cout << dq.front() << "\n"; dq.pop_front(); }
    } else if (c == "pop_back") {
      if (dq.empty()) cout << "error\n";
      else { cout << dq.back() << "\n"; dq.pop_back(); }
    } else if (c == "front") {
      if (dq.empty()) cout << "error\n";
      else cout << dq.front() << "\n";
    } else if (c == "back") {
      if (dq.empty()) cout << "error\n";
      else cout << dq.back() << "\n";
    } else if (c == "size") {
      cout << dq.size() << "\n";
    } else if (c == "clear") {
      dq.clear();
      cout << "ok\n";
    } else if (c == "empty") {
      cout << (dq.empty() ? "true" : "false") << "\n";
    } else if (c == "exit") {
      cout << "bye\n";
      return false; // signal to stop
    } else if (c == "print") {
      // debug helper: print space-separated elements
      for (size_t i = 0; i < dq.size(); ++i) {
        if (i) cout << ' ';
        cout << dq[i];
      }
      cout << "\n";
    } else {
      // Unknown command; attempt to consume rest of line
      string rest;
      getline(cin, rest);
    }
    return true;
  };

  if (q >= 0) {
    for (int i = 0; i < q; ++i) {
      if (!(cin >> cmd)) break;
      if (!proc(cmd)) break;
    }
  } else {
    while (cin >> cmd) if (!proc(cmd)) break;
  }

  return 0;
}
