#include<stdio.h>
#include<string.h>
 
struct student			
{						
	int rnum;			
	char name[20];		
	int marks;
};			
/*
The structure student contains:
 - The register number stored as int
 - the name of the student
 - the marks obtained by the student */

int main()
{
	struct student s1;				 
	// all of the members of the structure are  uninitialized
	printf("%d-----------\n",s1.rnum);		// junk value is printed
	// only one student details can be stored.
	strcpy(s1.name,"abc");
	s1.marks=78;
	s1.rnum=56;

    //The elements of the structure are displayed
	printf("%s\n",s1.name);
	printf("%d\n",s1.rnum);
	printf("%d\n",s1.marks);
	
	return 0; //This is the end of the program
}
