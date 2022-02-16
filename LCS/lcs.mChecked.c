#include<stdio.h>
#include<string.h>
#pragma CHECKED_SCOPE on
int i;
int j;
int m;
int n;
int c _Checked[20] _Checked[20];
char x _Nt_checked[20];
char y _Nt_checked[20];
char b _Checked[20] _Checked[20];
 
void print(int i,int j)
_Checked {
                if(i==0 || j==0)
                                return;
                if(b[i][j]=='c')
                {
                                print(i-1,j-1);
                                _Unchecked { printf("%c",x[i-1]); };
                }
                else if(b[i][j]=='u')
                                print(i-1,j);
                else
                                print(i,j-1);
}
 
void lcs(void)
_Checked {
                m=strlen(x);
                n=strlen(y);
                for(i=0;i<=m;i++)
                                c[i][0]=0;
                for(i=0;i<=n;i++)
                                c[0][i]=0;
                                
                //c, u and l denotes cross, upward and downward directions respectively
                for(i=1;i<=m;i++)
                                for(j=1;j<=n;j++)
                                {
                                                if(x[i-1]==y[j-1])
                                                {
                                                                c[i][j]=c[i-1][j-1]+1;
                                                                b[i][j]='c';
                                                }
                                                else if(c[i-1][j]>=c[i][j-1])
                                                {
                                                                c[i][j]=c[i-1][j];
                                                                b[i][j]='u';
                                                }
                                                else
                                                {
                                                                c[i][j]=c[i][j-1];
                                                                b[i][j]='l';
                                                }
                                }
}
int main(void)
_Checked {
                _Unchecked { printf("Enter 1st sequence:"); };
                _Unchecked { scanf("%s",x); };
                _Unchecked { printf("Enter 2nd sequence:"); };
                _Unchecked { scanf("%s",y); };
                _Unchecked { printf("\nThe Longest Common Subsequence is "); };
                lcs();
                print(m,n);
return 0;
}