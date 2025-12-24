#include <stdio.h>
#include <string.h>

// given x amount of digits, index, array of the numbers for each line, and an array to mark which nunmbers were used. it takes marked numbers and builds a number result at the end. 
long long findlargestnumber(long long *arr, int *process, int index)
{
    long long result = 0; 
    int digit = 12;
    
    for (int i = 0; i < index; i++)
    { process[i] = 0; }
    
    int stack[30];
    int top = 0;
    
    for (int i = 0; i < index; i++) // for every value in the array 
    {
        while (top > 0 && arr[i] > arr[stack[top-1]] && (top - 1 + index - i) >= 12) // this checks for arri is bigger than the last digit in the stack and there are enough digits to hit 12
        {
            top--; // "pop" it from the stack
        }
        
        if (top < 12) stack[top++] = i; // push digit onto stack
    }
    
    for (int i = 0; i < top; i++)
    {
        process[stack[i]] = 1; // mark all digits that we use
    }
    
    for (int i = 0; i < index; i++)
    {
        if (process[i] == 1)
        {
            result = result*10 + arr[i]; // build the number
        }
    }
   
    
    return result;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    
    char line[300]; 
    int pass = 200;  
    long long sum = 0;
    
    for (int i = 0; i < pass; i++)
    {
        int idx = 0; 
        long long arr[300];
        long long max = 0;
        
        if (fgets(line, sizeof(line), fp)) 
        {
             line[strcspn(line, "\n")] = 0; 
             
            for (int j = 0; j < strlen(line); j++)
            {
                if (line[j] >= '0' && line[j] <= '9')
                {
                    arr[idx++] = line[j] - '0'; 
                    printf("%lli", line[j] - '0'); 
                }
            }
            
            int process[300];
            for (int p = 0; p < idx; p++)
            {
                process[p] = 0;
            }
            
            max = findlargestnumber(arr,process,idx);
            sum += max;
            printf(" max:%lli total sum:%lli", max, sum);
        }
        
        printf("\n");
    }

    fclose(fp);
    return 0;
}
