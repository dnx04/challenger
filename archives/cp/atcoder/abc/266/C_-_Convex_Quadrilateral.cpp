#include <bits/stdc++.h>

using namespace std;

int CrossProduct(vector<vector<int>>& A) {
  int X1 = (A[1][0] - A[0][0]);
  int Y1 = (A[1][1] - A[0][1]);
  int X2 = (A[2][0] - A[0][0]);
  int Y2 = (A[2][1] - A[0][1]);
  return (X1 * Y2 - Y1 * X2);
}

bool isConvex(vector<vector<int>>& points) {
  int N = points.size();
  int prev = 0;
  int curr = 0;
  for (int i = 0; i < N; i++) {
    vector<vector<int>> temp = {points[i], points[(i + 1) % N],
                                points[(i + 2) % N]};
    curr = CrossProduct(temp);
    if (curr != 0) {
      if (curr * prev < 0) {
        return false;
      } else {
        prev = curr;
      }
    }
  }
  return true;
}

int main() {
  vector<int> a(2), b(2), c(2), d(2);
  cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
  auto polygon = vector<vector<int>>({a, b, c, d});
  if (isConvex(polygon)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}