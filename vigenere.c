#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char caesar(char text, int key);

int main(int argc, string argv[])
{
    /** variable declaration **/
    bool keySuccessful = false;
    string key = "";
    int keyCount = 0;
    
    /** validation of arguments **/
    
    do
    {
        // The number of command line args submitted was incorrect. 
        if (argc != 2)
        {
            printf("ERROR\n");
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            printf("We require a string as encryption key.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if (!isalpha(argv[1][i]))
                {
                    /** rejection if characters not found **/
                    printf("Invalid arguments, enter only characters\n");
                    return 1;
                }
                else
                {
                    /** valid input recieved **/
                    keySuccessful = true;
                    key = argv[1];
                }
            }
        }
    } while(!keySuccessful);
    
    int keylen = strlen(argv[1]);
    
    /** copying of each key into new variable **/
    int keyword[keylen];
    for(int i = 0; i < keylen; i++)
    {
        keyword[i] = toupper(key[i]) - 65;
    }
    
    
    /** getting user input and calculating its length**/
    printf("plaintext: ");
    string plainText = get_string();
    int text_length = strlen(plainText);
    
    /** printing of cipher text **/
    printf ("ciphertext: ");
    for (int i=0; i < text_length ; i++)
    {
        if (isalpha (plainText[i]))
        {
            printf ("%c", caesar(plainText[i], keyword[keyCount]));
            if (keyCount < keylen - 1)
            {
                keyCount++;
            }
            else
            {
                keyCount = 0;
            }
        }
        else
        {
            /** input is not alphabet, mirror it**/
            printf("%c",plainText[i]);
        }
    }
    printf("\n");
    return 0;
    
}
    
char caesar(char text, int key)
{
    if (isupper (text))
    {
        return(((((int) text - 65) + key) % 26) + 65);
    }
    else
    {
        return(((((int) text - 97) + key) % 26) + 97);
    }
}