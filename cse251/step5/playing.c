#include <stdio.h>

int main()
{
    int i;
    int j;
    
    for(i=0;  i<11;  i++)
    {
        if(i < 5)
        {
            for(j=0;  j<=i;  j++)
                printf("+");
        }
        else
        {
            for(j=0;  j<=(10-i);  j++)
                printf("+");
        }
        
        printf("\n");
    }

    printf("---\n");   
}
