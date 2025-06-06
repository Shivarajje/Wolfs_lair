/*
ALGORITHM:
STEP 01: START
STEP 02: Inside the structure declare the variable pid, atime, btime, wtime, ttime
STEP 03: Declare the variable i, n as integer, totwtime and totttime as 0
STEP 04: Set the value of n and assign pid as its value and get the value of p[i].btime
STEP 05: Sort the processes based on burst time
STEP 06: Assign p[0].wtime as 0 and p[0].ttime as p[0].btime. Inside the loop calculate the waiting time and turnaround time of each
STEP 07: Calculate the average waiting time and average turnaround time
         - Average Waiting Time = Total Waiting Time / no of processes
         - Average Turnaround Time = Total Turnaround Time / no of processes
STEP 08: Print the Gaant Chart, Total Waiting Time, Average Waiting Time, Total Turnaround Time, Average Turnaround Time
STEP 09: STOP
*/
//CODE:
#include <stdio.h>
#include <stdlib.h>

struct sjf
{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

void main()
{
    int i, j, n, temp, tempid;
    int totwtime = 0, totttime = 0;
    printf("In SJF Scheduling....\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].btime > p[j].btime)
            {
                temp = p[i].btime;
                p[i].btime = p[j].btime;
                p[j].btime = temp;
                tempid = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = tempid;
            }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    for (i = 0; i < n; i++)
    {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    printf("\nGantt Chart:\n");
    printf("Process\t|Burst Time\t|Waiting Time\t|Turnaround Time|\n");
    for (i = 0; i < n; i++)
        printf("%d\t|%d\t\t|%d\t\t|%d\t\t|\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    printf("\nTotal Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %.2f\n", (float)totwtime / n);
    printf("Total Turnaround Time: %d\n", totttime);
    printf("Average Turnaround Time: %.2f\n", (float)totttime / n);
}
/*
OUTPUT:
In SJF Scheduling....
Enter the number of processes: 3
Enter the burst time for process 1: 3
Enter the burst time for process 2: 27
Enter the burst time for process 3: 3

Gantt Chart:
Process |Burst Time     |Waiting Time   |Turnaround Time|
1       |3              |0              |3              |
3       |3              |3              |6              |
2       |27             |6              |33             |

Total Waiting Time: 9
Average Waiting Time: 3.00
Total Turnaround Time: 42
Average Turnaround Time: 14.00
*/