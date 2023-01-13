class Solution
{
public:
    int findIntegers(int n)
    {
        int ones = helper(n);
        return n - ones + 1;
    }
    int helper(int n)
    {
        double pow = Math.log(n) / Math.log(2);
        if (pow == (int)pow)
            return dp[(int)pow];
        pow = Math.floor(pow);
        int ans = dp[(int)pow];
        int lowestNumber = 1 << (int)pow;
        int left = n - lowestNumber;
        if (left >= lowestNumber / 2)
            ans += dp[(int)pow - 1] + (left - lowestNumber / 2 + 1);
        else
            ans += helper(left);
    }
    static
    {
        dp = new int[33];
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < 33; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + val;
            val = val << 1;
        }
    }
}