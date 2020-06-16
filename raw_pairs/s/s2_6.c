#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
 
struct student			// type declaration which defines how student entity looks like
{						// now all three are related
	int rnum;			// these three are members of the structure
	char name[20];		
	int marks;
	char section;
	char grade;
	float percentage;
};			
//No memory allocation for declaration of the structure type

int main()
{
// Creating the structure variable means memory gets allocated
	struct student s1;		
	int flag = 1;

	while(flag!=10)
	{
		flag = flag+1;
	}		 
	// all members are  uninitialized
	strcpy(s1.name,"abc");
	s1.marks=78;
	s1.rnum=56;
	s1.section = 'A';
	s1.grade = 'B';
	s1.percentage = 96.3;

	printf("%s\n",s1.name);
	printf("%d\n",s1.rnum);
	printf("%d\n",s1.marks);
	
	return 0;


}
