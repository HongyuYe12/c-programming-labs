#include<stdio.h>
struct course
{
    char coursename[50];
    int credits;
    int finalmark;
    char grade[5];
    float gradepoints;
    char description[20];
} ;
void calculate(struct course *course)
{
    if(course->finalmark>=85)
    {
        course->gradepoints=4.00;
        sprintf(course->grade,"A");
        sprintf(course->description,"Distinction");
    }
    else if(course->finalmark>=80)
    {
        course->gradepoints=3.70;
        sprintf(course->grade,"A-");
        sprintf(course->description,"Distinction");
    }
    else if(course->finalmark>=75)
    {
        course->gradepoints=3.30;
        sprintf(course->grade,"B+");
        sprintf(course->description,"Good");
    }
    else if(course->finalmark>=70)
    {
        course->gradepoints=3.00;
        sprintf(course->grade,"B");
        sprintf(course->description,"Good");
    }
    else if(course->finalmark>=65)
    {
        course->gradepoints=2.70;
        sprintf(course->grade,"B-");
        sprintf(course->description,"Good");
    }
    else if(course->finalmark>=60)
    {
        course->gradepoints=2.30;
        sprintf(course->grade,"C+");
        sprintf(course->description,"Pass");
    }
    else if(course->finalmark>=55)
    {
        course->gradepoints=2.00;
        sprintf(course->grade,"C");
        sprintf(course->description,"Pass");
    }
    else if(course->finalmark>=50)
    {
        course->gradepoints=1.70;
        sprintf(course->grade,"C-");
        sprintf(course->description,"Conditional Pass");
    }
    else if(course->finalmark>=45)
    {
        course->gradepoints=1.30;
        sprintf(course->grade,"D+");
        sprintf(course->description,"Fail");
    }
    else if(course->finalmark>=40)
    {
        course->gradepoints=1.00;
        sprintf(course->grade,"D");
        sprintf(course->description,"Fail");
    }
    else
    {
        course->gradepoints=0.00;
        sprintf(course->grade,"F");
        sprintf(course->description,"Fail");
    }
}
int main()
{
    char studentID[11];
    int sum=0;
    struct course course[5];
    float total=0.0;
    float gpa=0.0;
    printf("Please input the Student ID:");
    scanf("%s",studentID);
    for (int i=0;i<5;i++)
    {
        printf("Please input the course code of course #%d:",i+1);
        scanf("%s",course[i].coursename);
        printf("Please input the credits attempted for %s:",course[i].coursename);
        scanf("%d",&course[i].credits);
        printf("Please input the grade for %s:",course[i].coursename);
        scanf("%d",&course[i].finalmark);
        calculate(&course[i]);
        total=total+course[i].gradepoints*course[i].credits;
        sum+=course[i].credits;
    }
    gpa=total/sum;
    printf("Student ID:%s\n",studentID);
    printf("Course Code\tCredits\tFinal mark\tGrade\tGrade Points\tDescription\n");
    for (int i=0;i<5;i++)
    {
        printf("%s\t\t%d\t%d\t\t%s\t%.2f\t\t%s\n",course[i].coursename,course[i].credits,course[i].finalmark,course[i].grade,course[i].gradepoints,course[i].description);
    }
        printf("The average GPA of %s in 202404 semester:%.2f\n",studentID,gpa);
    return 0;
}
