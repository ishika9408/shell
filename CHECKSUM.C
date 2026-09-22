#include <stdio.h>
#include <string.h>

int main()
{
    char a[20], b[20];
    int i, carry = 0, sum[20];

    printf("Enter first binary number: ");
    scanf("%s", a);

    printf("Enter second binary number: ");
    scanf("%s", b);

    /* Binary addition from right to left */
    for(i = strlen(a) - 1; i >= 0; i--)
    {
        int x = a[i] - '0';
        int y = b[i] - '0';

        int s = x + y + carry;

        sum[i] = s % 2;
        carry = s / 2;
    }

    /* End-around carry */
    if(carry == 1)
    {
        for(i = strlen(a) - 1; i >= 0; i--)
        {
            int s = sum[i] + carry;
            sum[i] = s % 2;
            carry = s / 2;

            if(carry == 0)
                break;
        }
    }

    printf("Sum = ");
    for(i = 0; i < strlen(a); i++)
        printf("%d", sum[i]);

    /* 1's complement */
    printf("\nChecksum = ");
    for(i = 0; i < strlen(a); i++)
        printf("%d", sum[i] == 0 ? 1 : 0);

    return 0;
}