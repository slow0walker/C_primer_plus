#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 字体信息结构体
struct FontInFo
{
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int align : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

// 对齐方式
enum Alignment
{
    LEFT,
    CENTER,
    RIGHT
};

void display_menu(void);
void print_font_info(const struct FontInFo *font);
char get_choice(void);
void set_font_size(char choice, struct FontInFo *font);

int main()
{
    struct FontInFo font = {1, 12, LEFT, 0, 0, 0};
    char choice;

    while (true)
    {
        print_font_info(&font);
        display_menu();
        choice = get_choice();
        if (choice == 'q')
            break;
        set_font_size(choice, &font);
    }
    return 0;
}

void print_font_info(const struct FontInFo *font)
{
    const char *align_str[] = {"left", "center", "right"};

    printf("\nID   SIZE    ALIGNMENT    B    I   U\n");
    printf("%2u %4u %9s %8s %4s %4s\n",
           font->id,
           font->size,
           align_str[font->align],
           font->bold ? "on" : "off",
           font->italic ? "on" : "off",
           font->underline ? "on" : "off");
}

void display_menu(void)
{
    puts("\nf) change font   s) change size   a) change alignment");
    puts("b) toggle bold   i) toggle italic  u) toggle underline");
    puts("q) quit");
    printf("Enter your choice: ");
}

char get_choice(void)
{
    char ch;
    ch = getchar();
    while (getchar() != '\n')
        ;
    return ch;
}

void set_font_size(char choice, struct FontInFo *font)
{
    unsigned int new_val;
    char align_choice;

    switch (choice)
    {
    case 'f':
        printf("Enter font ID (0-255): ");
        scanf("%u", &new_val);
        while (getchar() != '\n')
            ;
        if (new_val <= 255)
            font->id = new_val & 0xFF;
        else
            printf("Invalid font ID. Must be between 0 and 255.\n");
        break;
    case 's':
        printf("Enter font size (0-127): ");
        scanf("%u", &new_val);
        while (getchar() != '\n')
            ;
        if (new_val <= 127)
            font->size = new_val & 0x7F;
        else
            printf("Invalid font size. Must be between 0 and 127.\n");
        break;
    case 'a':
        printf("Select alignment:\n");
        printf("l) left   c) center   r) right\n");
        align_choice = get_choice();
        switch (align_choice)
        {
        case 'l':
            font->align = LEFT;
            break;
        case 'c':
            font->align = CENTER;
            break;
        case 'r':
            font->align = RIGHT;
            break;
        default:
            printf("Invalid alignment choice.\n");
        }
        break;
    case 'b':
        font->bold = !font->bold;
        break;
    case 'i':
        font->italic = !font->italic;
        break;
    case 'u':
        font->underline = !font->underline;
        break;
    default:
        printf("Invalid choice.\n");
    }
}