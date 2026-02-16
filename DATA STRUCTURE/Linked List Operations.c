#include<stdio.h>
#include<conio.h>
struct node{
         int data;
         struct node *next;
}*head=NULL , *temp ,  *new1 , *prev , *after;
void main(){
           int choice;
           do{
              printf("\n ---------Linked List Menu---------");
              printf("\n 1.Create");
              printf("\n 2.Display");
              printf("\n 3.Insert First");
              printf("\n 4.Insert Middle");
              printf("\n 5.Insert Last");
              printf("\n 6.Delete First");
              printf("\n 7.Delete Middle");
              printf("\n 8.Delete Last");
              printf("\n 9.Count Nodes");
              printf("\n 10.Exit");
              printf("\n ------------------------------------");
              printf("\n Enter your choice:");
              scanf("%d",&choice);
              switch(choice){
                       case 1: create();
                               break;
                       case 2: display();
                               break;
                       case 3: insert_first();
                               break;
                       case 4: insert_middle();
                               break;
                       case 5: insert_last();
                               break;
                       case 6: delete_first();
                               break;
                       case 7: delete_first();
                               break;
                       case 8: delete_last();
                               break;
                       case 9: countnode();
                               break;
                       default: printf("\n Invalid Choice");
              }
           }while(choice!=10);

}
create(){
           int n;
           char ch;
           printf("\n Enter an element:");
           scanf("%d",&n);
           head = (struct node *)(malloc(sizeof(struct node)));
           head -> data = n;
           head -> next = NULL;
           temp=head;
           printf("\n Want to continue?");
           ch=getche();
           while (ch=='Y' || ch=='y'){
                        printf("\n Enter next element:");
                        scanf("%d",&n);
                        new1=(struct node *)(malloc(sizeof(struct node)));
                        new1 -> data = n;
                        new1 -> next = NULL;
                        temp -> next = new1;
                        temp = temp -> next;
                        printf("\n Want to continue?");
                        ch=getch();
           }

}
display(){
            if (head==NULL){
                printf("\n List not found");
            }
            else{
                temp=head;
                while (temp!=NULL){
                    printf("\n %d \t",temp -> data);
                    temp = temp -> next;
                }
            }
}
insert_first(){
          int n;
          if (head==NULL){
                   printf("list not found");
          }
          else{
                   printf("\n Enter new element for insert");
                   scanf("%d",&n);
                   new1=(struct node*)(malloc(sizeof(struct node)));
                   new1 -> data = n;
                   new1 -> next = NULL;
                   head = new1;
          }
}
insert_middle(){
          int n , pos , i=1 ;
          if (head==NULL){
                   printf("\n list not found");
          }
          else{
                   printf("\n Enter element for insertion:");
                   scanf("%d",&n);
                   new1 = (struct node *)(malloc(sizeof(struct node)));
                   new1 -> data = n;
                   new1 -> next = NULL;
                   printf("\n Enter the position you want to insert:");
                   scanf("%d",&pos);
                   after = head;
                   while (i<pos){
                            prev = after;
                            after = after -> next;
                            i++;
                   }
                   prev -> next = new1;
                   new1 -> next = after;
            }
}
insert_last(){
          int n;
          if (head==NULL){
                   printf("\n list not found");
          }
          else{
                   printf("\n Enter new element for insert");
                   scanf("%d",&n);
                   new1=(struct node*)(malloc(sizeof(struct node)));
                   new1 -> data = n;
                   new1 -> next = NULL;
                   temp = head;
                   while (temp -> next != NULL){
                                  temp = temp -> next;
                   }
                   temp -> next = new1;
          }
}
delete_first(){
          int n ;
          if (head==NULL){
                   printf("\n list not found");
          }
          else{
                   temp = head;
                   head = head -> next;
                   printf("\n deleted node is : %d", temp -> data);
                   free(temp);
           }
}
delete_middle(){
          int n , pos , i=1 ;
          if (head==NULL){
                   printf("\n list not found");
          }
          else{
                   printf("\n Enter the postion:");
                   scanf("%d",pos);
                   temp = head;
                   while (i<pos){
                           prev = temp;
                           temp = temp -> next;
                           i++;
                   }
                   after = temp -> next;
                   prev -> next = after;
                   printf("\n Deleted data is: %d", temp -> data);
                   free(temp);
          }
 }
 delete_last(){
          int n ;
          if (head==NULL){
                   printf("\n list not found");
          }
          else{
                   temp = head;
                   while(temp -> next != NULL){
                           prev = temp;
                           temp = temp -> next;
                   }
                   prev -> next = NULL;
                   printf("\n Deleted data is : %d", temp -> data);
                   free(temp);
           }
}
countnode()
{
                int count=0;
                temp = head;
                while (temp != NULL){
                    count++;
                    temp = temp -> next;
                }
                printf("\n Total node is %d",count);
}
search(){
                int s , f=0;
                if(head==NULL){
                    printf("\n List not found");
                }
                else{
                    printf("Enter an element for search:");
                    scanf("%d",&s);
                    temp = head;
                    while(temp !=NULL){
                        if (temp -> data == s) {
                            f=1;
                            break;
                        }
                        temp=temp->next;
                    }
                    if (f==1){
                        printf("Searching success");
                    }
                    else{
                        printf("searching not success");
                    }
                }
}
