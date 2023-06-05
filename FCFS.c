#include <stdio.h>

int main(){
    int n, i,at[10],bt[10],wt[10],tat[10],ct[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time of processes: ");
    for(i=0;i<n;i++){
       
            scanf("%d", &at[i]);
        
    }
    printf("Enter the burst time of processes: ");
    for(i=0;i<n;i++){
        
            scanf("%d", &bt[i]);
        
    }
    ct[0]=bt[0];
    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for(i=0;i<n;i++){
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

        
}