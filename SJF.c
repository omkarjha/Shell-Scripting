// SJF (Shortest Job First) Scheduling with User Input
#include <stdio.h>

void sjf() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_time[n], waiting_time[n], turnaround_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    // Input burst time for each process
    for(int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    // Sort processes based on burst time (Bubble Sort)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(burst_time[j] > burst_time[j+1]) {
                // Swap burst times
                int temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
                
                // Swap process ids
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
    
    waiting_time[0] = 0;
    
    // Calculate waiting time for each process
    for(int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
    
    // Calculate turnaround time for each process
    for(int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], 
               waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    printf("SJF CPU Scheduling Algorithm\n");
    sjf();
    return 0;
}
