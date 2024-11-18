// tree implementation using array

#include<stdio.h>
#include<stdlib.h>

#define max 10
int arr[max];
int index = -1;

void init(){
    for(int i=0; i<max; i++){
        arr[i] = -1;
    }
}

// the min element than root should be on left side
// the max element than root should be on right side
void insert(int index,int data){
    if(index >= max){
        return;
    }
    else{
        if(arr[index] <= -1){
            arr[index] = data;
        }
        else if(data<arr[index]){
            // if the data is smaller than root then it will be stored on the left side of the root
            insert((2*index)+1, data);
        }else{
            // if the data is greater than root then it will be stored on the right side of the root
            insert((2*index)+2, data);
        }
    }
}

// we need other create function because index of the element will be given using insert function
void create(int data){
    if(arr[0] == -1){
        // first inserted element will be root
        arr[0] = data;
    }else{
        insert(0, data);
    }
}

void print(){
    for(int i=0; i<max; i++){
        if(arr[i] != -1){
            printf("%d \t", arr[i]);
            int j= 2*i;
            if(((j+1)<max) && (arr[j+1] != -1)){
                printf("%d \t", arr[j+1]);
            }
            if(((j+2)<max)&&(arr[j+2] != -1)){
                printf("%d \t", arr[j+2]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    init();
    create(6);
    create(4);
    create(7);
    create(5);
    create(8);
    create(3);
    print();
    return 0;
}
