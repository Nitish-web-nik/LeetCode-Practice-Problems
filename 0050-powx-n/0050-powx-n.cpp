class Solution {
public:
    double myPow(double x, int n) {
        long long m = n; // Use long long to handle the case when n is INT_MIN
        double ans = 1.0;
        
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        
        while (m > 0) {
            if (m % 2 == 1) {
                ans = ans * x;
            }
            x = x * x;
            m = m / 2;
        }
        
        return ans;
    }
};