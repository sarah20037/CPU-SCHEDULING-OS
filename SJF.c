#include <stdio.h>

typedef struct
{
    int at, wt, bt, ct, tat, pid;
} process;

int main()
{
    int n;
    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival and burst time for process %d: ", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].ct = 0; // Initialize completion time to 0
    }

    // SJF Non-Preemptive
    int t = 0, completed = 0;
    while (completed < n)
    {
        int min_bt = 9999, index = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].ct == 0 && p[i].bt < min_bt)
            {
                min_bt = p[i].bt;
                index = i;
            }
        }

        if (index != -1)
        {
            t += p[index].bt;
            p[index].ct = t;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            completed++;
        }
        else
        {
            t++;
        }
    }

    // Display
    printf("SJF Non-Preemptive\n\n");
    printf("Process  AT  BT  WT  TAT\n");
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d      %3d %3d %3d %3d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("Average waiting time = %f\n", total_wt / n);
    printf("Average turnaround time = %f\n", total_tat / n);
    return 0;
}
