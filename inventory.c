#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int read_line(char str[], int n);

int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
        case 'i':case'I': insert();
            break;
        case 's':case 'S': search();
            break;
        case 'u':case 'U': update();
            break;
        case 'p':case 'P': print();
            break;
        case 'q':case 'Q': return 0;
        default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}


int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}


void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}


void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
        printf("Part not found.\n");
}


void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        printf("Part not found.\n");
}


void print(void)
{
    int i, pos, prev_part_number = 0, num_printed;

    printf("Part Number   Part Name                  "
        "Quantity on Hand\n");

    for (num_printed = 0; num_printed < num_parts; num_printed++) {

        /* find any part that hasn't already been printed */
        for (i = 0; i < num_parts; i++)
            if (inventory[i].number > prev_part_number) {
                pos = i;
                break;
            }

        /* find the part with the smallest number that hasn't
           already been printed */
        for (; i < num_parts; i++)
            if (inventory[i].number < inventory[pos].number &&
                inventory[i].number > prev_part_number)
                pos = i;

        printf("%7d       %-25s%11d\n", inventory[pos].number,
            inventory[pos].name, inventory[pos].on_hand);

        prev_part_number = inventory[pos].number;
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;

    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}