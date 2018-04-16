#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct process
{public:
int pid;
int bt;
int wt;
int tat;
int size;
int tstart, tend;
int ticket[100];
void putticket()
{
int j=0;
int i;
for(i=tstart;i<tend;i++)
{ticket[j]=i;
j++;
}
}
void showticket()
{int j=0;
int i;
for( i=tstart;i<tend;i++)
{printf("%d  ",ticket);
j++;
}
}
int searchticket(int q)
{int j=0,c=0,i;
for(i=tstart;i<tend;i++)
{if(ticket[j]==q)
{return 1;
}
j++;
}return 0;
}
};
 int main()
{int n;
int sze,y;
printf("Enter the Number of Processes ");
scanf("%d",&n);
int ts=0,te,i;
struct process p[n],c[n];
for(i=0;i<n;i++)
{printf("Enter the process id for  %d  process ",i+1);
scanf("%d",&p[i].pid);
printf("Enter the Burst Time for %d  process ",i+1);
scanf("%d",&p[i].bt);
c[i].bt=p[i].bt;
p[i].wt=0;
printf("Enter  the ending number of  ticket for %d  process ranging from  %d  to 200  ",i+1,ts);
scanf("%d",&te);
p[i].tstart=ts;
p[i].tend=te;
sze=te-ts;
p[i].size=sze;
p[i].putticket();
ts=te;
}
for(y=0;y<n;y++)
{
printf("Process id for %d  process is %d\n",y+1,p[y].pid);
printf("Burst Time for %d  process is %d \n",y+1,p[y].bt);
printf("Number of tickets %d  process have %d \n",y+1,p[y].size);
printf("Range of tickets for %d process is \n",y+1);
p[y].showticket(); 
printf("\n");

}
int x,l,tslice,k;

printf("Enter the Time Slice ");
scanf("%d",&tslice);

for(k=0;k<15;k++)
{x=(rand()%25);
printf(" The random number generated is %d",x);
for(i=0;i<n;i++)
{

l=p[i].searchticket(x);
if(l==1)
{if(p[i].bt<=0)
{printf("Process with Process id %d is already executed completely \n",p[i].pid);
}
else
{p[i].bt=p[i].bt-tslice;
if(p[i].bt<0)
printf("Remaining burst time for process with process id %d \n",p[i].pid);
else
printf("Remaining burst time for process with process id %d is %d \n",p[i].pid,p[i].bt);
}

}
if(l==0&&p[i].bt>0)
{p[i].wt+=tslice;
}
}
}
for(i=0;i<n;i++)
{printf("Process id for %d process is %d \n",i+1,p[i].pid);
printf("Burst Time for %d process is %d \n",i+1,c[i].bt);
printf("Waiting Time for %d process is %d \n",i+1,p[i].wt);
printf("TurnAround Time for %d process is %d \n",i+1,p[i].tat);

}
}
