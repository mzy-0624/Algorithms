#include <bits/stdc++.h>
using namespace std;
int Lower_bound(vector<int> nums, int begin, int end, int target)
{
	// return the first number in vector which is >= target. return -1 if nonexist
	// please make sure the vector is sorted from small to large
	if (begin > end || nums[end] < target)
		return -1;
	int l = begin, r = end;
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (nums[m] >= target)
			r = m;
		else
			l = m + 1;
	}
	return l;
}
int Upper_bound(vector<int> nums, int begin, int end, int target)
{
	// return the first number in vector which is greater than target. return -1 if nonexist
	if (begin > end || nums[end] <= target)
		return -1;
	int l = begin, r = end;
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (nums[m] > target)
			r = m;
		else
			l = m + 1;
	}
	return l;
}
bool Binary_search_one(vector<int> nums, int begin, int end, int target)
{
	// return true if exist a number in vector which is equal to target
	int pos = Lower_bound(nums, begin, end, target);
	return (pos != -1 && nums[pos] == target);
}
int main(void)
{
	vector<int> nums;
	int num;
	while (cin >> num)
	{
		if (num == -1)
			break;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	for (auto & i : nums)
		cout << i << " ";
	cout << endl;
	int target;
	while (cin >> target)
		cout << Binary_search_one(nums, 0, nums.size() - 1, target) << endl;
	return 0;
}
