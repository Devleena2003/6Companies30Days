class Solution
{
public:
    string customSortString(string order, string str)
    {
        map<char, int> mp;
        string ans = "";
        for (auto x : str)
        {
            mp[x]++;

            // a->1
            // b->1
            // c->1
            // d->1
        }
        for (auto x : order)
        {
            // traversing order string
            if (mp.find(x) != mp.end())
            {
                // if we find any element of order in map
                auto temp = mp.find(x);
                int count = temp->second; // count it
                // c=5 means ccccc
                string s(count, x);
                ans += s;
                mp.erase(x); // delete it from map after storing it in ans;
            }
        }

        // for remaining words which are not into order but in map
        for (auto x : mp)
        {
            string s(x.second, x.first);
            ans += s;
        }
        return ans;
    }
}