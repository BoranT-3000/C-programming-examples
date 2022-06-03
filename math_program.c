#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfect(int a);
int check_prime(int n);
int convert_binary(long long n);
long long convert_decimal(int n);


int main(void) {


    int selection;
    int long long n;
    int a, result;
    int x, s, num, sum = 0, i;
    double q, w, e, discriminant, root1, root2, realPart, imagPart;

    while (1) {
        printf("\n\t   **SELECT OPTION BELOW**\n");
        printf("\t################################\n");
        printf("\t1-write function to calculate the formula 1 + x/1 + x^2/2 + x^3/3 + ....+ x^n/n\n");
        printf("\t2-Roots of quadratic formula..\n");
        printf("\t3-perfect number function..\n");
        printf("\t4-prime number function..\n");
        printf("\t5-convert binary to decimal..\n");
        printf("\t6-convert decimal to binary..\n");
        printf("\t7-Exit..\n");
        printf("\t--> ");
        scanf_s("%d", &selection);



        switch (selection) {

        case 1:
            printf("1+x+x^2+……+x^n\n");
            printf("Enter the value of x and n:");
            scanf_s("%d%lld", &x, &n);
            for (i = 1;i <= n;++i)
                sum += pow(x, i);
            sum++;
            printf("Sum=%d\n\n", sum);

            break;

        case 2:
            printf("Enter coefficients a, b and c: ");
            scanf_s("%lf %lf %lf", &q, &w, &e);
            discriminant = q * q - 4 * w * e;

            // condition for real and different roots
            if (discriminant > 0) {
                root1 = (-w + sqrt(discriminant)) / (2 * q);
                root2 = (-w - sqrt(discriminant)) / (2 * q);
                printf("root1 = %.2lf and root2 = %.2lf \n", root1, root2);
            }

            // condition for real and equal roots
            else if (discriminant == 0) {
                root1 = root2 = -w / (2 * q);
                printf("root1 = root2 = %.2lf \n", root1);
            }

            // if roots are not real
            else {
                realPart = -w / (2 * q);
                imagPart = sqrt(-discriminant) / (2 * q);
                printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi\n", realPart, imagPart, realPart, imagPart);

            }

            break;

        case 3:
            printf("Give an integer number: ");
            scanf_s("%d", &num);
            s = perfect(num);
            if (s == num)
                printf("\nThe given number %d is a perfect number\n", num);
            else
                printf("\nThe given number %d is not a perfect number\n", num);

            break;


        case 4:
            printf("Enter an integer to check whether it is prime or not:");
            scanf_s("%d", &a);

            result = check_prime(a);

            if (result == 1)
                printf("%d is prime.\n\n", a);
            else
                printf("%d is not prime.\n", a);
            break;


        case 5:
            printf("enter a binary number:\n");
            scanf_s("%lld", &n);
            printf("%lld in binary =%d in decimal\n", n, convert_binary(n));
            break;

        case 6:
            printf("Enter a decimal number: ");
            scanf_s("%d", &x);
            printf("%d in decimal = %lld in binary\n", x, convert_decimal(x));
            return 0;
            break;

        case 7:
            exit(0);
            break;

        default:printf("others will come with your progress\n");break;
        }
    }
    system("Pause");
    return 0;
}

long long convert_decimal(int n) {
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n\n", step++, n, rem, n / 2);
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

int convert_binary(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec = dec + rem * pow(2, i);
        i++;
    }
    return dec;
}

int check_prime(int a) {
    int c;
    for (c = 2;c <= a - 1;c++) {
        if (a % c == 0) {
            return 0;
        }
    }
    return 1;
}

int perfect(int number) {
    int sum = 0;
    int a = 1;
    while (a < number) {
        if (number % a == 0)
            sum = sum + a;
        a++;
    }
    return(sum);

    return sum;
}

