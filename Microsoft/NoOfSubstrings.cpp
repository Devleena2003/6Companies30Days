class solution
{
public:
    int numberOfSubstrings(string s)
    {
        int A, B, C = 0;
        // vector<string> v;
        int i, j = 0;
        int n = s.length();
        int count = 0;
        while (i < s.length() && j < s.length())
        {
            if (s[j] == 'a')
                A++;
            else if (s[j] == 'b')
                B++;
            else if (s[j] == 'c')
                C++;
            while (A > 0 && B > 0 && C > 0)
            {
                count = count + n - j;
                if (s[i] == 'a')
                    A--;
                else if (s[i] == 'b')
                    B--;
                else if (s[i] == 'c')
                    C--;
                i++;
            }
            j++;
        }
        return count;
    }
}