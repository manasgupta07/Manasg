#include<stdio.h>
int main()
{
int i,j,n,time,rem,fg=0,time_qt;
int wt_time=0,td_time=0,at[10],bt[10],rt[10];
printf("Enter Total Process:\t ");
scanf("%d",&n);
rem=n;
for(i=0;i<n;i++)
{
printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
scanf("%d",&at[i]);
scanf("%d",&bt[i]);
rt[i]=bt[i];
}

printf("Enter Time Quantum:\t");
scanf("%d",&time_qt);
printf("\n\nProcess\t| Turnaround Time |  Waiting Time\n\n");
for(time=0,i=0;rem!=0;)
{
if(rt[i]<=time_qt && rt[i]>0)
	{
	time+=rt[i];	
	rt[i]=0;
	fg=1;
	}
else if(rt[i]>0)
	{
	rt[i]-=time_qt;
	time+=time_qt;
	}
if(rt[i]==0 && fg==1)
	{
	rem--;
	printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
	wt_time+=time-at[i]-bt[i];
	td_time+=time-at[i];
	fg=0;
	}
if(i==n-1)
	i=0;
else if(at[i+1]<=time)
	i++;
else
	i=0;
}
printf("\nAverage Waiting Time= %f\n",wt_time*1.0/n);
printf("Avg Turnaround Time = %f",td_time*1.0/n);
return 0;
}
