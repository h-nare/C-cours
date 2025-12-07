#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct Student {
    char name[50];
    char surname[50];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* table[TABLE_SIZE];

int hash(int id) {
    return id % TABLE_SIZE;
}

Student* create_student(char* name, char* surname, int id, float grade) {
    Student* s = malloc(sizeof(Student));
    strcpy(s->name, name);
    strcpy(s->surname, surname);
    s->id = id;
    s->grade = grade;
    s->next = NULL;
    return s;
}

void add_student() {
    char name[50], surname[50];
    int id;
    float grade;

    printf("Enter name: ");
    scanf("%49s", name);

    printf("Enter surname: ");
    scanf("%49s", surname);

    printf("Enter ID: ");
    scanf("%d", &id);

    printf("Enter grade: ");
    scanf("%f", &grade);

    int index = hash(id);
    Student* s = create_student(name, surname, id, grade);

    s->next = table[index];
    table[index] = s;

    printf("Student added.\n");
}

void remove_student() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int index = hash(id);
    Student *curr = table[index], *prev = NULL;

    while (curr != NULL) {
        if (curr->id == id) {
            if (prev == NULL)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            printf("Student removed.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Student not found.\n");
}

void search_student() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int index = hash(id);
    Student* curr = table[index];

    while (curr != NULL) {
        if (curr->id == id) {
            printf("Name: %s\n", curr->name);
            printf("Surname: %s\n", curr->surname);
            printf("ID: %d\n", curr->id);
            printf("Grade: %.2f\n", curr->grade);
            return;
        }
        curr = curr->next;
    }

    printf("Student not found.\n");
}

void display_all() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* curr = table[i];
        while (curr != NULL) {
            printf("%s %s | ID: %d | Grade: %.2f\n",
                   curr->name, curr->surname, curr->id, curr->grade);
            curr = curr->next;
        }
    }
}

void average_grade() {
    float sum = 0;
    int total = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* curr = table[i];
        while (curr != NULL) {
            sum += curr->grade;
            total++;
            curr = curr->next;
        }
    }

    if (total == 0) {
        printf("No students.\n");
        return;
    }

    printf("Average grade: %.2f\n", sum / total);
}

void save_to_file() {
    FILE* f = fopen("group_details.csv", "w");
    if (!f) {
        printf("Could not open file.\n");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* curr = table[i];
        while (curr != NULL) {
            fprintf(f, "%s,%s,%d,%.2f\n",
                    curr->name, curr->surname, curr->id, curr->grade);
            curr = curr->next;
        }
    }

    fclose(f);
    printf("Saved to group_details.csv\n");
}

void load_from_file() {
    FILE* f = fopen("group_details.csv", "r");
    if (!f) {
        printf("File not found.\n");
        return;
    }

    // Free existing data
    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* curr = table[i];
        while (curr != NULL) {
            Student* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        table[i] = NULL;
    }

    char line[200];
    while (fgets(line, sizeof(line), f)) {
        char* name = strtok(line, ",");
        char* surname = strtok(NULL, ",");
        char* id_str = strtok(NULL, ",");
        char* grade_str = strtok(NULL, ",");

        if (!name || !surname || !id_str || !grade_str)
            continue;

        int id = atoi(id_str);
        float grade = atof(grade_str);

        int index = hash(id);
        Student* s = create_student(name, surname, id, grade);
        s->next = table[index];
        table[index] = s;
    }

    fclose(f);
    printf("Loaded from file.\n");
}

void free_all() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Student* curr = table[i];
        while (curr != NULL) {
            Student* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        table[i] = NULL;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STUDENT MANAGER (HASH TABLE) ---\n");
        printf("1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Search student\n");
        printf("4. Display all students\n");
        printf("5. Display average grade\n");
        printf("6. Save to file\n");
        printf("7. Load from file\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: remove_student(); break;
            case 3: search_student(); break;
            case 4: display_all(); break;
            case 5: average_grade(); break;
            case 6: save_to_file(); break;
            case 7: load_from_file(); break;
            case 8:
                free_all();
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}

