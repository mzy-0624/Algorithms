#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
class Simplex {
    int m, n, *id;
    double *para, **matrix;
    int sgn(double x)
    {
        return x < -eps ? -1 : (x > eps ? 1 : 0);
    }
    void pivot(int r, int c)
    {
        swap(id[n + r], id[c]);
        double x = -matrix[r][c];
        matrix[r][c] = -1;
        for (int i = 0; i <= n; i++) 
            matrix[r][i] /= x;
        for (int i = 0; i <= m; i++) 
        {
            if (sgn(matrix[i][c]) && i != r) 
            {
                x = matrix[i][c];
                matrix[i][c] = 0;
                for (int j = 0; j <= n; j++) 
                    matrix[i][j] += x * matrix[r][j];
            }
        }
    }
public:
    Simplex (int m, int n)
    {
        this->m = m;
        this->n = n;
        id = new int[m + n + 1];
        para = new double[n + 1];
        matrix = new double*[m + 1];
        for (int i = 0; i <= m; i++)
            matrix[i] = new double[n + 1];
    }

    int simplex(void)
    {
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= n; j++) 
                matrix[i][j] *= -1;
        for (int i = 1; i <= n; i++) 
            id[i] = i;
        while (true) 
        {
            int x = 0, y = 0;
            for (int i = 1; i <= m; i++) 
                if (sgn(matrix[i][0]) < 0) 
                { 
                    x = i; 
                    break; 
                }
            if (!x) 
                break;
            for (int i = 1; i <= n; i++) 
                if (sgn(matrix[x][i]) > 0) 
                { 
                    y = i; 
                    break; 
                }
            if (!y) 
                return -1;
            pivot(x, y);
        }
        while (true) 
        {
            int x = 0, y = 0;
            for (int i = 1; i <= n; i++) 
                if (sgn(matrix[0][i]) > 0) 
                { 
                    x = i; 
                    break; 
                }
            if (!x) 
                break;
            double w = 0, t = 0; bool f = true;
            for (int i = 1; i <= m; i++) 
            {
                if (sgn(matrix[i][x]) < 0) 
                {
                    t = -matrix[i][0] / matrix[i][x];
                    if (f || t < w) 
                    {
                        w = t;
                        y = i;
                        f = false;
                    }
                }
            }
            if (!y) 
                return 1;
            pivot(y, x);
        }
        for (int i = 1; i <= n; i++) 
            para[i] = 0;
        for (int i = n + 1; i <= n + m; i++) 
            para[id[i]] = matrix[i - n][0];
        return 0;
    }
    void read_data(void)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &para[i]);
            matrix[0][i] = para[i];
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n + 1; j++)
                scanf("%lf", &matrix[i][j % (n + 1)]);
    }
    double getans(void)
    {
        return matrix[0][0];
    }
};
/*
    ******************************** README ********************************
    使用方法：
        将 matrix[0][j] 设置为目标函数的参数，整个函数为
            f = sum_{j = 1}^n(matrix[0][j])
        第 i 个约束条件为
            (sum_{j = 1}^n matrix[i][j]) <= matrix[i][0]
        para[j] 为各个参数的值
        运行 simplex() 的结果若为 -1 则无解，1 则无界，0代表有解（最优解为 matrix[0][0]）
        输入见 read_data() 函数
    ************************************************************************
*/
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    Simplex s(m, n);
    s.read_data();
    if (s.simplex() == 0)
        printf("%.6lf\n", s.getans());
    return 0;
}
