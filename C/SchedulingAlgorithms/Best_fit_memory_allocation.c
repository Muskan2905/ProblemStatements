//Best fit Memory allocation algo
#include<stdio.h>
#include<conio.h>

int main(){
int block_size[20],process_size[20],memory_allocated[20],mem_pos[20],process_allocated[20],b,p,i,j,flag,temp;
printf("Enter the no. of memory blocks\n");
scanf("%d",&b);
printf("Enter the size of each memory block\n");
for(i = 0;i<b;i++){
    scanf("%d",&block_size[i]);
    mem_pos[i] = i + 1;
    memory_allocated[i] = 0;
}
//sort the block_size array
//Bubble sorting
for(i=0;i<b-1;i++){
    flag = 0;
    for(j=0;j<b-i-1;j++){
        if(block_size[j] > block_size[j+1]){
            temp = block_size[j];
            block_size[j] = block_size[j+1];
            block_size[j+1] = temp;
            temp = mem_pos[j];
            mem_pos[j] = mem_pos[j+1];
            mem_pos[j+1] = temp;
            flag = 1;
        }
    }
    if(flag == 0){
        break;
    }
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
        printf("Process P%d of size %d is allocated at position %d of memory block of size %d\n",i+1,process_size[i],mem_pos[j],block_size[j]);
    }
    else{
        printf("Process P%d is not allocated\n",i+1);
    }
}
return 0;
}
