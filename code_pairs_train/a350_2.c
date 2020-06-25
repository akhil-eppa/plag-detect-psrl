#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(void)
{
unsigned int t;
scanf( "%u", &t );
for( unsigned int i = 0; i < t; i++ )
    {
    unsigned int n;
    scanf( "%u", &n );
    
    unsigned int * m = malloc( sizeof( unsigned int ) * n );
    unsigned int min = UINT_MAX;
    unsigned int count = 0;
    for( unsigned int j = 0; j < n; j++ )
        {
        scanf( "%u", &m[j] );
        if( 1 == n )
            {
            count = 1;
            }
        else if( m[j] <= min )
            {
            count++;
            min = m[j];
            }
        }
    printf( "%u\n", count );
    free( m );
    }

return 0;
}

