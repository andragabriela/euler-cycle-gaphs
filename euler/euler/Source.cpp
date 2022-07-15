#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("in.txt");
ofstream fout("euler.out");

int n, a[205][205], L[50000], p;

void Euler(int k)
{
    for (int i = 0; i < n; i++)
        if (a[k][i] == 1)
        {
            a[k][i] = a[i][k] = 0;
            Euler(i);
        }
    L[++p] = k;
}

int main()
{
    int i, j;
    fin >> n;
    while (fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }
    Euler(0);
    for (int i = 1; i <= p; i++)
            fout << L[i] << " ";
    return 0;
}