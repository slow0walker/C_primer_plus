#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WLEN 60

typedef struct node
{
    char word[WLEN];
    long count;
    struct node *left, *right;
} Node;

static Node *make_node(const char *w)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
        return NULL;
    strncpy(p->word, w, WLEN - 1);
    p->word[WLEN - 1] = '\0';
    p->count = 1;
    p->left = p->right = NULL;
    return p;
}

static Node *insert(Node *root, const char *w)
{
    if (!root)
        return make_node(w);
    int cmp = strcmp(w, root->word);
    if (cmp == 0)
        root->count++;
    else if (cmp < 0)
        root->left = insert(root->left, w);
    else
        root->right = insert(root->right, w);
    return root;
}

static const Node *find(Node *root, const char *w)
{
    while (root)
    {
        int cmp = strcmp(w, root->word);
        if (cmp == 0)
            return root;
        root = (cmp < 0) ? root->left : root->right;
    }
    return NULL;
}

static void inorder(const Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%-20s %ld\n", root->word, root->count);
    inorder(root->right);
}

static void free_tree(Node *root)
{
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

static int next_word(FILE *fp, char *out, int max)
{
    int ch;

    while ((ch = fgetc(fp)) != EOF && !isalpha((unsigned char)ch))
    {
    }
    if (ch == EOF)
        return 0;

    int i = 0;
    do
    {
        if (i < max - 1)
            out[i++] = (char)tolower((unsigned char)ch);
        ch = fgetc(fp);
    } while (ch != EOF && isalpha((unsigned char)ch));

    out[i] = '\0';
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
    char filename[256];
    printf("Enter filename to read: ");
    if (!s_gets(filename, sizeof(filename)))
        return 1;

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("fopen");
        return 1;
    }

    Node *root = NULL;
    char w[WLEN];
    while (next_word(fp, w, WLEN))
    {
        root = insert(root, w);
        if (!root)
        {
            puts("Out of memory.");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    for (;;)
    {
        puts("\nMenu:");
        puts("1) List all words and counts");
        puts("2) Query a word");
        puts("3) Quit");
        printf("Choice: ");
        int c;
        if (scanf("%d", &c) != 1)
            break;
        while (getchar() != '\n')
        {
        }

        if (c == 1)
        {
            puts("\nWORD                 COUNT");
            puts("-------------------- -----");
            inorder(root);
        }
        else if (c == 2)
        {
            char q[WLEN];
            printf("Enter a word: ");
            if (!s_gets(q, WLEN))
                continue;
            for (char *p = q; *p; p++)
                *p = (char)tolower((unsigned char)*p);
            const Node *hit = (Node *)find(root, q);
            if (hit)
                printf("'%s' occurs %ld time(s).\n", hit->word, hit->count);
            else
                printf("'%s' not found.\n", q);
        }
        else if (c == 3)
        {
            break;
        }
        else
        {
            puts("Invalid choice.");
        }
    }

    free_tree(root);
    return 0;
}
