#include<stdio.h>
#include<conio.h>
int n,i, fe, le;
int a[2][10], t[2][9], e[2], x[2], f1[10], f2[10], l[2][10];
void print_stations()
{
int j,i=le;
printf("\nThe Optimal path is:\n");
for(j=1;j<n;++j)
{
i = l[i-1][j];
                                printf("line %d ", i);
                                printf("station %d ", j);
                                printf("\n");
}
i = le;
printf("line %d ", i);
                printf("station %d ", n);
                printf("\n");
}
void fastest_way()
{
f1[0] = e[0] + a[0][0];
                f2[0] = e[1] + a[1][0];
                int j;
                for(j = 1; j<n; ++j)
                {
                                if( (f1[j-1]+a[0][j]) <= (f2[j-1]+t[1][j-1]+a[0][j]) )
{
f1[j] = f1[j-1] + a[0][j];
l[0][j] = 1;
}
else
{
f1[j] = f2[j-1] + t[1][j-1] + a[0][j];
l[0][j] = 2;
}
if( (f2[j-1]+a[1][j]) <= (f1[j-1]+t[0][j-1]+a[1][j]) )
{
f2[j] = f2[j-1] + a[1][j];
l[1][j] = 2;
}
else
{
f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
l[1][j] = 1;
}
}
if( (f1[n-1] + x[0]) <= (f2[n-1] + x[1]) )
{
fe = f1[n-1] + x[0];
le = 1;
}
else
{
 fe = f2[n-1] + x[1];
le = 2;
}
print_stations();
}
int main()
{
printf("\tAssembly Line Scheduling\n");
printf("Enter the number of nodes: ");
scanf("%d",&n);
printf("Enter the entry values:\n");
for(i=0;i<2;i++)
scanf("%d",&e[i]);
printf("Enter the exit values:\n");
for(i=0;i<2;i++)
scanf("%d",&x[i]);
printf("\nEnter the station times of row/line S1:\n");
for(i=0; i<n; ++i)
scanf("%d", &a[0][i]);
printf("\nEnter the station times of row/line S2:\n");
                for(i=0 ; i<n; ++i)
                                scanf("%d", &a[1][i]);
                printf("\nEnter transaction times from row/line S1:\n");
                for(i=0; i<n-1; ++i)
                                scanf("%d", &t[0][i]);
                printf("\nEnter transaction times from row/line S2:\n");
                for(i=0; i<n-1; ++i)
scanf("%d", &t[1][i]);
                printf("\n");
                fastest_way();
printf("\nOptimal path costs are:\n");
i=1;
printf("For Path[%d] ->\t",i);
for(int j=0;j<n;j++)
printf("S[%d][%d]=%d\t",i,j+1,f1[j]);
printf("Total cost: %d",fe);
printf("\n");
i=2;
printf("For Path[%d] ->\t",i);
for(int j=0;j<n;j++)
printf("S[%d][%d]=%d\t",i,j+1,f2[j]);
fe = f2[n-1] + x[1];
printf("Total cost: %d",fe);
getch();
return 0;
}
