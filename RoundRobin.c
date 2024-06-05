#include <stdio.h>

typedef struct
{
    int at, wt, bt, ct, tat, pid, rt;
} process;

int main()
{
    int n, quantum;
    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].rt = p[i].bt; // Initialize remaining time to burst time
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int t = 0, completed = 0;
    while (completed < n)
    {
        int executed = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].rt > 0)
            {
                if (p[i].rt > quantum)
                {
                    t += quantum;
                    p[i].rt -= quantum;
                }
                else
                {
                    t += p[i].rt;
                    p[i].ct = t;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    p[i].rt = 0;
                    completed++;
                }
                executed = 1;
            }
        }
        if (!executed)
        {
            t++;
        }
    }

    // Display
    printf("Round Robin Scheduling\n\n");
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
