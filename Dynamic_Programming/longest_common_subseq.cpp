#include <bits/stdc++.h>
using namespace std;
int LCS(string& s1, string& s2)
{
	vector<vector<int>> dp(s1.size(), vector<int> (s2.size()));
	function<int(int, int)> DP = [&] (int i, int j) {
		if (i < 0 || j < 0)
			return 0;
		return dp[i][j];
	};
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
			if (s1[i] == s2[j])
				dp[i][j] = DP(i - 1, j - 1) + 1;
			else
				dp[i][j] = max(DP(i, j - 1), DP(i - 1, j));
	return dp[s1.size() - 1][s2.size() - 1];
}
int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << LCS(s1, s2) << endl;
	return 0;
}
