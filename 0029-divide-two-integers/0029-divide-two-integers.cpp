class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow cases
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        if(dividend == divisor)
            return 1;
        int sign = 1;;
        if(dividend >=0 && divisor <=0)
            sign = -1;
        if(dividend <=0 && divisor >=0)
            sign = -1;
        long n = abs(dividend);
        long d = abs(divisor);
        long ans = 0;

        while(n>=d)
        {
            int count = 0;
            while(n>=(d<<(count+1)))
            {
                count++;
            }   
            ans += (1<<count);
            n -= (d*(1<<count));
            
        }
        return sign * ans;

        
    }
};