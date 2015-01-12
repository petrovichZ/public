#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) a[i] = i;
    copy(a, a+n, ostream_iterator<int>(cout, " "));
    return 0;
}
