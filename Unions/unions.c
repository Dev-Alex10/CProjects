#include <stdio.h>

union student {
    int roundedGrade;
    float exactGrade;
    char letterGrade;
};

/*
   struct car_data{
   char make[15];
   int status; // 0 = owned, 1 = leased
   union{
   struct owner own_car;
   struct lease lease_car;
   };
   };
   */
int main(){
    union student student1, student2 = {.exactGrade = 2.0}, *student3;
    student1.letterGrade = 'A';
    student1.exactGrade = 55.0;
    puts("Insert a number to see on union student1");
    scanf("%d", &student1.roundedGrade);
    printf("memory size occupied by data: %zu\n", sizeof(student1));
    printf("Union of %d and %f, letterGrade: %c\n",
            student1.roundedGrade, student1.exactGrade, student1.letterGrade);


    puts("\nInsert a letter to see union student2");
    scanf("%s", &student2.letterGrade);
    printf("letterGrade student2 %c\n",student2.letterGrade);
    printf("student2 memory occupied %zu\n",sizeof(student2));

    puts("\nInsert a integer to see union student2");
    scanf("%d", &student2.roundedGrade);
    printf("integer student2 %d\n",student2.roundedGrade);
    printf("student2 memory occupied %zu\n",sizeof(student2));

    puts("\nInsert a float to see union student2");
    scanf("%f", &student2.exactGrade);
    printf("float student2 %f\n",student2.exactGrade);
    printf("student2 memory occupied %zu\n",sizeof(student2));

    return 0;
}
