/*First, we sum up the nums to see if it's possible.
If sum doesn't divide by k - return false.
Then, we use typical backtracking to find all possible subsets with each sum = sum / k.
Vector visited will help us check if we used each number exactly once.
In Backtrack function:
k is counting the number of subsets with sum = target. Therefor, if k == 0 we have k subsets and we return true.
If curr_sum == target - we finished filling the current subset - call backtrack again with k = k-1 and curr_sum = 0 for the next subset.
Then, we loop through all numbers.
If we got to a number that we used already - visited[j], or curr_sum + nums[j] > target - continue.
Now, we want to use the current number, so we set visited[j] = true, call backtrack with that number.
If we got a true from backtrack, we're done - return true.
Otherwise - change back visited[j] to false and try the next number.*/

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k)
            return false;

        vector<int> visited(nums.size(), false);
        return backtrack(nums, visited, sum / k, 0, 0, k);
    }

    bool backtrack(vector<int> &nums, vector<int> &visited, int target, int curr_sum, int i, int k)
    {
        if (k == 0)
            return true;

        if (curr_sum == target)
            return backtrack(nums, visited, target, 0, 0, k - 1);

        for (int j = i; j < nums.size(); j++)
        {
            if (visited[j] || curr_sum + nums[j] > target)
                continue;

            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j + 1, k))
                return true;
            visited[j] = false;
        }

        return false;
    }
};