#include <bits/stdc++.h>
using namespace std;
pair<int, int> Binary_search_two(vector<vector<int>> nums, pair<int, int> begin, pair<int, int> end, int target)
{
	// return the position of a point if the value in this point is equal to target, return {-1, -1} if nonexist
	// please make sure that 
	// 	numbers in each row are sorted in ascending from left to right.
	//  numbers in each column are sorted in ascending from top to bottom.
	int row = end.first, col = begin.second;
	while (row >= begin.first && col <= end.second)
    {
		if (nums[row][col] > target)
			row--;
		else if (nums[row][col] < target)
			col++;
		else
			return {row, col};
	}
	return {-1, -1};
}
int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> nums(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		cin >> nums[i][j];
	int target;
	while (cin >> target)
	{
		pair<int, int> p = Binary_search_two(nums, {0, 0}, {m - 1, n - 1}, target);
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
