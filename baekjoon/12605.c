#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splength(char *str)
{
    int len = 1;
    int i = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            len++;
        i++;
    }
    return (len);
}

char **split(char *str)
{
    char **sp;
    int len = 1;
    int i = 0;
    int count = 0;
    int c = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            len++;
        i++;
    }
    sp = (char **)calloc(sizeof(char *), len);
    for (int l = 0; l < len; l++)
        sp[l] = (char *)calloc(sizeof(char), 25);
    i = 0;
    int j = 0;
    int k = 0;
    while (str[i])
    {
        k = 0;
        while (str[i] != ' ' && str[i])
        {
            sp[j][k] = str[i];
            k++;
            i++;
        }
        if (str[i] == ' '){
            i++;
            j++;
        }
    }
   // printf("sp[2] = %s\n", sp[]);
    return (sp);
}

int main(void)
{
    int c;
    scanf("%d", &c);
    while (getchar() != '\n');
    char **sp_str;
    char **str;
    int sp_len;

    str = (char **)calloc(sizeof(char *), c);
    for (int l = 0; l < c; l++)
        str[l] = (char *)calloc(sizeof(char), 50);
    for (int i = 0; i < c; i++){
        fgets(str[i], 50, stdin);
        for (int j = 0; str[i][j]; j++)
        {
            if (str[i][j] == '\n')
                str[i][j] = 0;
        }
        // fflush(stdin);
    }
    for (int i = 0; i < c; i++)
    {
        sp_str = split(str[i]);
        printf("Case #%d:", i + 1);
        sp_len = splength(str[i]);
        for (int k = 1; k <= sp_len; k++)
        {
            fprintf(stdout, " %s", sp_str[sp_len - k]);
            if (sp_len == k)
                printf("\n");
            // else
            //     printf(" ");
        }
    }
    return (0);
}
