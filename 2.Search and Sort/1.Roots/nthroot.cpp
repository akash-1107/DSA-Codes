#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; 
    //for 6 decimal accuracy -7
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
        // cout<<(low)<<" "<<high<<" "<<mid<<endl;
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<" "<<high<<endl; 
    
}
int main() {
	int n=3, m=27; 
	getNthRoot(n, m); 
	return 0;
}
