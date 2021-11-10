//First Fit Memory allocation algo

#include<stdio.h>
#include<conio.h>

int main(){
int block_size[20],process_size[20],memory_allocated[20],process_allocated[20],b,p,i,j;
printf("Enter the no. of memory blocks\n");
scanf("%d",&b);
printf("Enter the size of each memory block\n");
for(i = 0;i<b;i++){
    scanf("%d",&block_size[i]);
    memory_allocated[i] = 0;
}
printf("Enter the no. of processes\n");
scanf("%d",&p);
printf("Enter the size of each process\n");
for(i = 0;i<p;i++){
    printf("Process P%d = ",i+1);
    scanf("%d",&process_size[i]);
    process_allocated[i] = 0;
}
for(i = 0;i<p;i++){
    for(j = 0;j<b;j++){
        if((memory_allocated[j] == 0) && (block_size[j] >= process_size[i])){
            process_allocated[i] = 1;
            memory_allocated[j] = 1;
            break;
        }
    }
    if(process_allocated[i] == 1){
        printf("Process P%d of size %d is allocated at position %d of memory block of size %d\n",i+1,process_size[i],j+1,block_size[j]);
    }
    else{
        printf("Process P%d is not allocated\n",i+1);
    }
}
return 0;
}
