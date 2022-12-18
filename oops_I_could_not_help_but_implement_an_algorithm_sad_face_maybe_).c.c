#include <stdio.h>
#include <ctype.h>

#define MAX_CHARACTERS 1000

int read_line(char str[], int n);
void ceasor_shift(char str[], int shift);

int main(int argc, char *argv[])
{
    int key = 0;
    char message[MAX_CHARACTERS+1];

    printf("Enter your Christmas wish :) : ");
    read_line(message, MAX_CHARACTERS+1);

    printf("Enter your key: ");
    scanf("%d", &key);
    
    ceasor_shift(message, key);
    
    printf("\n\n%s\n", message);
    
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';  // terminates string 
    return i;
}

void ceasor_shift(char str[], int shift)
{
    shift %= 26;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ') continue;

        if (shift >= 0)
        {   
            if (isupper(str[i]))
            {   
                if (str[i] + shift > 'Z')
                {
                    str[i] = 'A' + (str[i] + shift - 'Z') - 1;
                } else 
                {
                    str[i] += shift;
                }
            } else
            {
                if (str[i] + shift > 'z')
                {
                    str[i] = 'a' + (str[i] + shift - 'z') - 1;
                } else 
                {
                    str[i] += shift;
                }
            }
        } else
        {
            if (isupper(str[i]))
            {
                if (-shift <= str[i] - 'A')
                {
                    str[i] += shift;
                } else 
                {
                    str[i] = 'Z' - (-shift - str[i] + 'A') + 1;
                }
            }
            else 
            {
                if (-shift <= str[i] - 'a')
                {
                    str[i] += shift;
                } else 
                {
                    str[i] = 'z' - (-shift - str[i] + 'a') + 1;
                }
            }
        }
    }
}