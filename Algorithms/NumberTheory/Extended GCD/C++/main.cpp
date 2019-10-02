/**
 * @author: Pham T. Nhan    
 * @Date:   10/2/2019
**/

#include <bits/stdc++.h>

using namespace std;

// Find GCD of a and b
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Finds such x and y, that a * x + b * y = gcd(a, b)
long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long a, b, x, y;

int main()
{
    cin >> a >> b;
    long long g = extended_gcd(a, b, x, y);
    printf("x = %ld, y = %ld", x, y);
}