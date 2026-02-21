#include <stdio.h>
int main(){
     int ar[5]={1,2,3,4,5},pos,i,n=5;
     printf("Enter position of element you want to delete:");
     scanf("%d",&pos);
     for (i=pos ; i<5 ; i++){
          ar[i]=ar[i+1];
     }
     n--;
     for (i=0 ; i<n ; i++){
          printf("%d",ar[i]);
     }
     return 0;
}
