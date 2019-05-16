#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    /** getting input from user as strings **/ 
    string name = get_string();
    int n = strlen(name);
    
    /** taking out initials from input and printing it **/
    printf("%c", toupper(name[0])); 
    for (int i = 0; i < n; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c",toupper(name[i + 1])); 
        }
    }
    printf("\n");
    
}
