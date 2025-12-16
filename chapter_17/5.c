#include <stdio.h>
#include <string.h>

#define MAX 1024

typedef struct
{
    char data[MAX];
    int top;
} Stack;

static void init(Stack *s) { s->top = 0; }
static int empty(const Stack *s) { return s->top == 0; }
static int full(const Stack *s) { return s->top >= MAX; }
static int push(Stack *s, char c)
{
    if (full(s))
        return 0;
    s->data[s->top++] = c;
    return 1;
}
static int pop(Stack *s, char *out)
{
    if (empty(s))
        return 0;
    *out = s->data[--s->top];
    return 1;
}

static char *s_gets(char *st, int n)
{
    char *ret = fgets(st, n, stdin);
    if (!ret)
        return NULL;
    char *p = strchr(st, '\n');
    if (p)
        *p = '\0';
    else
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
    return ret;
}

int main(void)
{
    char line[MAX];
    Stack st;
    init(&st);

    puts("Enter a string:");
    if (!s_gets(line, MAX))
        return 0;

    for (size_t i = 0; i < strlen(line); i++)
    {
        if (!push(&st, line[i]))
        {
            puts("Stack overflow!");
            return 1;
        }
    }

    puts("Reversed:");
    char ch;
    while (pop(&st, &ch))
        putchar(ch);
    putchar('\n');
    return 0;
}
