#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 宏定义掩码和偏移量
// 0: Underline (1 bit)
#define UNDERLINE_MASK 0x1UL
#define UNDERLINE_SHIFT 0
// 1: Italic (1 bit)
#define ITALIC_MASK 0x1UL
#define ITALIC_SHIFT 1
// 2: Bold (1 bit)
#define BOLD_MASK 0x1UL
#define BOLD_SHIFT 2
// 3-4: Alignment (2 bits)
#define ALIGN_MASK 0x3UL
#define ALIGN_SHIFT 3
// 5-11: Size (7 bits)
#define SIZE_MASK 0x7FUL
#define SIZE_SHIFT 5
// 12-19: ID (8 bits)
#define ID_MASK 0xFFUL
#define ID_SHIFT 12

enum Alignment
{
    LEFT,
    CENTER,
    RIGHT
};

// 字体设置的unsigned long 变量
typedef unsigned long FontSettings;

// 1. 获取bit field值
unsigned long get_field(FontSettings settings, unsigned long mask, int shift)
{
    return (settings >> shift) & mask;
}

// 2. 设置bit field值
void set_field(FontSettings *settings, unsigned long new_val, unsigned long mask, int shift)
{
    // 1. 清除旧值：用掩码取反后左移，再与当前设置做 & 运算
    *settings &= ~(mask << shift);
    // 2. 设置新值：新值与掩码做 & 运算（确保范围），再左移到指定位置，然后与当前设置做 | 运算
    *settings |= (new_val & mask) << shift;
}

// 3. 切换单一位 (用于 Bold/Italic/Underline)
void toggle_bit(FontSettings *settings, int shift)
{
    *settings ^= (1UL << shift);
}

void print_font_info_ul(FontSettings font);
void display_menu(void);
char get_choice(void);
void set_font_size(char choice, FontSettings *font);

int main()
{
    FontSettings font = 0;
    // 初始化默认值
    // 初始设置：ID=1, Size=12, Alignment=LEFT(0), B/I/U=off(0)
    set_field(&font, 1, ID_MASK, ID_SHIFT);          // ID=1
    set_field(&font, 12, SIZE_MASK, SIZE_SHIFT);     // Size=12
    set_field(&font, LEFT, ALIGN_MASK, ALIGN_SHIFT); // Align=LEFT

    char choice;

    while (true)
    {
        print_font_info_ul(font);
        display_menu();
        choice = get_choice();
        if (choice == 'q')
        {
            puts("Bye!");
            break;
        }
        set_font_size(choice, &font);
    }
    return 0;
}

// 打印字体信息
void print_font_info_ul(FontSettings font)
{
    const char *align_str[] = {"left", "center", "right"};

    unsigned long id = get_field(font, ID_MASK, ID_SHIFT);
    unsigned long size = get_field(font, SIZE_MASK, SIZE_SHIFT);
    unsigned long align = get_field(font, ALIGN_MASK, ALIGN_SHIFT);
    unsigned long bold = get_field(font, BOLD_MASK, BOLD_SHIFT);
    unsigned long italic = get_field(font, ITALIC_MASK, ITALIC_SHIFT);
    unsigned long underline = get_field(font, UNDERLINE_MASK, UNDERLINE_SHIFT);

    printf("\nID   SIZE    ALIGNMENT    B    I   U\n");
    printf("%2lu %4lu %9s %8s %4s %4s\n",
           id,
           size,
           align_str[align],
           bold ? "on" : "off",
           italic ? "on" : "off",
           underline ? "on" : "off");
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

void set_font_size(char choice, FontSettings *font)
{
    unsigned long new_val;
    char align_choice;

    switch (choice)
    {
    case 'f':
        printf("Enter font ID (0-255): ");
        scanf("%lu", &new_val);
        while (getchar() != '\n')
            ;
        if (new_val <= 255)
            set_field(font, new_val, ID_MASK, ID_SHIFT);
        else
            printf("Invalid ID. Must be between 0 and 255.\n");
        break;
    case 's':
        printf("Enter font size (0-127): ");
        scanf("%lu", &new_val);
        while (getchar() != '\n')
            ;
        if (new_val <= 127)
            set_field(font, new_val, SIZE_MASK, SIZE_SHIFT);
        else
            printf("Invalid size. Must be between 0 and 127.\n");
        break;
    case 'a':
        printf("Select alignment:\n");
        printf("l) left   c) center   r) right\n");
        align_choice = get_choice();
        if (align_choice == 'l')
            set_field(font, LEFT, ALIGN_MASK, ALIGN_SHIFT);
        else if (align_choice == 'c')
            set_field(font, CENTER, ALIGN_MASK, ALIGN_SHIFT);
        else if (align_choice == 'r')
            set_field(font, RIGHT, ALIGN_MASK, ALIGN_SHIFT);
        else
            printf("Invalid alignment choice.\n");
        break;
    case 'b':
        toggle_bit(font, BOLD_SHIFT);
        break;
    case 'i':
        toggle_bit(font, ITALIC_SHIFT);
        break;
    case 'u':
        toggle_bit(font, UNDERLINE_SHIFT);
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}