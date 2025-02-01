#include "algo-ng/testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt();
  for (int i = 0; i < n; ++i) {
    int ja = ouf.readInt();
    int pa = ans.readInt();
    if (ja != pa) quitf(_wa, "expected %d, found %d", ja, pa);
  }
  quitf(_ok, "n = %d, correct answer", n);
}