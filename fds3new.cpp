//without pointers structure
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct student      //structure declaration
{
    char name[30];
    int prn;
    float perc;
};
struct student stu[10];  //declaring a global variable named stu

int count=0;   //keeping the track of elements present in the structure

void create();
void insert();
void modify();
void Delete();
void display();
int main()
{
	int num , ch ;
    do
    {

	printf("\n******MAIN MENU******");
	printf("\n Create");
    printf("\n Insert");
    printf("\n Modify");
    printf("\n Delete");
    printf("\n Display");

    printf("\nenter the choice number==> ");
    scanf("%d" , &num);

    switch(num)
    {
        case 1:
        create();
        break;

        case 2:
        insert();
        break;

        case 3:
        modify();
        break;

        case 4:
        Delete();
        break;

        case 5:
        display();
        break;

        default:
        printf("wrong choice");
    }

    printf("\n Do you want to continue(0/1)==>");
    scanf("%d", &ch);
    }
    while(ch!=0);
}
void create()
{
    int x;
    printf("Enter the number of the records you want to enter:\n==>");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        printf("Enter the name prn and percentage:\n");
        scanf("%s",stu[i].name);
        scanf("%d",&stu[i].prn);
        scanf("%f",&stu[i].perc);
        count++;
    }
    display();
}
void insert()
{
    int x;
    printf("Enter the number of the records you want to insert:\n==>");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        printf("Enter the name prn and percentage:\n");
        fflush(stdin); // to clear (or flush) the output buffer and move the buffered data to console 
        scanf("%s",stu[count].name);
        scanf("%d",&stu[count].prn);
        scanf("%f",&stu[count].perc);
        count++;                     
    }
    display();
}
void Delete()
{
    char name[30];
    printf("Enter the name of which you want to delete the entry:\n==>");
    fflush(stdin);
    scanf("%s",name);
    for (int i=0;i<count;i++)  //count is keeping the track of number of elements in structure
    {
        if (!strcmp(name,stu[i].name))
        {
            while(i<count)
            {
                stu[i]=stu[i+1]; //shifting one posn before
                i++;
            }
        }
    }
    printf("Deleted!!\n");
    count--;
}
void modify()
{
    char stname[30];
    int stprn;
    float stperc;

    printf("Enter the student's name you want to modify\n==>");
    scanf("%s",stname);
    printf("\nNew prn\n==>");
    scanf("%d", &stprn);
    printf("\nNew percentage\n==>");
    scanf("%f", &stperc);
    
    for (int i=0;i<count;i++)  //using the for loop searching the name in the given structure
    {
        if (!strcmp(stname ,stu[i].name))
        {
            stu[i].prn = stprn;
            stu[i].perc = stperc;
        }
        display();
    }

}
void display()
{
    for (int i =0;i<count;i++)
    {
        printf("\nName: %s\t",stu[i].name);
        printf("PRN: %d \t",stu[i].prn);
        printf("Percentage: %f\t",stu[i].perc);
        printf("\n");
    }
}