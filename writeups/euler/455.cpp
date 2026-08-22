#include <bits/stdc++.h>
using namespace std;

// --- Macros & Type Aliases ---
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<i32, i32>;
using vi = vector<i32>;
// -----------------------------

// --- CRT Struct (From Previous Request) ---
struct CRT {
  i64 res = 0, mod = 1;

  i64 euclid(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) return x = 1, y = 0, a;
    i64 d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
  }

  // Add condition: val % m = a
  bool add(i64 m, i64 a) {
    i64 x, y;
    i64 g = euclid(mod, m, x, y);
    if ((a - res) % g) return false;  // No solution

    i64 m0 = m / g;
    // k = (a - res) / g * inv(mod / g) mod (m / g)
    i128 k = (i128)(a - res) / g * x % m0;

    res += (i64)k * mod;
    mod *= m0;
    res = (res % mod + mod) % mod;
    return true;
  }
};

// --- Math Utilities ---

// Calculate a^b % m safely
i64 binpow(i64 a, i64 b, i64 m) {
  i64 res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (i128)res * a % m;
    a = (i128)a * a % m;
    b >>= 1;
  }
  return res;
}

// Calculate Euler's totient function
i64 get_phi(i64 n) {
  i64 result = n;
  for (i64 i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}

// Calculate a^^inf % m (Power Tower)
// Logic: tower(a, m) = a^(tower(a, phi(m))) % m
// Using property: a^b % m = a^(b % phi(m) + phi(m)) % m (for large b)
i64 tower(i64 a, i64 m) {
  if (m == 1) return 0;
  if (a == 0) return 0; // Assuming 0^0 is handled or a >= 1 usually
  
  i64 ph = get_phi(m);
  i64 exponent = tower(a, ph);
  
  // We add ph to the exponent to ensure we are using the Extended Euler property
  // This simulates that the infinite tower height is definitely >= log_a(m)
  return binpow(a, exponent + ph, m);
}

i64 solve(int a, int m) {

  // Edge case: m=1 -> 0 is a trivial solution if allowed, usually 1^x=x mod 1 -> 0=0
  if (m == 1) {
    return 0;
  }

  i64 ph = get_phi(m);
  
  // Calculate H mod m
  i64 val_mod_m = tower(a, m);
  
  // Calculate H mod phi(m)
  // Note: logical recursion implies tower(a, m) already computes tower(a, phi(m)) internally
  // but we call it explicitly to get the value for the CRT system.
  i64 val_mod_phi = tower(a, ph);

  CRT crt;
  // Condition 1: x = H (mod m)
  if (!crt.add(m, val_mod_m)) {
    return 0;
  }
  // Condition 2: x = H (mod phi(m))
  if (!crt.add(ph, val_mod_phi)) {
    return 0;
  }

  // The smallest non-negative solution
  i64 ans = crt.res;
  
  // If result is 0 and m > 1, usually we want positive x, 
  // but a^0 = 1 != 0 (mod m), so x=0 is invalid unless m=1.
  // However, CRT logic with tower usually yields large enough x.
  // If ans == 0, taking the next solution ans + crt.mod is safer for a^x constraint.
  if (ans == 0) ans += crt.mod;

  ans %= m;
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  i64 ans = 0;
  for(int i = 2; i <= 1e6; ++i) {
    ans += solve(i, 1e9);
  }
  cout << ans;
}
