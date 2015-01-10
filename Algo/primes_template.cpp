#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX_VAL_ 300000
// 6bits = 1parity bit + 32 different offsets in the same int
int P_[(MAX_VAL_>>6) + 1]; // negative logic (1 bit marks a non-prime)
// ****** only call this for ODD x greater than 1 *****
inline bool is_prime_fast(int x) { return !((P_[x>>6]>>((x>>1)&0x1f))&1); }
// ****** only call this for ODD x greater than 1 *****
inline void mark_nonprime(int x) { P_[x>>6] |= (1<<((x>>1)&0x1f)); }
inline bool is_prime(int x) { return x==2 ? true : x<2||((x&1)==0) ? false : is_prime_fast(x); }
void init_primes() { for (long long x=3; x*x<=MAX_VAL_; x+=2) if (is_prime_fast(x)) { const long long z = x<<1; for (long long y=x*x; y<=MAX_VAL_; y+=z) mark_nonprime(y); } }

int main() {
    init_primes();

    return 0;
}
