#include <stdio.h>
#include <stdlib.h>
 
 #pragma CHECKED_SCOPE on
int max(int a, int b) _Checked{ return (a > b)? a : b; }
// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt _Checked[]:count(n), int val _Checked[]:count(n), int n)
{
   int i, w;
    _Array_ptr<int> K : count((n+1)*(W+1)) = malloc<int>((n+1)*(W+1)*sizeof(int));
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i*W+w] = 0;
           else if (wt[i-1] <= w)
                 K[i*W+w] = max(val[i-1] + K[(i-1)*W+(w-wt[i-1])],  K[(i-1)*W+w]);
           else
                 K[i*W+w] = K[(i-1)*W+w];
       }
   }
 
   return K[n*W+W];
}
 
int main(void)
{
    int val _Checked[] = {60, 100, 120};
    int wt _Checked[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    _Unchecked{
    printf("\nValue = %d", knapsack(W, wt, val, n));
}
    return 0;
}