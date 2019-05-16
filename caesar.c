#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    bool keySuccessful = false;
    int key = 0;
    
    // valiadation of the command line input
    do
    {
        if (argc != 2)
        {
            printf("ERROR\n");
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            printf("We require an integer as encryption key.\n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            keySuccessful = true;
        }
    }
    while(!keySuccessful);
    
    
    // prompting user for input
    printf("plaintext: ");
    string plainText = get_string();
    int text_length = strlen(plainText);
   
    // converting plain text into cipher text and printing
    printf ("ciphertext: ");
    for (int i=0; i < text_length ; i++)
    {
        if (isalpha (plainText[i]))
        {
            if (isupper (plainText[i]))
            {
                printf ("%c", ((((int) plainText[i] - 65) + key) % 26) + 65 );
            }
            else
            {
                printf ("%c", ((((int) plainText[i] - 97) + key) % 26) + 97 );
            }
        }
        else
        {
            printf("%c",plainText[i]);
        }
    }
    printf("\n");
    return 0;
    
}