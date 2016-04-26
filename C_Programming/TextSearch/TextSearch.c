#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256

bool TextSearch(const char *text, const char *pattern);

int main(int argc, char **argv)
{
    char text[MAX_SIZE];
    char pattern[MAX_SIZE];

    printf("Insert the text \n");
    scanf("%s",text);

    printf("Insert the pattern \n");
    scanf("%s",pattern);

    printf("Text: %s Pattern: %s \n",text, pattern);

    bool result = TextSearch(text, pattern);
    printf("Found: %s \n", result ? "true" : "false");
    return 0;
}

bool TextSearch(const char *text, const char *pattern)
{
    size_t text_size = strlen(text);
    size_t pattern_size = strlen(pattern);
    bool status = false;
    int i, j;

    for(i=0; i < text_size ; i++) {
        for(j=0; j < pattern_size; j++)
            if(pattern[j] != text[i+j])
                break;

        if (j == pattern_size) {
            status = true;
            break;
        }
    }
    return status;
}
