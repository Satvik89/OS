#include <stdio.h>

int main(){
     int n,i,j,at[10],bt[10],wt[10],tat[10],p[10],pos,temp,total,total2;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time of processes: ");
    for(i=0;i<n;i++){
       
            scanf("%d", &at[i]);
            p[i]=i+1;
        
    }
    printf("Enter the burst time of processes: ");
    for(i=0;i<n;i++){
        
            scanf("%d", &bt[i]);
        
    }
    for (i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos]){
                pos=j;
            }
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;

            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
            total += wt[i];
        }
    }
    printf("Process  BT  WT  TAT\n");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total2 +=tat[i]; 
        printf("%d  %d  %d  %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Avg WT : %d",total/n);
    printf("Avg TAT : %d",total2/n);
}