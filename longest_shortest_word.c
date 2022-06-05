#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");
    
    char string[100], shortest[30], longest[30];;
    int count = 0, min, max = 0, i, j, index = 0, length;
    printf("Enter String: ");
    gets(string);
    length = strlen(string);
    index = 0;

    /* Initially set some large value to min */
    min = 100; // This is important

    
    for (i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            count++;
        }
        else
        {
            if (count > max)
            {
                max = count;
                index = i - max;
            }
            else if (count < min)
            {
                min = count;
                index = i - min;
            }
            count = 0;
        }
    }

    /* this is for shortest */

    /* Checking if last word is shortest */
    if (count < min)
    {
        min = count;
        index = length - min;
    }

    // copying shortest word to the char arr to display
    j = 0;
    for (i = index;i < index + min;i++)
    {
        shortest[j] = string[i];
        j++;
    }


    /* this is for longest */

    /* Checking if last word is longest */
    if (count > max)
    {
        max = count;
        index = length - max;
    }
    // copying longest word to the char arr to display
    j = 0;
    for (i = index;i < index + max;i++)
    {
        longest[j] = string[i];
        j++;
    }

    /* null char for terminating char */
    shortest[j] = '\0';
    longest[j] = '\0';

    printf("Shortest word is: %s\n", shortest);
    printf("And its length is %d\n", min);

    printf("Longest word is: %s\n", longest);
    printf("And its length is: %d", max);


    return 0;
}