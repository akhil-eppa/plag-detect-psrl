#include<stdio.h>
#include<string.h>
struct student			
{						
	int rnum;			
	char name[20];		
	int marks;
};
int main()
{
	struct student s1;
	printf("%d-----------\n",s1.rnum);
	strcpy(s1.name,"abc");
	s1.marks=78;
	s1.rnum=56;
	printf("%s\n",s1.name);
	printf("%d\n",s1.rnum);
	printf("%d\n",s1.marks);
	return 0;
}
