#include <stdio.h>
#include <string.h>

int anagram(char *str1, char *str2);


int main(int argc, char **argv)
{
    char string1[] = "algoritmo";
    char string2[] = "logaritmo";

    if(!anagram(string1, string2))
        printf("%s is an anagram of %s \n", string2, string1);
    else
        printf("%s is not an anagram \n", string2);

    return 0;
}

int anagram(char *str1, char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return 1;

    size_t str_size1 = strlen(str1);
    size_t str_size2 = strlen(str2);
    int alpha[27] = {};

    if(str_size1 != str_size2)
        return 1;

    int i;
    for(i = 0; str1[i] != '\0'; i++){
        alpha[str1[i] - 'a']++;
        alpha[str2[i] - 'a']--;
    }

    for(i = 0; i < 27; i++)
        if(alpha[i] != 0){
            return 1;
        }

    return 0;
}




