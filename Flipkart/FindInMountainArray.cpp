class solution
{
public:
    int findMountainArray(int target, MountainArray A)
    {
        int n = A.length(), l, r, m, peak = 0;
        l = 0;
        r = n - 1;
        while (l < r)
        {
            m = (l + r) / 2;
            if (A.get(m) < A.get(m + 1))
                l = peak = m + 1;
            else
                r = m;
        }
        // in the left side of mountain
        l = 0;
        r = peak;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (A.get(m) < target)
                l = m + 1;
            else if (A.get(m) > target)
                r = m - 1;
            else
                return m;
        }
        // in the right side of mountain
        l = peak;
        r = n - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (A.get(m) > target)
                l = m + 1;
            else if (A.get(m) < target)
                r = m - 1;
            else
                return m;
        }
        return -1;
    }
}