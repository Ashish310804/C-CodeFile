#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int cqueue[MAXSIZE],rear=-1,front=-1;
int main(){
         int choice;
         do{
            printf("\n--------------CIRCULAR QUEUE-----------");
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
        if((rear+1)%MAXSIZE==front){
                printf("Circular Queue is overflow!");
        }
        else{
            printf("Enter an element :");
            scanf("%d",&n);
            if(rear==-1&&front==-1){
                    rear=0;
                    front=0;
            }
            else{
                    rear=(rear+1)%MAXSIZE;
                    cqueue[rear]=n;
            }
        }
}
void dequeue(){
         int n;
         if(rear==-1&&front==-1){
            printf("Circular Queue is empty!");
         }
         else{
            n=cqueue[front];
            if(front==rear){
                  front=-1;
                  rear=-1;
            }
            else{
                 front=(front+1)%MAXSIZE;
                 printf("Deleted element from Circular Queue is : %d",n);
            }
         }
}
void display(){
         int i;
         if(rear==-1&&front==-1){
            printf("Circular Queue is empty!");
         }
         else{
            printf("Circular Queue elements are:");
            for(i=front;i!=rear;i=((i+1)%MAXSIZE)){
                printf("%5d",cqueue[i]);
            }
            printf("%5d",cqueue[i]);
         }
}
