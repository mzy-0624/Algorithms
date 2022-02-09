#include <bits/stdc++.h>
using namespace std;

#define eps 1e-16
class Gauss
{
    int n; // n * (n + 1)
    double **a;
    void swap_line(int x, int y)
    {
        for (int i = 1; i <= n + 1; i++)
            swap(a[x][i], a[y][i]);
    }
    bool Agreater(int k, int x, int y)
    {
        if (fabs(fabs(a[x][k] - fabs(a[y][k]))) > eps)
            return fabs(a[x][k]) > fabs(a[y][k]);
        for (int i = k + 1; i <= n; i++)
            if (fabs(fabs(a[x][i]) - fabs(a[y][i])) > eps)
                return fabs(a[x][i]) < fabs(a[y][i]);
        return 0;
    }
public:
    Gauss(int n)
    {
        this->n = n;
        a = new double *[n + 1];
        for (int i = 0; i <= n; i++)
            a[i] = new double[n + 2];
    }
    void read_data(void)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n + 1; j++)
                cin >> a[i][j];
    }
    void print_ans(void)
    {
        for (int i = 1; i <= n; i++)
        {
            if (fabs(a[i][i]) < eps && fabs(a[i][n + 1]) > eps)
            {
                cout << "There is no solution." << endl;
                return;
            }
            else if (fabs(a[i][i]) < eps && fabs(a[i][n + 1]) < eps)
            {
                cout << "There are infinitely many solutions." << endl;
                return;
            }
        }
        
        for (int i = 1; i <= n; i++)
            cout << a[i][n + 1] << endl;
    }
    void gauss(void)
    {
        for (int i = 1; i <= n; i++)
        {
            int r = i;
            for (int j = i + 1; j <= n; j++)
                if (Agreater(i, j, r))
                    r = j;
            if (r != i)
                swap_line(r, i);
            double k = a[i][i];
            if (fabs(k) < eps)
                continue;
            for (int j = i; j <= n + 1; j++)
                a[i][j] /= k;
            for (int j = i + 1; j <= n; j++)
            {
                double k = a[j][i];
                for (int l = i; l <= n + 1; l++)
                    a[j][l] -= a[i][l] * k;
            }
        }
        for (int i = n; i > 0; i--)
            if (a[i][i])
                for (int j = i - 1; j > 0; j--)
                {
                    a[j][n + 1] -= a[j][i] * a[i][n + 1];
                    a[j][i] = 0;
                }
    }
};
int main(void)
{
    int n;
    scanf("%d", &n);
    Gauss G(n);
    G.read_data();
    G.gauss();
    G.print_ans();
    return 0;
}
