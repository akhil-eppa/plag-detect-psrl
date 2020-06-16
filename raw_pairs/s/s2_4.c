#include<stdio.h>
#include<string.h>
 
struct student			// type declaration which defines how student entity looks like
{						// now all three are related
	double rnum;			// these three are members of the structure
	char name[100];		
	float marks;
};			// semicolon is compulsory
//No memory allocation for declaration of the structure type

int main()
{
// Creating the structure variable means memory gets allocated
	struct student s1;				 
	// all members are  uninitialized
	printf("Student number is %d\n",s1.rnum);		// junk is printed
	// only one student details can be stored. If you want to store details of more students, we must create many structure variables separately or create array of structures
	strcpy(s1.name,"abc");
	s1.marks=78;
	s1.rnum=56;

	printf("Student Name: %s\n",s1.name);
	printf("Student number: %lf\n",s1.rnum);
	printf("Marks obtained: %f\n",s1.marks);
	
	return 0;


}
