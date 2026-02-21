#include <stdio.h>
int main() {
    FILE *source, *target;
    char ch;
    source = fopen("source.txt", "r");
    if (source == NULL) {
        printf("Source file not found.\n");
        return 1;
    }
    target = fopen("target.txt", "w");
    if (target == NULL) {
        fclose(source);
        printf("Target file cannot be opened.\n");
        return 1;
    }
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }
    printf("File copied successfully.\n");
    fclose(source);
    fclose(target);
    return 0;
}
