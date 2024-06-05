#include <stdio.h>

typedef struct
{
    int at,wt,bt,ct,tat,pid;
}process;

int main()
{
    int n;
    //Input
    printf("Enter number of processes\t");
    printf("\n");
    scanf("%d",&n);
    process p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival and burst time fo process%d\t",i);printf("\n");
        scanf("%d%d",&p[i].at,&p[i].bt);p[i].pid=i;
    }
    //Swapping according to arrival time
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[i].at>p[i+1].at)
            {
                process temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }
    //FCFS
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].at>t)
            t=p[i].at;
        t = t + p[i].bt;
		p[i].tat = t-p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
    }
    //Swapping wrt pid
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[i].pid>p[i+1].pid)
            {
                process temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }
    //Display
    printf("FCFS\n\n");
	printf("Process  AT  BT  WT  TT\n");
	float w=0,k=0;
	for(int i=0;i<n;i++){
		printf("P%d      %3d %3d %3d %3d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);
		k +=p[i].tat;
		w +=p[i].wt;
	}
	w = w/n; k=k/n;
	printf("Average waiting time = %f\n", w);
	printf("Average waiting time = %f\n", k);
    return 0;
}
