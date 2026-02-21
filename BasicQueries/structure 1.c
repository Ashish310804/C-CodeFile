#include <stdio.h>
struct student{
    char name;
    int marks;
}e1;
int main(){
    struct student e1;
    int math , chem , phy , total , percentage ;
    printf("name of student:");
    scanf("%c",&e1.name);
    e1.marks=89;
    math=e1.marks;
    printf("\nmarks of student in maths: %d",math);
    e1.marks=90;
    phy=e1.marks;
    printf("\nmarks of student in physics: %d",phy);
    e1.marks=99;
    chem=e1.marks;
    printf("\nmarks of student in chemistry: %d",chem);
    total=math+chem+phy;
    printf("\ntotal marks of student: %d",total);
    percentage=total/3;
    printf("\npercentage obtained by student if all subject exam was of 100 marks each: %d",percentage);
    return 0;
}
