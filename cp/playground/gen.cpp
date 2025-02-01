#include "algo-ng/testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100);
    cout << rnd.next(1, n) << endl;
}