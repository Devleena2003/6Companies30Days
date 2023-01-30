class Solution
{
public:
    static bool comparator(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
            mp[words[i]]++;
        vector<pair<string, int>> freq;
        for (auto itr : mp)
            freq.push_back(make_pair(itr.first, itr.second));
        sort(freq.begin(), freq.end(), comparator);
        vector<string> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(freq[i].first);

        return ans;
    }
};