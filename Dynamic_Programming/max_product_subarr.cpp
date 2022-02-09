#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
/*
 * 如果当前位置是一个负数，我们希望以它前一个位置结尾的某个段的积也是个负数，且这个积尽可能小
 * 如果当前位置是一个正数，我们希望以它前一个位置结尾的某个段的积也是个正数，且这个积尽可能大
 * 维护
 *		fmax(i)：表示以第 i 个元素结尾的乘积最大子数组的乘积
 *		fmin(i)：表示以第 i 个元素结尾的乘积最小子数组的乘积
 * 可以得到这样的动态规划转移方程：
 * 		fmax(i) = max{i: 1->n}(fmax(i - 1) * ai, fmin(i - 1) * ai, ai)
 * 		fmin(i) = min{i: 1->n}(fmax(i - 1) * ai, fmin(i - 1) * ai, ai)
 *
 * 把 ai 加入 i - 1 个元素结尾的乘积最大或最小的子数组的乘积中，和 ai 三者取大，就是 fmax(i)
 * fmin(i) 同理
 * */
int maxProduct(void) 
{
	int maxf = nums[0], minf = nums[0], ans = nums[0];
	for (int i = 1; i < nums.size(); i++) 
	{
		int mx = maxf, mn = minf;
		maxf = max(mx * nums[i], max(nums[i], mn * nums[i]));
		minf = min(mn * nums[i], min(nums[i], mx * nums[i]));
		ans = max(maxf, ans);
	}
	return ans;
}
int main(void)
{
	srand(time(NULL));
	int n;
	cin >> n;
	while (n--)
	{
		int num = (rand() % 10 + 1) * (rand() % 2 ? -1 : 1);
		nums.push_back(num);
	}
	cout << maxProduct() << endl;
	return 0;
}
