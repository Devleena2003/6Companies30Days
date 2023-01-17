class solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {

        // sieve approach to find the prime numbers
        vector<int> check(1e6 + 1, 0);
        vector<int> prime;
        for (int i = 2; i <= 1e6; i++)
        {
            if (check[i] == 0)
                prime.push_back(i);
            for (int j = i; j <= 1e6; j += i)
            {
                check[j]++;
            }
        }

        // after finding the range of prime numbers we have to find  pair of minimum difference
        int mini = INT_MAX;
        int a = -1, b = -1;
        for (int i = 0; i + 1 < prime.size(); i++)
        {
            if (prime[i] >= left && prime[i + 1] <= right)
            {
                if (prime[i + 1] - prime[i] < mini)
                {
                    mini = prime[i + 1] - prime[i];
                    a = prime[i];
                    b = prime[i + 1];
                }
            }
        }
        return {a, b};
    }
}