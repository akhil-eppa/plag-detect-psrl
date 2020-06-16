#include <stdlib.h>
#include<stdio.h> 

int range_size(int a, int b, int n);
int get_current_value(int a, int b, int range_offset);

typedef  struct {
    int b;
	int a;
} range_t;
int check_current_range(int current_value, int a, int b, int n);


 

 
int main()
{
    int tc; 
 
	// Read number of testcases
    scanf("%d", &tc);

    int tc_loop_index;

    int m, n;
    int jj;
    
    
    for (tc_loop_index=0; tc_loop_index<tc; tc_loop_index++)
    {
    	range_t *ranges;
    	
    	// Read number of countries
    	scanf("%d\n%d", &n, &m);
    	
    	if ( n >= 1000000000 || m >= 500000 )
		{
			printf("NO\n");
			continue;
		}
		
    	// Read ranges values
    	ranges = (range_t *) (malloc(m*sizeof(range_t)));
    	for(jj=0; jj<m; jj++)
		{
			scanf("%d\n%d", &ranges[jj].a, &ranges[jj].b);
		}
		
        int current_starting_range_offset = 0, found_no = 0;
		int current_starting_range = 0;
		
		
		while ( current_starting_range < m )
		{
            int current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
			int curr_counter = 0, min_group_size, current_value;
			
 
			while ( current_range_size >= m )
			{
				++current_starting_range;
				if ( current_starting_range >= m )
					break;
				current_range_size = range_size(ranges[current_starting_range].a, ranges[current_starting_range].b, n);
			}
			min_group_size = current_range_size;
			current_value = get_current_value(ranges[current_starting_range].a, ranges[current_starting_range].b, current_starting_range_offset);
 
	    	for(jj=0; jj<m; jj++)
	    	{
				if ( check_current_range(current_value, ranges[jj].a, ranges[jj].b, n) )
				{
					if ( current_range_size < min_group_size )
						min_group_size = current_range_size;
					
	    			++curr_counter;
					if ( curr_counter > min_group_size )
					{
                        current_starting_range = m;
						found_no = 1;
						
						break;
					}
				}
			}
			current_starting_range_offset+=1;
			if ( current_starting_range_offset == current_range_size )
			{
                current_starting_range_offset=0;
				current_starting_range+=1;
				
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
    
    return 0;
 
}

int get_current_value(int a, int b, int range_offset)
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


int range_size(int a, int b, int n)
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

int check_current_range(int current_value, int a, int b, int n)
{
	if (a <= b )
	{
		if ( current_value >= a && current_value <= b )
			return 1;
	
	}
	else
	{
		if ( (current_value >= 0 && current_value <= b) || ( current_value >= a && current_value < n) )
        			return 1;
	}
	return 0;
}