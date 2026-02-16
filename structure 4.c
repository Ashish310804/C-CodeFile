#include <stdio.h>
#include <string.h>
struct Student {
    int roll_no;
    char name[50];
    float marks;
    char grade;
};
int main() {
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (i = 0; i < n; i++) {
        printf("Enter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
    char search_name[50];
    printf("Enter the name of the student to search: ");
    scanf("%s", search_name);
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Marks of %s: %.2f\n", students[i].name, students[i].marks);
            break;
        }
    }
    if (i == n) {
        printf("Student not found.\n");
    }
    return 0;
}

