#include <stdlib.h>
#include<stdio.h> 

/*
    Comments are added
    here
    in this file
*/
typedef  struct {
	int a; 
    //Extra comment
	int b;
} range_t; //sizeof range_t is 8 bytes
 
static int check_current_range(int current_value, int a, int b, int n)
{
    /*
    this
    program
    has around
    150
    lines
            */
	if (a <= b )
	{
		if ( current_value >= a && current_value <= b ) //single if statement
		{
			return 1; //return 1
		}
	}
	else
	{
		if ( (current_value >= 0 && current_value <= b) || ( current_value >= a && current_value < n) )
	    {
			return 1; //return 1
		}
	}
	return 0;
    //here return 0
}
static int range_size(int a, int b, int n) //comment
{
	if (a <= b )
	{
		return b - a + 1; //return statement
	}
	else
	{
		return b + 1 + n - a;//return statement
	}
}
//new function
static int get_current_value(int a, int b, int range_offset)
{
	if (a <= b )
	{ //triple if-else statement
		return a+range_offset;
	}
	else if ( range_offset <= b )
	{
		return range_offset;
	}
	else
	{
		return a + range_offset - b + 1;
	}
}
 
int main()
{
    int tc, tc_loop_index, jj, n, m;

    scanf("%d", &tc);
    
    for (tc_loop_index=0; tc_loop_index<tc; tc_loop_index++)
    {
    	range_t *ranges;
    	

    	scanf("%d", &n);

    	scanf("%d", &m);
    	
    	if ( n >= 1000000000 || m >= 500000 )
		{
			printf("NO\n");
			continue;
        }
    	ranges = (range_t *) (malloc(m*sizeof(range_t)));
    	for(jj=0; jj<m; jj++)//for loop
		{
			scanf("%d", &ranges[jj].a);
			scanf("%d", &ranges[jj].b);
		}
		//datatypes are defined
		int found_no = 0;
		int current_starting_range = 0;
		int current_starting_range_offset = 0;
		
		while ( current_starting_range < m ) //while loop
		{
			int curr_counter = 0;
			int min_group_size;
			int current_value;
			int current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
 
			while ( current_range_size >= m ) //abcdefgh
			{
				current_starting_range++;
				if ( current_starting_range >= m ) //if break
				{
					break;
				}
				current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
			}
			min_group_size = current_range_size;
			current_value = get_current_value(ranges[current_starting_range].a, ranges[current_starting_range].b, current_starting_range_offset);
 
	    	for(jj=0; jj<m; jj++) //last for loop
	    	{
				if ( check_current_range(current_value, ranges[jj].a, ranges[jj].b, n) )
				{
					if ( current_range_size < min_group_size )
					{
						min_group_size = current_range_size;
					}
	    			curr_counter++;
					if ( curr_counter > min_group_size )
					{
						found_no = 1;
						current_starting_range = m;
						break;
					}
				}
			}
			current_starting_range_offset++;
			if ( current_starting_range_offset == current_range_size )
			{
				current_starting_range++;
				current_starting_range_offset=0;
			}
	    }
		if ( found_no )
		{
			printf("NO\n");
		}
	    else
		{
	    	printf("YES\n");
		}
	}
    
    return 0; //end of program
 
}