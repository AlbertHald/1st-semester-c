#include <stdio.h>

#define n 5

struct Student
    {
        char name[10];
        int age;
        float GPA;
        char gradeLevel[10];
    };

    struct Student students[n];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < n; i++)
    {
        students[i].age = 5;
        *students[i].name = "Albert";
        students[i].GPA = 3,14;
        *students[i].gradeLevel = "BingBong";
    }
    for (int j = 0; j < n; j++)
    {
        printf("bing bing");
    }
    
    
    return 0;
}
