#include<bits/stdc++.h>

using namespace std;
 
int getC (char aChar) {
    switch (aChar) {
         case '1': return 1;
         case '2': return 2;
         case '3': return 3;
         case '4': return 4;
         case '5': return 5;
         case '6': return 6;
         case '7': return 7;
         case '8': return 8;
         case '9': return 9;
         default:  return 0;
                   break;
    }
}
 
int main ()
{
    string input;
    int testcaseNb = 0;
    int n;
    int digits[26];
    int sum[26];
    int dp[26][26];
    while (true)
    {
          cin >> input;
          if (input == "bye") break;
           
          testcaseNb++;
          n = input.length ();
          for (int i = 1; i <= n; i++)
              for (int j = 1; j <= n; j++)
                  dp[i][j] = 0;
          dp[1][1] = 1;
          digits[0] = 0;
          sum[0] = 0;
          for (int i = 1; i <= n; i++)
          {
              digits[i] = getC(input[i-1]);
              sum[i] = sum[i-1] + digits[i];
          }  
           
          for (int i = 2; i <= n; i++)
              for (int j = 1; j <= i; j++)
              {
                  int prev = sum[i] - sum[i-j];
                  int tempSum = 0;
                  for (int k = 1; k <= i-j; k++)
                  {
                      tempSum = tempSum + digits[i-j-k+1];
                      if (tempSum > prev) break;
                      dp[i][j] += dp[i-j][k];
                  }
                  if (j == i)
                     dp[i][j] = 1;
              }
           
         int finalRs = 0;
          for (int i = 1; i <= n; i++)
              finalRs += dp[n][i];
          cout << testcaseNb << ". " << finalRs << "\n";
    }
}