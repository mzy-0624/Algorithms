#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    int m, n;

public:
	// 按照题意，可能会修改 matrix 的数据类型为 long long，并在相关操作取模
    int **matrix;
    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;
        matrix = new int *[m + 1];
        for (int i = 0; i <= m + 1; i++)
            matrix[i] = new int[n + 1];
    }
    Matrix operator*(const Matrix &that)
    {
        int m_ = this->m, n_ = that.n;
        assert(this->n == that.m);
        Matrix matrix(m_, n_);
        for (int i = 1; i <= m_; i++)
            for (int j = 1; j <= n_; j++)
                matrix.matrix[i][j] = 0;
        for (int i = 1; i <= m_; i++)
            for (int j = 1; j <= n_; j++)
                for (int k = 1; k <= this->n; k++)
                    matrix.matrix[i][j] += (this->matrix[i][k] * that.matrix[k][j]);
        return matrix;
    }
    Matrix operator+(const Matrix &that)
    {
        assert(this->m == that.m && this->n == that.n);
        Matrix matrix(this->m, this->n);
        for (int i = 1; i <= this->m; i++)
            for (int j = 1; j <= this->n; j++)
                matrix.matrix[i][j] = this->matrix[i][j] + that.matrix[i][j];
        return matrix;
    }
    Matrix operator-(const Matrix &that)
    {
        assert(this->m == that.m && this->n == that.n);
        Matrix matrix(this->m, this->n);
        for (int i = 1; i <= this->m; i++)
            for (int j = 1; j <= this->n; j++)
                matrix.matrix[i][j] = this->matrix[i][j] - that.matrix[i][j];
        return matrix;
    }
    Matrix Pow(Matrix A, int b) 
    {
        int s = A.m;
        assert(A.m == A.n);
        Matrix matrix(A.m, A.n);
        for (int i = 1; i <= s; i++)
            for (int j = 1; j <= s; j++)
                matrix.matrix[i][j] = (i == j);
        while (b)
        {
            if (b & 1)
                matrix = matrix * A;
            A = A * A;
            b >>= 1;
        }
        return matrix;
    }
};

int main(void)
{
    int m, n;
    cin >> m >> n; // m * n
    Matrix matrix(m, n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix.matrix[i][j];
    matrix = matrix + matrix;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << matrix.matrix[i][j] << " ";
        cout << endl;
    }
    // 其他操作，略
    return 0;
}
