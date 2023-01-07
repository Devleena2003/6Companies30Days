class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {

        int n = nums.size();

        unordered_map<int, int> m;

        //  store the no. of subsequence ending with nums[i]

        unordered_map<int, int> m1;

        // store the frequency of each element in count map

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        // iterate over the nums array

        for (int i = 0; i < n; i++)
        {
            // if nums[i] is already included

            if (m[nums[i]] == 0)
                continue;

            // decrement the frequency of curr element

            m[nums[i]]--;

            // 1st check can we include in existing subsequence

            if (m[nums[i] - 1] > 0)
            {
                m1[nums[i] - 1]--;

                m1[nums[i]]++;
            }

            // 2nd check can we form a new subsequence starting with nums[i] and ending with nums[i] + 2

            else if (m[nums[i] + 1] && m[nums[i] + 2])
            {
                m[nums[i] + 1]--;

                m[nums[i] + 2]--;

                m1[nums[i] + 2]++;
            }

            // otherwise return false

            else
                return false;
        }

        return true;
    }
};