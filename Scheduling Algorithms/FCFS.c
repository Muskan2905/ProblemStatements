#include<stdio.h>
#include<conio.h>

//Implementing FCFS ALGORITHM


void implement_FCFS(int,int [],int []);

int main(){
    int n,i,arr_time[10],cpu_time[10];
    printf("Enter the number of processes to be executed\n");
    scanf("%d",&n);
    printf("Enter the arrival time for each process\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr_time[i]);
    }
    printf("Enter CPU burst time for each process\n");
    for(i=0;i<n;i++){
        scanf("%d",&cpu_time[i]);
    }
    printf("Implementing FCFS\n");
    implement_FCFS(n,arr_time,cpu_time);
return 0;
}

void implement_FCFS(int n, int arr_time[],int cpu_time[]){
//Process Diagram
int i,j,process[10],tt=0,tat[10],flag,temp;
float sum =0;
//Bubble sorting of arr_time[i] and then corresponding cpu_time[i]
for(i=0;i<n-1;i++){
   flag = 0;
   for(j = 0;j<n-1-i;j++){
    if(arr_time[j] > arr_time[j+1]){
        temp = arr_time[j];
        arr_time[j] = arr_time[j+1];
        arr_time[j+1] = temp;
        temp = cpu_time[j];
        cpu_time[j] = cpu_time[j+1];
        cpu_time[j+1] = temp;
        flag = 1;
    }
   }
    if(flag == 0)
        break;
}
for(i = 0;i<n;i++){
    tt = tt + cpu_time[i];
    process[i] = tt;
}

  //calculate TAT = Termination time - Arrival Time
  for(i=0;i<n;i++){
    tat[i] = process[i] - arr_time[i];
    sum = sum + tat[i];
    printf("Turn Around Time of P%d in sequence: %d\n",i+1,tat[i]);
  }
  printf("\nAverage Turn Around Time = %f\n",(sum/n));
  //calculate waiting Time = TAT - CPU TIME
  sum = 0;
  for(j=0;j<n;j++){
    int wt = tat[j] - cpu_time[j];
    sum = sum + wt;
    printf("Waiting Time of P%d in sequence: %d\n",j+1,wt);
  }
  printf("\nAverage Waiting Time = %f",(sum/n));
}














