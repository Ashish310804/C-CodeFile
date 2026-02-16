#include <stdio.h>
struct Student {
    char name[50];
    char usn[15];
    char subject[50];
    int ia_marks;
};
int main() {
    int n, i, name, usn, subject, ia_marks;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (i = 0; i < n; i++) {
        printf("Enter details of student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("USN: ");
        scanf("%s", &students[i].usn);
        printf("Subject: ");
        scanf("%s", &students[i].subject);
        printf("IA Marks: ");
        scanf("%d", &students[i].ia_marks);
    }
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, USN: %s, Subject: %s, IA Marks: %d\n", students[i].name, students[i].usn, students[i].subject, students[i].ia_marks);
    }
    return 0;
}
