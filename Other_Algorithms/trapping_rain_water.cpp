#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> height;
int n;
class trapSolutions {
public:
	int trap1(void)			// Dynamic Programming
	{
		/*
		 * vector<int> lmax(n), rmax(n)
		 * lmax[0] = height[0], rmax[n - 1] = height[n - 1]
		 * ans = sum_{0 <= i < n} min(lmax[i], rmax[n]) - height[i]
		 * lmax, rmax	==> vector<int> dp(n)
		 * */
		vector<int> dp(n);
		dp[0] = height[0];
		for (int i = 1; i < n; i++)
			dp[i] = max(dp[i - 1], height[i]);
		dp[n - 1] = min(dp[n - 1], height[n - 1]);
		for (int i = n - 2; i >= 0; i--)
			dp[i] = min(dp[i], max(dp[i + 1], height[i]));
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += dp[i] - height[i];
		return ans;
	}
	int trap2(void)			// Monotonous stack
	{
		/*
		 * 单调栈中存储的是下标，满足从栈底到栈顶的下标对应的数组 height 中的元素递减。
		 * 从左到右遍历数组，遍历到下标 i 时
		 * 如果栈内至少有两个元素，记栈顶元素为 top，top 的下面一个元素是 left，则一定有 
		 * 						height[left] >= height[top]
		 * 如果 height[i] > height[top]，则得到一个可以接雨水的区域
		 * 区域宽 i − left − 1，高 min(⁡heigh[left], height[i]) − heighttop]，由此计算出接水量。
		 * 为了得到 left，需要将 top 出栈。
		 * 在对 top 计算能接的雨水量之后，left 变成新的 top
		 * 重复上述操作，直到栈变为空，或者栈顶下标对应的 height 中的元素大于或等于 height[i]。
		 * 在对 i 处计算接的雨水量后，将 i 入栈继续遍历计算雨水量。遍历结束后可得到接的雨水总量。
		 * */
		int ans = 0;
		stack<int> stk;
		for (int i = 0; i < n; i++)
		{
			while (!stk.empty() && height[i] > height[stk.top()])
			{
				int top = stk.top();
				stk.pop();
				if (stk.empty())
					break;
				int l = stk.top(), w = i - l - 1, h = min(height[l], height[i]) - height[top];
				ans += w * h;
			}
			stk.push(i);
		}
		return ans;
	}
	int trap3(void)			// double points
	{
		int ans = 0, l = 0, r = n - 1, lm = 0, rm = 0;
		while (l < r)
		{
			lm = max(lm, height[l]);
			rm = max(rm, height[r]);
			if (height[l] < height[r])
			{
				ans += lm - height[l];
				l++;
			}
			else
			{
				ans += rm - height[r];
				r--;
			}
		}
		return ans;
	}
};
int main(void)
{
	freopen("data.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		height.push_back(h);
	}
	trapSolutions s;
	cout << s.trap1() << " " << s.trap2() << endl;
	return 0;
}
