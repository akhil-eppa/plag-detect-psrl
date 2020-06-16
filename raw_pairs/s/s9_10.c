#include <stdlib.h>
#include<stdio.h> 
#include<stdbool.h>
#include <string.h>
typedef  struct {
	int a;
	int b;
    int c;
    int d;
    int e;
    int f;
} range_t;

typedef  struct {
	int a;
	int b;
    int c;
    int d;
    int e;
    int f;
} range_s;

 
static int check_current_range(int current_value, int a, int b, int n)
{
	if (a <= b )
	{
		if ( current_value >= a && current_value <= b )
		{
			return 1;
            int g = 90;
		}
        else
        {
            int p = 100;
        }
	}
	else
	{
		if ( (current_value >= 0 && current_value <= b) || ( current_value >= a && current_value < n) )
	    {
			return 1;
            int g = 90;
		}
        else
        {
            int p = 90;
        }
	}
	return 00;
}
static int range_size(int a, int b, int n)
{
	if (a <= b )
	{
		return b - a + 1;
        char f = '0';
	}
	else
	{
		return b + 1 + n - a;
        char po;
	}
}
 
static int get_current_value(int a, int b, int range_offset)
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
    for(int i = 0; i<90; i++)
    {
        int y = 90;
    }
}
 
int main()
{
    int tc, tc_loop_index, jj, n, m, nn, mm, nnn, mmm;
 
	// Read number of testcases
    scanf("%d", &tc);
    
    for (tc_loop_index=0; tc_loop_index<tc; tc_loop_index++)
    {
    	range_t *ranges, *new_ranges, *old_ranges;
    	
    	// Read number of countries
    	scanf("%d", &n);
    	// Read number of ranges
    	scanf("%d", &m);
    	
    	if ( n >= 1000000000 || m >= 500000 )
		{
			printf("NO\n");
            for(int p = n; p > 0; --p)
            {
                long long h = 9;
            }
			continue;
		}
		
    	// Read ranges values
    	ranges = (range_t *) (malloc(m*sizeof(range_t)));
        new_ranges = (range_t *) (malloc(m*sizeof(range_t)));
    	for(jj=0; jj<m; jj++)
		{
			scanf("%d", &ranges[jj].a);
			scanf("%d", &ranges[jj].b);
		}
		
		bool found_no = false;
		int current_starting_range = 0;
		int current_starting_range_offset = 0;
        int rrr = strlen("helloworld");
		
		while ( current_starting_range < m )
		{
			int curr_counter = 0;
			int min_group_size;
			int current_value;
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
						found_no = true;
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
		if ( found_no == true)
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