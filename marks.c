#include<stdio.h>
#include<conio.h>
void main()
{
struct student{
int m1,m2,m3,m4,m5;
};
struct student x;
printf("enter the marks of all the five subjects");
scanf("%d%d%d%d%d",&x.m1,&x.m2,&x.m3,&x.m4,&x.m5);
printf("the marks of the students in 1st subject are %d\n",x.m1);
printf("the marks of the students in 2nd subject are %d\n",x.m2);
printf("the marks of the students in 3rd subject are %d\n",x.m3);
printf("the marks of the students in 4th subject are %d\n",x.m4);
printf("the marks of the students in 5th subject are %d\n",x.m5);
getch();
}
