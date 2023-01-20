/* One thing we can observe that, in the question it is mentioned that we need to check if every binary code of length k is a substring of s, so we actually don't need to generate all codes and check if it matches rather we can just check all the substrings of length k in the string s, If number of all the distinct substrings of length k is 2^k. then it's for sure that all the binary codes exits in the distinct substrings.*/

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        if (k > s.size())
            return false;

        unordered_set<string> set;

        for (int i = 0; i <= s.size() - k; i++)
            set.insert(s.substr(i, k));

        return set.size() == pow(2, k);
    }
};
