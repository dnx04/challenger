#line 1 "E_Thief_in_a_Shop.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#line 1 "algo/convolution/fft.hpp"
using cd = complex<double>;

const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd& x : a) x /= n;
  }
}

template <typename T>
vector<T> fftconv(vector<T> const& a, vector<T> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < int(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<T> result(n);
  for (int i = 0; i < n; i++) result[i] = (round(fa[i].real()) > 0);
  return result;
}
#line 8 "E_Thief_in_a_Shop.cpp"

void solve(int ith) {
  const int N = 1001;
  int n, k;
  cin >> n >> k;
  vector<ll> a(N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x] |= 1;
  }
  vector<ll> ans({1});
  while (k) {
    if (k & 1) ans = fftconv(ans, a);
    a = fftconv(a, a), k >>= 1;
  }
  for (int i = 0; i < int(ans.size()); ++i) {
    if (ans[i]) cout << i << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
