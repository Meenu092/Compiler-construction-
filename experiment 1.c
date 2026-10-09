#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter a C statement: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (isspace((unsigned char)str[i]))
        {
            i++;
            continue;
        }

        if (isalpha((unsigned char)str[i]) || str[i] == '_')
        {
            char word[50];
            int j = 0;

            while (isalnum((unsigned char)str[i]) || str[i] == '_')
            {
                word[j++] = str[i++];
            }

            word[j] = '\0';

            if (strcmp(word, "int") == 0 ||
                strcmp(word, "float") == 0 ||
                strcmp(word, "char") == 0 ||
                strcmp(word, "if") == 0 ||
                strcmp(word, "else") == 0 ||
                strcmp(word, "while") == 0 ||
                strcmp(word, "return") == 0)
            {
                printf("%s : Keyword\n", word);
            }
            else
            {
                printf("%s : Identifier\n", word);
            }
        }
        else if (isdigit((unsigned char)str[i]))
        {
            char number[50];
            int j = 0;

            while (isdigit((unsigned char)str[i]) || str[i] == '.')
            {
                number[j++] = str[i++];
            }

            number[j] = '\0';
            printf("%s : Constant\n", number);
        }
        else if (strchr("+-*/%=<>!", str[i]) != NULL)
        {
            printf("%c : Operator\n", str[i]);
            i++;
        }
        else
        {
            printf("%c : Special Symbol\n", str[i]);
            i++;
        }
    }

    return 0;
}
