#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> leftMin(n);
    vector<int> stk(n + 1);
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        while (p && nums[stk[p]] <= nums[i])
            p--;
        leftMin[i] = p ? stk[p] : -1;
        stk[++p] = i;
    }
    return 0;
}