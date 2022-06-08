#define _CRT_SECURE_NO_WARNINGS

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part* next; // The part structure will contain an additional member (a pointer to the next node)
};

struct part* inventory = NULL;   /* points to first part */ //inventory will point to the first node in the list

struct part* find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
        case 'i': insert();
            break;
        case 's': search();
            break;
        case 'u': update();
            break;
        case 'p': print();
            break;
        case 'd': dump();
            break;
        case 'r': restore();
            break;
        case 'q': return 0;
        default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}


/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            list. Returns a pointer to the node         *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part* find_part(int number)
{
    struct part* p;
    //find_partâ€™s search loop
    for (p = inventory;
        p != NULL && number > p->number;
        p = p->next)
        ;
    //When the loop terminates, weâ€™ll need to test whether the part was found
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
    struct part* cur, * prev, * new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    //The new version must determine where the new part belongs in the list and insert it there.
    //It will also check whether the part number is already present in the list.
    for (cur = inventory, prev = NULL;
        cur != NULL && new_node->number > cur->number;
        prev = cur, cur = cur->next)
        ;
    // Once the loop terminates, insert will check whether cur isnâ€™t NULL and whether new_node->number equals cur->number.
    if (cur != NULL && new_node->number == cur->number) { // If both are true, the part number is already in the list
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    //Otherwise, insert will insert a new node between the nodes pointed to by prev and cur.
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
    int number;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else
        printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
    int number, change;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else
        printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Part numbers will appear in   *
 *        ascending order.                                *
 **********************************************************/
void print(void)
{
    struct part* p;

    printf("Part Number   Part Name                  "
        "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d       %-25s%11d\n", p->number, p->name,
            p->on_hand);
}
/**********************************************************
 * dump: Saves the database in a specified file.          *
 **********************************************************/
void dump(void)
{
  FILE *fp;
  char filename[FILENAME_MAX+1];
  struct part *p;

  printf("Enter name of output file: ");
  read_line(filename, FILENAME_MAX);

  if ((fp = fopen(filename, "wb")) == NULL) {
    printf("Can't open %s\n", filename);
    return;
  }

  for (p = inventory; p != NULL; p = p->next)
    fwrite(p, offsetof(struct part, next), 1, fp);

  fclose(fp);
}

/**********************************************************
 * restore: Loads the database from a specified file.     *
 **********************************************************/
void restore(void)
{
  FILE *fp;
  char filename[FILENAME_MAX+1];
  struct part *head, *new_node, *tail = NULL;

  printf("Enter name of input file: ");
  read_line(filename, FILENAME_MAX);

  if ((fp = fopen(filename, "rb")) == NULL) {
    printf("Can't open %s\n", filename);
    return;
  }

  while (inventory != NULL) {
    head = inventory;
    inventory = inventory->next;
    free(head);
  }

  for (;;) {
    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
      printf("Database is full; can't add more parts.\n");
      break;
    }
    if (fread(new_node, offsetof(struct part, next), 1, fp) == 1) {
      new_node->next = NULL;
      if (tail == NULL) {
        inventory = new_node;
        tail = new_node;
      } else {
        tail->next = new_node;
        tail = new_node;
      }
    } else {
      free(new_node);
      break;
    }
  }

  fclose(fp);
}
/**********************************************************
 * read_line: Skips leading white-space characters, then  *
 *            reads the remainder of the input line and   *
 *            stores it in str. Truncates the line if its *
 *            length exceeds n. Returns the number of     *
 *            characters stored.                          *
 **********************************************************/
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