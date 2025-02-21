#include <iostream>
using namespace std;
typedef long long ll;

const ll LIMIT = 1000000000LL;

// All primes <= 100.
const int primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const int numPrimes = sizeof(primes) / sizeof(primes[0]);

// Recursive function that “includes” or “excludes” primes in order.
// 'idx' is the current index in the primes array.
// 'current' is the current product.
ll dfs(int idx, ll current) {
  // Count the current number.
  ll count = 1;
  for (int i = idx; i < numPrimes; i++) {
    ll prod = current;
    // Multiply by the prime repeatedly (i.e. try prime^1, prime^2, …)
    while (prod <= LIMIT / primes[i]) {
      prod *= primes[i];
      // Recurse with the next prime to avoid duplicate factorizations.
      count += dfs(i + 1, prod);
    }
  }
  return count;
}

int main() {
  // The answer is the total count of generalised Hamming numbers (of type 100)
  // not exceeding 10^9.
  cout << dfs(0, 1) << endl;
  return 0;
}
