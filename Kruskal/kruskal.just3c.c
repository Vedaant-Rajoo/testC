#include<stdio.h>
 
#define MAX 30
 
typedef struct edge
{
int u,v,w;
}edge;
 
typedef struct edgelist
{
edge data _Checked[MAX];
int n;
}edgelist;
 
edgelist elist;
 
int G _Checked[MAX] _Checked[MAX];
int n;
edgelist spanlist;
 
void kruskal();
int find(_Array_ptr<int> belongs : count(30), int vertexno);
void union1(_Array_ptr<int> belongs : count(30), int c1, int c2);
void sort();
void print();
 
int main()
{
int i,j,total_cost;
printf("\nEnter number of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
kruskal();
print();
}
 
void kruskal()
{
int belongs _Checked[MAX];
int i;
int j;
int cno1;
int cno2;
elist.n=0;
 
for(i=1;i<n;i++)
for(j=0;j<i;j++)
_Checked {
if(G[i][j]!=0)
{
elist.data[elist.n].u=i;
elist.data[elist.n].v=j;
elist.data[elist.n].w=G[i][j];
elist.n++;
}
}
 
sort();
for(i=0;i<n;i++)
belongs[i]=i;
spanlist.n=0;
for(i=0;i<elist.n;i++)
_Checked {
cno1=find(belongs,elist.data[i].u);
cno2=find(belongs,elist.data[i].v);
if(cno1!=cno2)
{
spanlist.data[spanlist.n]=elist.data[i];
spanlist.n=spanlist.n+1;
union1(belongs,cno1,cno2);
}
}
}
 
int find(_Array_ptr<int> belongs : count(30), int vertexno)
_Checked {
return(belongs[vertexno]);
}
 
void union1(_Array_ptr<int> belongs : count(30), int c1, int c2)
_Checked {
int i;
for(i=0;i<n;i++)
if(belongs[i]==c2)
belongs[i]=c1;
}
 
void sort()
_Checked {
int i,j;
edge temp;
for(i=1;i<elist.n;i++)
for(j=0;j<elist.n-1;j++)
if(elist.data[j].w>elist.data[j+1].w)
{
temp=elist.data[j];
elist.data[j]=elist.data[j+1];
elist.data[j+1]=temp;
}
}
 
void print()
_Checked {
int i,cost=0;
for(i=0;i<spanlist.n;i++)
{
_Unchecked { printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w); };
cost=cost+spanlist.data[i].w;
}
 
_Unchecked { printf("\n\nCost of the spanning tree=%d",cost); };
}