#include <stdio.h>

int main(void)
{
    long long int card_num;
    int valid;
    long long int temp;

    // Asking_For_CardNum
    do
    {
        printf("Enter Your Card Number: ");
        valid = scanf("%lld", &card_num);
        if (!valid)
        {

            scanf("%*s");
            card_num = -1;
        }
    }
    while (card_num < 0);

    temp = card_num;

    // Luhn
    int sum_1 = 0;
    int sum_2 = 0;
    int total = 0;
    int count = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (count % 2 == 0)
        {
            sum_1 += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum_2 += (doubled / 10) + (doubled % 10);
        }
        temp /= 10;
        count++;
    }

    total = sum_1 + sum_2;
    if (total % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    if (valid == 0)
    {
        printf("INVALID\n");
    }

    else if (valid == 1)
    {
        // Card_NO
        int i = 0;
        temp = card_num;
        while (temp > 0)
        {
            temp /= 10;
            i++;
        }
        temp = card_num;
        if (i == 13)
        {
            do
            {
                temp /= 10;
            }
            while (temp > 9);

            if (temp == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (i == 16)
        {
            temp = card_num;
            do
            {
                temp /= 10;
            }
            while (temp > 99);

            if (temp != 51 && temp != 52 && temp != 53 && temp != 54 && temp != 55)
            {
                do
                {
                    temp /= 10;
                }
                while (temp > 9);

                if (temp == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("MASTERCARD\n");
            }
        }

        else if (i == 15)
        {
            temp = card_num;

            do
            {
                temp /= 10;
            }
            while (temp > 99);

            if (temp == 34 || temp == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }
}
