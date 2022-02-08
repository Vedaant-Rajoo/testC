#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) _Checked { return (a > b)? a : b; }
// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, _Array_ptr<int> wt : count(n), _Array_ptr<int> val : count(n), int n)
_Checked {
   int i, w;
   typedef _Array_ptr<int> inResult;// = malloc <int>((n+1)*sizeof(int));
_Array_ptr<inResult> K : count((n+1)*(W+1)) = malloc<int>((n+1)*(W+1) *sizeof(int));
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
_Checked {
    int val _Checked[] = {60, 100, 120};
    int wt _Checked[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    _Unchecked { printf("\nValue = %d", knapsack(W, wt, val, n)); };
    return 0;
}