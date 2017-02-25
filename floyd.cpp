#include <stdio.h>
#include <string.h>
#define MAX  (100 + 10)
#define INF (1000000 + 10)
int nN, nM;
int nDis[MAX][MAX];
void SearchAll()
{
    for (int k = 0; k < nN; ++k)
    {
        for (int i = 0; i < nN; ++i)
        {
            for (int j = 0; j < nN; ++j)
            {
                if (nDis[i][k] + nDis[k][j] < nDis[i][j])
                {
                    nDis[i][j] = nDis[j][i] = nDis[i][k] + nDis[k][j];
                }
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &nN, &nM) == 2)
    {
        for (int i = 0; i < nN; ++i)
        {
            for (int j = 0; j < nN; ++j)
            {
                if (i == j)
                {
                    nDis[i][j] = 0;
                }
                else
                {
                    nDis[i][j] = INF;
                }
            }
        }
        while (nM--)
        {
            int nX, nY, nK;
            scanf("%d%d%d", &nX, &nY, &nK);
            nDis[nX][nY] = nDis[nY][nX] = nK;
        }
        SearchAll();
        bool bOk = false;
        int nMin = 1 << 30;
        for (int i = 0; i < nN; ++i)
        {
            int nTemp = 0;
            int j = 0;
            for ( ; j < nN; ++j)
            {
                if (i == j) continue;
                if (nDis[i][j] == INF)
                {
                    break;
                }
                else
                {
                    if (nDis[i][j] > nTemp)
                    {
                        nTemp = nDis[i][j];
                    }
                }
            }
            if (j == nN)
            {
                bOk = true;
                if (nTemp < nMin)
                {
                    nMin = nTemp;
                }
            }
        }
        if (bOk)
        {
            printf("%d\n", nMin);
        }
        else
        {
            printf("Can not\n");
        }
    }
    return 0;
}
