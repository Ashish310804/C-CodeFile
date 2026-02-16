#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int queue[MAXSIZE],rear=-1,front=0;
int main(){
         int choice;
         do{
            printf("\n--------------QUEUE-----------");
            printf("\n 1.INSERT \n 2.DELETE \n 3.DISPLAY \n 4.EXIT ");
            printf("\n------------------------------");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
                   case 1 : enqueue();
                            break;
                   case 2 : dequeue();
                            break;
                   case 3 : display();
                            break;
                   default : printf("Invalid Choice!");
             }
         }while(choice != 4);
         return 0;
}
void enqueue(){
        int n;
        if(rear==MAXSIZE-1){
                printf("Queue is overflow!");
        }
        else{
            printf("Enter an element");
            scanf("%d",&n);
            rear++;
            queue[rear]=n;
        }
}
void dequeue(){
         int n;
         if(front>rear){
            printf("Queue is empty!");
         }
         else{
            n=queue[front];
            printf("Deleted element is: %d",n);
            front++;
         }
}
void display(){
         int i;
         if(front>rear){
            printf("Queue is empty!");
         }
         else{
            printf("Queue elements");
            for(i=rear;i>=front;i++){
                printf("%d \n",queue[i]);
            }
         }
}
