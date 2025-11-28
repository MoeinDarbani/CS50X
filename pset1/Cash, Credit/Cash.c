#include <stdio.h>

int main()
{
    int money, valid;

    do
    {
        printf("Change owed: ");
        valid = scanf("%d", &money);

        if (!valid) // input was not numeric
        {
            money = -1;   // force loop to continue
            scanf("%*s"); // discard invalid input
        }
    }
    while (money <= 0);

    if (valid)
    {
        int f1, f2, f3, f4;

        f1 = money / 25;
        money %= 25;
        f2 = money / 10;
        money %= 10;
        f3 = money / 5;
        money %= 5;
        f4 = money / 1;

        int f = f1 + f2 + f3 + f4;

        printf("%d\n", f);
        return 0;
    }
    else
    {
        printf("Not Valid\n");
    }
}
