#include <stdlib.h>
#include<stdio.h> 
typedef  struct {
	unsigned int a;
	unsigned int b;
} range_t;
 
static int check_current_range(long current_value, long a, long b, long n)
{
	if (a <= b )
	{
		if ( current_value >= a && current_value <= b )
		{
			return 1;
		}
	}
	else
	{
		if ( (current_value >= 0 && current_value <= b) || ( current_value >= a && current_value < n) )
	    {
			return 1;
		}
	}
	return 0;
}
static int range_size(int a, long int b, unsigned int n)
{
	if (a <= b )
	{
		return b - a + 1;
	}
	else
	{
		return b + 1 + n - a;
	}
}
 
static int get_current_value(int a, long int b, long long int range_offset)
{
	if (a <= b )
	{
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
    long long int tc, tc_loop_index, jj, n, m;
 
	// Read number of testcases
    scanf("%li", &tc);
    
    for (tc_loop_index=0; tc_loop_index<tc; tc_loop_index++)
    {
    	range_t *ranges;
    	
    	// Read number of countries
    	scanf("%li", &n);
    	// Read number of ranges
    	scanf("%li", &m);
    	
    	if ( n >= 1000000000 || m >= 500000 )
		{
			printf("The answer is NO\n");
			continue;
		}
		
    	// Read ranges values
    	ranges = (range_t *) (malloc(m*sizeof(range_t)));
    	for(jj=0; jj<m; jj++)
		{
			scanf("%d", &ranges[jj].a);
			scanf("%d", &ranges[jj].b);
		}
		
		int found_no = 0;
		int current_starting_range = 0;
		int current_starting_range_offset = 0;
		
		while ( current_starting_range < m )
		{
			long long int curr_counter = 0;
			long int min_group_size;
			long current_value;
			int current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
 
			while ( current_range_size >= m )
			{
				current_starting_range++;
				if ( current_starting_range >= m )
				{
					break;
				}
				current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
			}
			min_group_size = current_range_size;
			current_value = get_current_value(ranges[current_starting_range].a, ranges[current_starting_range].b, current_starting_range_offset);
 
	    	for(jj=0; jj<m; jj++)
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
			printf("The answer is NO\n");
		}
	    else
		{
	    	printf("The answer is YES\n");
		}
	}
    
    return 0;
 
}