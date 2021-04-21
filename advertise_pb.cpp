#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;


//Bottomu-Up Approach
int maxTotalReven(int d, int x[], int revenue[], int n, int maxTotRev[])
{
    ofstream file;
    file.open("advertise_pb_out.txt");
    int next_ad = 0; 
    for (int i = 1; i <= d; i++)
    {
        if (next_ad < n) 
        {
            if (x[next_ad] != i)
            {
                maxTotRev[i] = maxTotRev[i-1];
            }
            else
            {
                if (i <= 5)
                {
                    maxTotRev[i] = max(maxTotRev[i-1], revenue[next_ad]);
                }
                else
                {
                    maxTotRev[i] = max(maxTotRev[i-4]+revenue[next_ad],maxTotRev[i-1]);
                    next_ad++;
                }
            }
        }
        else
        {
            maxTotRev[i] = maxTotRev[i - 1];
        }
        file << maxTotRev[i] << " ";
    }
    file << endl;
    return maxTotRev[d];
}

int main()
{
    int d = 20;
    int x[] = {6, 7, 12, 14};
    int revenue[] = {5, 6, 5, 1};
    int n = 4;
    int maxTotRev[n+1]; 
    memset(maxTotRev, 0, sizeof(maxTotRev));
    maxTotalReven(d, x, revenue, n, maxTotRev);
    return 0;
}