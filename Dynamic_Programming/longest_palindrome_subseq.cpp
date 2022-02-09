#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max_palindrome_subseq(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	/* ababa	n = 5
	 * dp[0][0] = 1   dp[1][1] = 1   dp[2][2] = 1   dp[3][3] = 1   dp[4][4] = 1
	 *     "a"            "b"            "a"            "b"            "a"
	 * */
	for (int n - 1; i >= 0; i--0) 		// i from n - 1 downto 0 not i from 0 to n - 1
		for (int j = i + 1; j < n; j++)
			dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
	/*
	 * "ba"		dp[3][4] = max(dp[4][4], dp[3][3]) = 1		"b" / "a"
	 * "ab"		dp[2][3] = max(dp[3][3], dp[2][2]) = 1		"a" / "b"
	 * "aba"	dp[2][4] = dp[3][3] + 2 = 3					"aba"
	 * "ba"		dp[1][2] = max(dp[2][2], dp[1][1]) = 1		"b" / "a"
	 * "bab"	dp[1][3] = dp[2][2] + 2 = 3					"bab"
	 * "baba"	dp[1][4] = max(dp[2][4], dp[1][3]) = 3		"aba" / "bab"
	 * "ab"		dp[0][1] = max(dp[1][1], dp[0][0]) = 1		"a" / "b"
	 * "aba"	dp[0][2] = dp[1][1] + 2 = 3					"aba"
	 * "abab"	dp[0][3] = max(dp[1][3], dp[0][2]) = 3		"bab" / "aba"
	 * "ababa"	dp[0][4] = dp[1][3] + 2 = 5					"ababa"
	 * */
	return dp[0][n - 1];
}
int main(void)
{
	string s;
	while (cin >> s)
		cout << max_palindrome_subseq(s) << endl;
	return 0;
}
