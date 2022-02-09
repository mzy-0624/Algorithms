#include <bits/stdc++.h>
using namespace std;
class Manacher {
public:
    int expand(const string & s, int left, int right) 
	{
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
		{
            left--;
            right++;
        }
        return (right - left - 2) / 2;
    }
    string longestPalindrome(string s) 
	{
        int start = 0, end = -1;
        string t = "#";
        for (char c : s) 
		{
            t += c;
            t += '#';
        }
        t += '#';
        s = t;
        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); i++) 
		{
            int cur_arm_len;
            if (right >= i) 
			{
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } 
			else
                cur_arm_len = expand(s, i, i);
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) 
			{
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) 
			{
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }
        string ans;
        for (int i = start; i <= end; i++) 
            if (s[i] != '#')
                ans += s[i];
        return ans;
    }
};

string max_palindrome_substr(string s)
{
	int n = s.size(), len = 1, begin = 0;
	if (n < 2)
		return s;
	vector<vector<bool>> dp(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	for (int l = 2; l <= n; l++)
		for (int i = 0; i < n - l + 1; i++)
		{
			int j = l + i - 1;
			dp[i][j] = (s[i] == s[j]) && (l < 4 || dp[i + 1][j - 1]);
			if (dp[i][j] && l > len)
			{
				len = l;
				begin = i;
			}
		}
	return s.substr(begin, len);
}

int main(void)
{
	string s;
	while (cin >> s)
		cout << max_palindrome_substr(s) << endl;
	return 0;
}
