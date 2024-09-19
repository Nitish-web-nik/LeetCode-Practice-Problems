class Solution {
public:
    int myAtoi(string s) {

        //Step 1) Handling the issue of Whitespace
        int n = s.length();
        int i = 0;
        int ans = 0;
        int sign = 1;
        while(i < n && s[i]==' ')
        {
            i++;
        }

        //Step  2) Handling the issue of Signedness
        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        //Step 3) Conversion
        while(i<n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            //Handling the issue of overflow
            if(ans > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = ans*10 + digit;
            i++;
        }

        return ans*sign;
    }
};