#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <stack>
#include<bitset>
using namespace std;

ifstream fin("in.txt");
ofstream fout("euler.out");

int n;

vector<vector<int>> G;
vector<int> L;
vector<pair<int, int>> M;
bitset<500000> elim; //vector de 0 sau 1 

void euler(int start) {
    stack<int> S;
    S.push(start);
    while (!S.empty())
    {
        int k = S.top();
        if (G[k].size())
        {
            int x = G[k].back();
            G[k].pop_back();
            if (!elim[x])
            {
                elim[x] = 1;
                int p = M[x].second;
                if (p == k)
                    p = M[x].first;
                S.push(p);
            }
        }
        else
        {
            L.push_back(k);
            S.pop();
        }

    }

}

int main()
{
    int i, j, m;
    fin >> n>>m;
    G = vector<vector<int>>(n+1);
    for(int k=0;k<m;k++)
    {   
        fin >> i >> j;
        M.push_back({ i,j });
        G[i].push_back(M.size() - 1);
        G[j].push_back(M.size() - 1);
    }
    euler(0);
    for (auto k : L)
       fout << k << " ";
    return 0;
}