#include<bits/stdc++.h>
using namespace std;

int maxTotalReven(int d, int x[], int revenue[], int n)
{

    int maxTotRev[d+1]; 
    memset(maxTotRev, 0, sizeof(maxTotRev));
    int next_ad = 0; 
    for (int i = 1; i <= d; i++)
    {
        if (next_ad < n) 
        {
            if (x[next_ad] != i)
            {
                maxTotRev[i] = maxTotRev[i-1];
                cout << maxTotRev[i] << endl;
            }
            else
            {
                if (i <= 5)
                {
                    maxTotRev[i] = max(maxTotRev[i-1], revenue[next_ad]);
                    cout << maxTotRev[i] << endl;
                }
                else
                {
                    maxTotRev[i] = max(maxTotRev[i-4]+revenue[next_ad],maxTotRev[i-1]);
                    next_ad++;
                    cout << maxTotRev[i] << endl;
                }
            }
        }
        else
        {
            maxTotRev[i] = maxTotRev[i - 1];
            cout << maxTotRev[i] << endl;
        }
    }
    return maxTotRev[d];
}

int main()
{
    int d = 20;
    int x[] = {6, 7, 12, 14};
    int revenue[] = {5, 6, 5, 1};
    int n = 4;
    maxTotalReven(d, x, revenue, n);
    return 0;
}