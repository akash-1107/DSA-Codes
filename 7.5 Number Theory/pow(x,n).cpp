#include <bits/stdc++.h>
using namespace std;
// O(logN) and O(1)
class Solution
{
public:
    double myPow(double x, long long n)
    {
        double res = 1; //store ans
        if (n > 0) //(x^n)
        {
            while (n>0)
            {
                if (n % 2 == 1) //n is odd (x^(n-1))*x krna hoga taki even ho phir n/2 kr ske
                {
                    res = res * x;
                    n--;
                }
                else //n is even (x^n) = ((x*x)^n/2)
                {
                    x = x * x;
                    n /= 2;
                }
            }
        }
        else //(x^(-n))
        {
            n = 0 - n;
            while (n>0)
            {
                if (n % 2 == 1)//n is odd (x^(n-1))*x krna hoga taki even ho phir n/2 kr ske
                {
                    res = res * x;
                    n--;
                }
                else //n is even (x^n) = ((x*x)^n/2)
                {
                    x = x * x;
                    n /= 2;
                }
            }
            res = 1 / res; //simply 1/(x^n)
        }
        return res;
    }
};