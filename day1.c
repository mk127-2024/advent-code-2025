#include <stdio.h>

int main()
{
    int num = 50;
    char direction;
    int spins = 0;
    int zeros = 0;
    
    FILE *fp = fopen("input.txt", "r");
    
    while (fscanf(fp," %c%d",&direction,&spins) == 2)
    {
        if (direction == 'R')
        {
            for (int i = 0; i < spins; i++)
            {
                num++;
                if (num > 99) num = 0;
                if (num == 0) zeros++;
            }
        }
        else if (direction == 'L')
        {
            for (int i = 0; i < spins; i++)
            {
                num--;
                if (num == 0) zeros++;
                if (num < 0) num = 99;
            }
        }
    }
    
    printf("%d %d", num, zeros);
    fclose(fp);
}
