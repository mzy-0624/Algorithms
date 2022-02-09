/* Triple, which is either three same numbers or three continuous number. For example (1, 1, 1) or (1, 2, 3).
 * What we are going to do is find there are How many triples can these n numbers form at most
 * For example (2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 7, 7, 7, 8, 9, 9, 10, 10)
 * Can form 5 triples at most: (2, 2, 2), (3, 3, 3), (4, 4, 4), (7, 7, 7), (8, 9, 10)
 * */
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> T;
int dp[2][3][3] = { 0 };
vector<int> nums;
int n, m = 0;
int main(void)
{
	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	int pre = 1, cur = 0;
	for (int i = 1; i < n; i++)
	{
		cur = pre + (nums[i] != nums[i - 1]) + (nums[i] - nums[i - 1] > 1);
		m = max(m, pre);
		T[pre]++;
		pre = cur;
	}
	m = max(m, cur);
	T[cur]++;
	memset(dp[0], 0xff, sizeof(dp[0]));
	dp[0][0][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(dp[i & 1], 0xff, sizeof(dp[i & 1]));
		for (int j = 0; j <= 2; j++)
			for (int k = 0; k <= 2; k++)
				for (int l = 0; l <= 2; l++)
					if (j + k + l > T[i])
						break;
					else
						dp[i & 1][k][l] = max(dp[!(i & 1)][j][k] + l + (T[i] - j - k - l) / 3, dp[i & 1][k][l]);
	}
	cout << dp[m & 1][0][0] << endl;
	return 0;
}
