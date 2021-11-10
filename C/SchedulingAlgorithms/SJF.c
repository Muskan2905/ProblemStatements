//Non-Preemption Mode
//solve for 0 arrival time
#include<stdio.h>
#include<conio.h>

//Implementing SJF ALGORITHM


void implement_SJF(int,int [],int [],int []);

int main(){
    int n,i,arr_time[10],cpu_time[10],process_id[10];
    printf("Enter the number of processes to be executed\n");
    scanf("%d",&n);
    printf("Enter the arrival time for each process\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr_time[i]);
        process_id[i] = i+1;
    }
    printf("Enter CPU burst time for each process\n");
    for(i=0;i<n;i++){
        scanf("%d",&cpu_time[i]);
    }
    printf("Implementing SJF\n");
    implement_SJF(n,arr_time,cpu_time,process_id);
return 0;
}

void implement_SJF(int n, int arr_time[],int cpu_time[],int process_id[]){
int i,j,k,flag,temp,process[10],tt=0,tat[10];
float sum = 0;
//Sorting acc to arr_time[i]

for(i=0;i<n-1;i++){
  flag = 0;
  for(j = 0;j<n-i-1;j++){
    if((arr_time[j] > arr_time[j+1]) && (arr_time[j] != 0 || arr_time[j+1] !=0)){
        temp = arr_time[j];
        arr_time[j] = arr_time[j+1];
        arr_time[j+1] = temp;
        temp = cpu_time[j];
        cpu_time[j] = cpu_time[j+1];
        cpu_time[j+1] = temp;
        temp = process_id[j];
        process_id[j] = process_id[j+1];
        process_id[j+1] = temp;
        flag = 1;
    }
   }
    if(flag == 0)
        break;
}

for(i = 0;i<n-1;i++){
flag = 0;
for(j=0;j<n;j++){
    k = 0;
if(arr_time[j] != 0){
    k = 1;
    break;
}
}
for(;k<n-i-1;k++){
     if(cpu_time[k] > cpu_time[k+1]){
        temp = cpu_time[k];
        cpu_time[k] = cpu_time[k+1];
        cpu_time[k+1] = temp;
        if(arr_time[k] != 0 || arr_time[k+1] !=0){
        temp = arr_time[k];
        arr_time[k] = arr_time[k+1];
        arr_time[k+1] = temp;
        }
        temp = process_id[k];
        process_id[k] = process_id[k+1];
        process_id[k+1] = temp;
        flag = 1;
    }
}
if(flag == 0)
    break;
}

for(i = 0;i<n;i++){
    tt = tt + cpu_time[i];
    process[i] = tt;
    printf("%d\t",process[i]);
}
printf("\n");
//calculate TAT = Termination time - Arrival Time
for(i=0;i<n;i++){
    tat[i] = process[i] - arr_time[i];
    sum = sum + tat[i];
    printf("Turn Around Time of P%d in sequence: %d\n",process_id[i],tat[i]);
  }
  printf("\nAverage Turn Around Time = %f\n",(sum/n));
  //calculate waiting Time = TAT - CPU TIME
  sum = 0;
  for(j=0;j<n;j++){
    int wt = tat[j] - cpu_time[j];
    sum = sum + wt;
    printf("Waiting Time of P%d in sequence: %d\n",process_id[j],wt);
  }
  printf("\nAverage Waiting Time = %f",(sum/n));
 }




