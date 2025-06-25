#include <bits/stdc++.h>
using namespace std;

static const long long N = 1000000000000000000LL;  // 10^18
static const long long K = 1000000000LL;           // 10^9

bool is_prime(int x) {
  if (x < 2) return false;
  if (!(x % 2) && x != 2) return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return false;
  return true;
}

vector<int> get_primes(int low, int high) {
  vector<int> v;
  for (int x = low + 1; x < high; x++) {
    if (is_prime(x)) v.push_back(x);
  }
  return v;
}

long long pow_mod(long long base, long long exp, long long m) {
  long long res = 1 % m;
  base %= m;
  while (exp > 0) {
    if (exp & 1) res = (__int128)res * base % m;
    base = (__int128)base * base % m;
    exp >>= 1;
  }
  return res;
}

long long inv_mod(long long a, long long m) { return pow_mod(a, m - 2, m); }

long long nCk_mod_p(long long n, long long k, long long p) {
  // Lucas + factorial precomputation
  static vector<long long> fact, invf;
  static long long lastP = 0;
  if (p != lastP) {
    fact.resize(p);
    invf.resize(p);
    fact[0] = 1;
    for (int i = 1; i < (int)p; i++) fact[i] = (fact[i - 1] * i) % p;
    invf[p - 1] = inv_mod(fact[p - 1], p);
    for (int i = p - 2; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % p;
    lastP = p;
  }
  long long res = 1;
  while (n > 0 || k > 0) {
    long long nn = n % p, kk = k % p;
    if (kk > nn) return 0;
    res = (res * ((fact[nn] * invf[kk]) % p) * invf[nn - kk]) % p;
    n /= p;
    k /= p;
  }
  return res;
}

long long CRT3(long long a1, long long a2, long long a3, long long m1,
               long long m2, long long m3) {
  long long M = m1 * m2 * m3;
  long long M1 = m2 * m3, M2 = m1 * m3, M3 = m1 * m2;
  long long y1 = inv_mod(M1 % m1, m1);
  long long y2 = inv_mod(M2 % m2, m2);
  long long y3 = inv_mod(M3 % m3, m3);
  __int128 r = 0;
  r += (__int128)a1 * M1 % M * y1 % M;
  r += (__int128)a2 * M2 % M * y2 % M;
  r += (__int128)a3 * M3 % M * y3 % M;
  r %= M;
  return (long long)r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> primes = get_primes(1000, 5000);
  vector<long long> val(primes.size());
  for (int i = 0; i < (int)primes.size(); i++) {
    val[i] = nCk_mod_p(N, K, primes[i]);
  }
  __int128 ans = 0;
  for (int i = 0; i < (int)primes.size(); i++) {
    for (int j = i + 1; j < (int)primes.size(); j++) {
      for (int k = j + 1; k < (int)primes.size(); k++) {
        long long x =
            CRT3(val[i], val[j], val[k], primes[i], primes[j], primes[k]);
        ans += x;
      }
    }
  }
  cout << (long long)(ans) << "\n";
  return 0;
}
