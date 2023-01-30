/* We can treat the two queues moving to left and right separately because meeting and turning has no cost, or we can think that the one moving left continues moving left after two ants meet, and the one moving right also continues with previous direction.
So the algorithm is :

for the ants moving to the left, find the rightmost one, it is the last to reach index 0 and fall out,
for the ants moving to the right, find the leftmost one, it is the last to reach index n-1 and fall out.*/

int getLastMoment(int n, vector<int> &left, vector<int> &right)
{
    int res = 0;
    if (left.size())
    {
        int t = *max_element(left.begin(), left.end());
        res = t;
    }
    if (right.size())
    {
        int t = *min_element(right.begin(), right.end());
        res = max(res, n - t);
    }

    return res;
}