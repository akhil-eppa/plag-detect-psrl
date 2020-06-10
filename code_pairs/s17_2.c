#include<stdio.h>
#include<string.h>
 
struct student			
{						
	int rnum;			
	char name[20];		
	int marks;
};			

struct student get_student()
{
// Creating the structure variable means memory gets allocated
	struct student s1;	

    strcpy(s1.name,"abc");
	s1.marks=78;
	s1.rnum=56;

    return s1;
}

int main()
{
    struct student A = get_student();
	printf("%d-----------\n",A.rnum);
	// only one student details can be stored. If you want to store details of more students, we must create many structure variables separately or create array of structures

	printf("%s\n",A.name);
	printf("%d\n",A.rnum);
	printf("%d\n",A.marks);
	
	return 0;


}
