#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
#define mid(l, r)	((l + r) / 2)
class Solution1 {
public:
	int max_crossing_subarr(int l, int m, int h)
	{
		int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
		for (int i = m; i >= l; i--)
		{
			sum += nums[i];
			left_sum = max(left_sum, sum);
		}
		sum = 0;
		for (int i = m + 1; i <= h; i++)
		{
			sum += nums[i];
			right_sum = max(right_sum, sum);
		}
		return left_sum + right_sum;
	}
	int max_subarr(int l, int h)
	{
		if (h == l)
			return nums[l];
		else
			return max(max(max_subarr(l, mid(l, h)), max_subarr(mid(l, h) + 1, h)), max_crossing_subarr(l, mid(l, h), h));
	}
	int maxSubArray(void)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max_subarr(0, n - 1);
    }
};
class Solution2 {
public:
    int maxSubArray(void)
	{
        int pre = 0, ans = nums[0];
        for (auto & x : nums) 
		{
            pre = max(pre + x, x);
            ans = max(ans, pre);
        }
        return ans;
    }
};
int main(void)
{
	srand(time(NULL));
	int T = 100;
	Solution1 s1;
	Solution2 s2;
	Solution3 s3;
	while (T--)
	{
		nums.clear();
		int n = rand() % 1000 + 100;
		while (n--)
		{
			int num = rand() % 1000000;
			nums.push_back(num);
		}
		int ans1 = s1.maxSubArray();
		int ans2 = s2.maxSubArray();
		int ans3 = s3.maxSubArray();
		if (ans1 != ans2 || ans1 != ans3 || ans2 != ans3)
			cout << "\033[0;31mWA\033[0m\n";
		else
			cout << "\033[0;32mAC\033[0m\n";
	}
	return 0;
}
