#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SLEN 30

typedef struct kindnode
{
    char kind[SLEN];
    struct kindnode *next;
} KindNode;

typedef struct petnode
{
    char name[SLEN];
    KindNode *kinds;
    struct petnode *left;
    struct petnode *right;
} PetNode;

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

static void tolower_str(char *s)
{
    for (; *s; s++)
        *s = (char)tolower((unsigned char)*s);
}

static KindNode *make_kind(const char *k)
{
    KindNode *p = (KindNode *)malloc(sizeof(KindNode));
    if (!p)
        return NULL;
    strncpy(p->kind, k, SLEN - 1);
    p->kind[SLEN - 1] = '\0';
    p->next = NULL;
    return p;
}

static int kind_exists(KindNode *head, const char *k)
{
    for (; head; head = head->next)
        if (strcmp(head->kind, k) == 0)
            return 1;
    return 0;
}

static void add_kind(KindNode **head, const char *k)
{
    if (kind_exists(*head, k))
        return; /* avoid duplicates */
    KindNode *p = make_kind(k);
    if (!p)
        return;
    p->next = *head;
    *head = p;
}

static void free_kinds(KindNode *head)
{
    while (head)
    {
        KindNode *t = head->next;
        free(head);
        head = t;
    }
}

static PetNode *make_petnode(const char *name, const char *kind)
{
    PetNode *p = (PetNode *)malloc(sizeof(PetNode));
    if (!p)
        return NULL;
    strncpy(p->name, name, SLEN - 1);
    p->name[SLEN - 1] = '\0';
    p->left = p->right = NULL;
    p->kinds = NULL;
    add_kind(&p->kinds, kind);
    return p;
}

static PetNode *find_name(PetNode *root, const char *name)
{
    while (root)
    {
        int cmp = strcmp(name, root->name);
        if (cmp == 0)
            return root;
        root = (cmp < 0) ? root->left : root->right;
    }
    return NULL;
}

static PetNode *insert_pet(PetNode *root, const char *name, const char *kind)
{
    if (!root)
        return make_petnode(name, kind);

    int cmp = strcmp(name, root->name);
    if (cmp == 0)
    {
        add_kind(&root->kinds, kind);
    }
    else if (cmp < 0)
    {
        root->left = insert_pet(root->left, name, kind);
    }
    else
    {
        root->right = insert_pet(root->right, name, kind);
    }
    return root;
}

static void list_all(const PetNode *root)
{
    if (!root)
        return;
    list_all(root->left);

    printf("%s: ", root->name);
    for (KindNode *k = root->kinds; k; k = k->next)
    {
        printf("%s", k->kind);
        if (k->next)
            printf(", ");
    }
    putchar('\n');

    list_all(root->right);
}

static void free_tree(PetNode *root)
{
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free_kinds(root->kinds);
    free(root);
}

static void show_kinds_of_name(PetNode *root)
{
    char name[SLEN];
    printf("Enter pet name: ");
    if (!s_gets(name, SLEN))
        return;
    tolower_str(name);

    PetNode *hit = find_name(root, name);
    if (!hit)
    {
        printf("No pets named '%s'.\n", name);
        return;
    }
    printf("Pets named '%s' include kinds: ", hit->name);
    for (KindNode *k = hit->kinds; k; k = k->next)
    {
        printf("%s", k->kind);
        if (k->next)
            printf(", ");
    }
    putchar('\n');
}

int main(void)
{
    PetNode *root = NULL;

    for (;;)
    {
        puts("\nPet Club Menu:");
        puts("a) add a pet (name + kind)");
        puts("l) list all pets (grouped by name)");
        puts("f) find by name (list all kinds)");
        puts("q) quit");
        printf("Choice: ");

        int ch = getchar();
        while (getchar() != '\n')
        {
        }

        if (ch == 'q')
            break;

        if (ch == 'a')
        {
            char name[SLEN], kind[SLEN];
            printf("Enter pet name: ");
            if (!s_gets(name, SLEN))
                continue;
            printf("Enter pet kind: ");
            if (!s_gets(kind, SLEN))
                continue;
            tolower_str(name);
            tolower_str(kind);

            root = insert_pet(root, name, kind);
            if (!root)
            {
                puts("Out of memory.");
                break;
            }
        }
        else if (ch == 'l')
        {
            if (!root)
                puts("No entries.");
            else
                list_all(root);
        }
        else if (ch == 'f')
        {
            show_kinds_of_name(root);
        }
        else
        {
            puts("Invalid choice.");
        }
    }

    free_tree(root);
    return 0;
}
