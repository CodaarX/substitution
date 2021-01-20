#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>


int main(int argc, string argv[])
{
    // outline alphabets for mapping
    char CLETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char cletters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // check if key is null
    if (argv[1] == NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get length of key
    int argv_length = strlen(argv[1]);

    // ensure that key is provided and argument counts 26
    if (argc != 2 || argv_length != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < j; k++)
            {
                // This loop checks if the current letter of the key is a duplicate
                if (argv[1][j] == argv[1][k])
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }


            // check if key contains invalid characters
            if (!((argv[1][j] >= 'a') && (argv[1][j] <= 'z')))
            {
                if (!((argv[1][j] >= 'A') && (argv[1][j] <= 'Z')))
                {
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
                }
            }
        }


        // get plain text for encryption
        string words = get_string("plaintext: ");

        // get lenght of plain text
        int word_length = strlen(words);


        for (int i = 0; i < word_length; i++)
        {
            // ensure word is a letter
            if (((words[i] >= 'a') && (words[i] <= 'z')))
            {
                for (int l = 0; l < argv_length; l++)
                {
                    // map a character to its position in the alphabet
                    if (words[i] == cletters[l])
                    {
                        // map that same letter to  its position in key
                        words[i] = argv[1][l];
                        words[i] = tolower(words[i]);
                        break;
                    }
                }
            }


            // ensure word is a letter
            else if ((words[i] >= 'A') && (words[i] <= 'Z'))
            {
                for (int m = 0; m < argv_length; m++)
                {
                    // map a character to its position in the alphabet
                    if (words[i] == CLETTERS[m])
                    {
                        // map that same letter to  its position in key
                        words[i] = argv[1][m];
                        words[i] = toupper(words[i]);
                        break;
                    }
                }
            }
        }

        printf("ciphertext: %s", words);
        printf("\n");
        return 0;
    }
}
