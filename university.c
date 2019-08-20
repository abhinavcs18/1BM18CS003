#include<stdio.h>
void main()
{
    int n,x ;
    printf("enter the number of students\n") ;
    scanf("%d",&n) ;
    struct student
    {
        int id ;
        int marks ;
        int age ;
    }st[n];
    for( x=0;x<n;x++)
    {
        printf("enter student's id:\n") ;
        scanf("%d",&st[x].id) ;
        printf("enter student's age:\n") ;
        scanf("%d",&st[x].age) ;
        printf("enter student's marks:\n") ;
        scanf("%d",&st[x].marks) ;
    }
    for( x=0;x<n;x++)
    {
        if(st[x].age>20&&st[x].marks>=0&&st[x].marks<=100)
        {
            if(st[x].marks>=65)
            {
                printf("student having id %d passed\n",st[x].id) ;
            }
            else
            {
                printf("student having id %d failed\n",st[x].id) ;
            }
        }
        else
        {
            printf("student having id %d have entered invalid information\n",st[x].id) ;
        }
    }
}