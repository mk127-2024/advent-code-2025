#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    
    char line[300]; 
    int pass = 200;  
    int sum = 0;
    
    for (int i = 0; i < pass; i++)
    {
        int idx = 0; 
        int arr[300];
        int max = 0;
        
        if (fgets(line, sizeof(line), fp)) 
        {
             line[strcspn(line, "\n")] = 0; 
             
            for (int j = 0; j < strlen(line); j++)
            {
                if (line[j] >= '0' && line[j] <= '9')
                {
                    arr[idx++] = line[j] - '0'; 
                    printf("%d", line[j] - '0'); 
                }
            }
            
            int process[300];
            for (int p = 0; p < idx; p++)
            {
                process[p] = 0;
            }
            
            for (int k = 0; k < idx; k++)
            {
                process[k] = 1;
               
                for (int l = k+1; l < idx; l++)
                {
                    int num = arr[k]*10+arr[l];
                    
                    if (process[l] != 1 && num > max)
                    {
                        max = num;
                    }
                }
                
                process[k] = 0;
            }
            
            sum += max;
            printf(" sum: %d max: %d", sum, max);
        }
        
        printf("\n");
    }

    fclose(fp);
    return 0;
}
