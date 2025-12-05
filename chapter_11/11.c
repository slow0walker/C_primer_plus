#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 10
#define LEN 80

void show_menu(void);
int get_int(void);
char *s_gets(char *st, int n);
// choice1:print the original list of strings
void show_oringinal(char *ptstr[], int ct);

// choice2:print the strings in ASCII order
void show_Ascii_order(char *ptstr[], int ct);

// choice3:print the strings in order of increasing length
void show_length_order(char *ptstr[], int ct);

// choic4: print the strings in order of the length of the first word in the string
int first_word_len(const char *s);
void show_first_word_order(char *ptstr[], int ct);

int main()
{
    char input[MAX_STR][LEN];
    char *ptstr[MAX_STR];
    int ct = 0; // input count

    printf("Enter up to %d strings (empty line to stop):\n", MAX_STR);
    while (ct < MAX_STR && s_gets(input[ct], LEN) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    show_menu();
    int choice = get_int();

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            show_oringinal(ptstr, ct);
            break;
        case 2:
            show_Ascii_order(ptstr, ct);
            break;
        case 3:
            show_length_order(ptstr, ct);
            break;
        case 4:
            show_first_word_order(ptstr, ct);
            break;
        case 5:
            puts("Goodbye!");
            break;
        default:
            printf("Sorry, but %d is an invalid choice,please try again.\n", choice);
        }
        show_menu();
        choice = get_int();
    }
}

void show_menu(void)
{
    printf("***************Menu:****************\n");
    printf("1) Print original list\n");
    printf("2) Print strings in ASCII order\n");
    printf("3) Print strings by length\n");
    printf("4) Print strings by length of first word\n");
    printf("5) Quit\n");
    printf("Enter choice: ");
}

int get_int(void)
{
    int input;
    printf("Enter your choice: ");
    while (scanf("%d", &input) != 1)
    {
        while (getchar() != '\n')
            continue;
        printf("Please enter an integer: ");
    }
    return input;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void show_oringinal(char *ptstr[], int ct)
{
    for (int i = 0; i < ct; i++)
    {
        puts(ptstr[i]);
    }
}

void show_Ascii_order(char *ptstr[], int ct)
{
    char *temp[MAX_STR];
    for (int i = 0; i < ct; i++)
    {
        temp[i] = ptstr[i];
    }
    for (int i = 0; i < ct - 1; i++)
    {
        for (int j = i + 1; j < ct; j++)
        {
            if (strcmp(temp[i], temp[j]) > 0)
            {
                char *temp2 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp2;
            }
        }
    }
    for (int i = 0; i < ct; i++)
    {
        puts(temp[i]);
    }
}

void show_length_order(char *ptstr[], int ct)
{
    char *temp[MAX_STR];
    for (int i = 0; i < ct; i++)
    {
        temp[i] = ptstr[i];
    }
    for (int i = 0; i < ct - 1; i++)
    {
        for (int j = i + 1; j < ct; j++)
        {
            if (strlen(temp[i]) > strlen(temp[j]))
            {
                char *temp2 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp2;
            }
        }
    }
    for (int i = 0; i < ct; i++)
    {
        puts(temp[i]);
    }
}

int first_word_len(const char *s)
{
    int len = 0;
    while (isspace(*s))
    {
        s++;
    }
    while (*s && !isspace(*s))
    {
        len++;
        s++;
    }
    return len;
}

void show_first_word_order(char *ptstr[], int ct)
{
    char *temp[MAX_STR];
    for (int i = 0; i < ct; i++)
    {
        temp[i] = ptstr[i];
    }
    for (int i = 0; i < ct - 1; i++)
    {
        for (int j = i + 1; j < ct; j++)
        {
            if (first_word_len(temp[i]) > first_word_len(temp[j]))
            {
                char *temp2 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp2;
            }
        }
    }
    for (int i = 0; i < ct; i++)
    {
        puts(temp[i]);
    }
}