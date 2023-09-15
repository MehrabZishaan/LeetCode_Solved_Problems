// https://leetcode.com/problems/perfect-squares/
class Solution
{
public:
    int perfectSquaresUtil(int n, vector<int>& memo)
    {
        if (n == 0)
            return 0;
        if (memo[n] != -1)
            return memo[n];

        int minnum = INT_MAX;
        for (int i=1; i*i<= n; ++i)
        {
            minnum = min(minnum, perfectSquaresUtil(n - i*i, memo) + 1);
        }

        memo[n] = minnum;
        return minnum;
    }


    int numSquares(int n)
    {
        vector<int> memo(n+1, -1);
        return perfectSquaresUtil(n, memo);
    }
};