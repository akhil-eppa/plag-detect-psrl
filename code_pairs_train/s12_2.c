#include<stdio.h>
#include<string.h>
 
struct STUD			// type declaration which defines how STUD entity looks like
{						// now all three are related
	int id_number;			// these three are members of the structure
	char NAME[20];		
	int MARKS;
};			// semicolon is compulsory
//No memory allocation for declaration of the structure type

int main()
{
// Creating the structure variable means memory gets allocated
	struct STUD S;				 
	// all members are  uninitialized
	printf("%d-----------\n",S.id_number);		// junk is printed
	// only one STUD details can be stored. If you want to store details of more students, we must create many structure variables separately or create array of structures
	strcpy(S.NAME,"xyz");
	S.MARKS=53;
	S.id_number=12;

	printf("%s\n",S.NAME);
	printf("%d\n",S.id_number);
	printf("%d\n",S.MARKS);
	
	return 0;


}
