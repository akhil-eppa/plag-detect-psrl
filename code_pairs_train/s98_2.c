#include <stdlib.h>
#include<stdio.h> 
typedef struct range{
	int x;
	int y;
} hello;
 
static int check_current_range(int val, int x, int y, int n)
{
	if (x <= y )
	{
		if ( val >= x && val <= y )
		{
			return 1;
		}
	}
	else
	{
		if ( (val >= 0 && val <= y) || ( val >= x && val < n) )
	    {
			return 1;
		}
	}
	return 0;
}
static int range_size(int q, int w, int e)
{
	if (q <= w )
	{
		return w - q + 1;
	}
	else
	{
		return w + 1 + e - q;
	}
}
 
static int get_val(int q, int w, int pop)
{
	if (q <= w )
	{
		return q+pop;
	}
	else if ( pop <= w )
	{
		return pop;
	}
	else
	{
		return q + pop - w + 1;
	}
}
 
int main()
{
    int new, tc_loop_index, jj, n, m;
 
	// Read number of testcases
    scanf("%d", &new);
    
    for (tc_loop_index=0; tc_loop_index<new; tc_loop_index++)
    {
    	hello *code;
    	
    	// Read number of countries
    	scanf("%d", &n);
    	// Read number of code
    	scanf("%d", &m);
    	
    	if ( n >= 1000000000 || m >= 500000 )
		{
			printf("NO\n");
			continue;
		}
		
    	// Read code values
    	code = (hello *) (malloc(m*sizeof(hello)));
    	for(jj=0; jj<m; jj++)
		{
			scanf("%d", &code[jj].x);
			scanf("%d", &code[jj].y);
		}
		
		int F = 0;
		int CURR = 0;
		int CURR_offset = 0;
		
		while ( CURR < m )
		{
			int count = 0;
			int minimum;
			int val;
			int size = range_size(code[CURR].x, code[CURR].y, n);
 
			while ( size >= m )
			{
				CURR++;
				if ( CURR >= m )
				{
					break;
				}
				size = range_size(code[CURR].x, code[CURR].y, n);
			}
			minimum = size;
			val = get_val(code[CURR].x, code[CURR].y, CURR_offset);
 
	    	for(jj=0; jj<m; jj++)
	    	{
				if ( check_current_range(val, code[jj].x, code[jj].y, n) )
				{
					if ( size < minimum )
					{
						minimum = size;
					}
	    			count++;
					if ( count > minimum )
					{
						F = 1;
						CURR = m;
						break;
					}
				}
			}
			CURR_offset++;
			if ( CURR_offset == size )
			{
				CURR++;
				CURR_offset=0;
			}
	    }
		if ( F )
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