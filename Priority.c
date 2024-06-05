#include <stdio.h>

typedef struct
{
    int at, wt, bt, ct, tat, pid,priority;
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
        printf("Enter arrival time,burst time,priority for process %d: ", i);
        scanf("%d%d%d", &p[i].at, &p[i].bt,&p[i].priority);
        p[i].pid = i;
        p[i].ct = 0; // Initialize completion time to 0
    }

    // Priority
    int t = 0, completed = 0;
    while (completed < n)
    {
        int min = 9999, index = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].ct == 0 && p[i].priority < min)
            {
                min = p[i].priority;
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
    printf("Priority\n\n");
    printf("Process  AT  BT  WT  TAT\n");
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d      %3d %3d %3d %3d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turnaround time = %.2f\n", total_tat / n);
    return 0;
}
