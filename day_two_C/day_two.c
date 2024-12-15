#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    FILE *file = fopen("D:/input2.txt", "r");

    char line[256];
    char *token;
    int numbers[10];
    int count = 0;
    int lines = 0;
    if (file != NULL)
    {
        while (fgets(line, sizeof(line), file))
        {
            lines++;
            line[strcspn(line, "\n")] = '\0';
            char *p1 = line;
            int numbers[20];
            int n = 0;
            while (*p1 != '\0')
            {
                while (*p1 == ' ')
                    p1++;
                if (*p1 == '\0')
                    break;
                int number = 0;
                if (isdigit(*p1))
                {
                    number = *p1 - '0';
                    p1++;

                    if (isdigit(*p1))
                    {
                        number = number * 10 + (*p1 - '0');
                        p1++;
                    }
                }
                else
                {
                    fprintf(stderr, "Unexpected character '%c' in input\n", *p1);
                    p1++;
                    continue;
                }
                numbers[n++] = number;
            }
            bool isSafe = true;
            bool isIncreasing = false;
            bool isDecreasing = false;

            for (int i = 0; i < n; i++)
            {
                printf("%d ", numbers[i]);
            }
            printf("\n");
            if (numbers[0] < numbers[1])
                isIncreasing = true;
            else if (numbers[0] > numbers[1])
                isDecreasing = true;
            else
            {
                isSafe = false;
            }
            for (int i = 1; i < n; i++)
            {
                int diff = abs(numbers[i] - numbers[i - 1]);
                if (diff > 3)
                {
                    isSafe = false;
                    printf("Line %d: Difference too large between %d and %d\n", lines, numbers[i - 1], numbers[i]);
                    break;
                }
                if (isIncreasing)
                {
                    if (numbers[i] <= numbers[i - 1])
                    {
                        isSafe = false;
                        printf("Line %d: Sequence not strictly increasing at %d and %d\n", lines, numbers[i - 1], numbers[i]);
                        break;
                    }
                }
                else if (isDecreasing)
                {
                    if (numbers[i] >= numbers[i - 1])
                    {
                        isSafe = false;
                        printf("Line %d: Sequence not strictly decreasing at %d and %d\n", lines, numbers[i - 1], numbers[i]);
                        break;
                    }
                }
            }

            if (isSafe)
            {
                count++;
            }
        }
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Unable to open file!\n");
    }
    printf("%d\n", count);
    return 0;
}