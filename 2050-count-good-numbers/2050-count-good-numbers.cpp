#include<cmath>
class Solution {
public:

    long long topower(long long x, long long y)
    {
        long long ans = 1;
        while(y>0)
        {
            if(y%2 == 1)
            {
                ans = (ans * x)%(1000000000+7);
            }
            x = (x*x)%(1000000000+7);
            y/=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {

        long long even = (n+1)/2;
        long long odd = n/2;
        long long actual_ans = (topower(5, even) * topower(4, odd)) % (1000000000 + 7);

    //     long long ans = 1;
    //     long long even = (n+1)/2;
    //     long long odd = n/2;
    //     for(long long i = 0; i < even; ++i)
    //     {
    //         ans = (ans * 5)%(1000000000+7);
    //     }
    //     for(long long i = 0; i < odd; ++i)
    //     {
    //         ans = (ans * 4)%(1000000000+7);
    //     }
            return actual_ans;
    }
};