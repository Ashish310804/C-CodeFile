#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10                //macros
int stack[MAXSIZE],top=-1;
int main(){
         int choice;
         do{
            printf("\n--------------stack-----------");
            printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT ");
            printf("\n------------------------------");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
                   case 1 : push();
                            break;
                   case 2 : pop();
                            break;
                   case 3 : display();
                            break;
                   default : printf("Invalid Choice!");
             }
         }while(choice != 4);
         return 0;
}
void push(){
           int n , number ,i;
           if(top==MAXSIZE - 1){
                printf("\n Stack is overflow");
           }
           else{
                printf("Enter no. of element you want to push:");
                scanf("%d",&number);
                for ( i=1 ; i<=number ; i++){
                printf("\n Enter an element:");
                scanf("%d",&n);
                top++;
                stack[top]=n;
                }
           }
}
void display(){
           int i;
           if (top== -1){
               printf("\n Stack is empty");
           }
           else{
               printf("Elements in an stack are:");
               for (i=top ; i>=0 ; i--){
                   printf("\n %d",stack[i]);
               }
           }
}
void pop(){
           int n;
           if (top== -1){
               printf("\n Stack is empty");
           }
           else{
                n=stack[top];
                top--;
                printf("\n Poped element is %d",n);
           }
}
