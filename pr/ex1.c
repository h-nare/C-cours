#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[50];
	int age;
	float grade;
}Student;

void sort_by_grade(Student *s, int n) {
    int i, j;
    Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].grade > s[j].grade) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main(){
	int n;
	int i;

	Student *students;
	
	printf("Enter number of students: ");
	scanf("%d", &n);

	students = malloc(n * sizeof(Student));
	if(students == NULL)
		return 1;

	for (i = 0; i < n; i++) {
        	printf("\nStudent %d\n", i + 1);

        	printf("Name: ");
        	scanf(" %49[^\n]", students[i].name);

        	printf("Age: ");
        	scanf("%d", &students[i].age);

        	printf("Grade: ");
        	scanf("%f", &students[i].grade);
    	}

	sort_by_grade(students, n);

   
    	FILE *file = fopen("students.csv", "w");
    	if (file == NULL) {
        	free(students);
        	return 1;
    	}

    	for (i = 0; i < n; i++) {
        	fprintf(file, "%s,%d,%.2f\n",
                	students[i].name,
                	students[i].age,
                	students[i].grade);
    	}

    	fclose(file);
    	free(students);

    	return 0;
}	
