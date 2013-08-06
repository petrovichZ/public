#include <iostream>
#include <cstring>

using namespace std;

int n;
int d[10000];

int fib(int n, string s) {
    s += "  ";
    if (d[n] != 0) {
        cout << s << "c: " << n << "\tresult: " << d[n] << endl;
        return d[n];
    }

    cout << s << "b: " << n << endl;
    if(n < 2) {
        d[n] = 1;
        cout << s << "a: " << n << "\tresult: " << d[n] << endl;
        return d[n];
    }
    else {
        d[n] = fib(n - 1, s) + fib(n - 2, s);
        cout << s << "a: " << n << "\tresult: " << d[n] << endl;
        return d[n];
    }
}

int main()
{
   cin >> n; 
   
   fib(n, "");
   
   return 0;
}
