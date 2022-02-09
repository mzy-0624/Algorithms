#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int LIS_DP(void)	// Longest_Increasing_Subseq		Dynamic_Programming
{
	int n = nums.size(), ans = 1;
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
	return ans;
}
int LIS_BS(void)	// Binary_Search
{
	// d[i] 代表长度为 i 的递增子序列的末尾元素的最小值，易得 d[i] 关于 i 递增
	// 要递增子序列尽可能长，则要每次加入的末尾元素尽可能小
	int ans = 1, n = nums.size();
	vector<int> d(n + 1, 0);
	d[ans] = nums[0];
	// ans 为此时最长递增子序列的长度
	for (int i = 1; i < n; i++) 
	{
		if (nums[i] > d[ans]) 				// 若 nums[i] 比 d[ans] 大，则说明找到了一个更长的子序列，更新 ans 和 数组 d
			d[++ans] = nums[i];
		else 								// 否则，在 d[1] ~ d[ans] 中，找到最大的使得 d[k] < nums[i] 的 k，并更新 d[k + 1] = nums[i]
		{
			int k = lower_bound(d.begin() + 1, d.begin() + ans + 1, nums[i]);
			while (k && nums[i] <= d[k])
				k--;
			d[k + 1] = nums[i];
		}
	}
	return ans;

}
int main(void)
{
	return 0;
}
