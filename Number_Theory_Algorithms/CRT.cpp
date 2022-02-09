#include <bits/stdc++.h>
using namespace std;
int extend_Euclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = extend_Euclid(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
int inverse(int a, int b)
{
     int x, y;
     extend_Euclid(a, b, x, y);
     return (x % b + b) % b;
}
int Chinese_Remainer_Theorem(vector<int> a, vector<int> n, int k) // x \equiv a_i mod n_i
{
    int N = 1, ans = 0;
    for (int i = 0; i < k; i++)
        N *= n[i]; // N = n_1 * n_2 * ... * n_k
    for (int i = 0; i < k; i++)
    {
        int N_i = N / n[i];            // N_i = N / n_i
        int N_i_ = inverse(N_i, n[i]); // N_i * N_i_ \equiv 1 mod n_i
        ans = (ans + a[i] * N_i * N_i_) % N;
    }
    return ans;
}

int main(void)
{
    /*
        x \equiv 2 mod 3
        x \equiv 1 mod 5
        x \equiv 6 mod 7
    */
    vector<int> a = {2, 1, 6};
    vector<int> n = {3, 5, 7};
    int k = 3;
    cout << Chinese_Remainer_Theorem(a, n, k) << endl;
    return 0;
}
