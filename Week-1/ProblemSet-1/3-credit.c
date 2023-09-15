#include <cs50.h>
#include <stdio.h>

int main(void) {
    long card;
    do card = get_long("Number: ");
    while (card <= 0);

    bool flag = false;
    int length = 0;
    int checksum = 0;
    int head_bit;
    int last_bit;

    while (true) {
        last_bit = card % 10;
        if (flag) {
            last_bit *= 2;
            if (last_bit > 9) {
                last_bit -= 9;
            }
        }

        card = card / 10;
        if (card >= 10 && card <= 99) {
            head_bit = card;
        }
        checksum += last_bit;
        length++;
        flag = !flag;
        if (card == 0)
            break;
    }
    
    if (checksum % 10 != 0)
        printf("INVALID\n");
    else if ((head_bit == 34 || head_bit == 37) && length == 15)
        printf("AMEX\n");
    else if (head_bit >= 51 && head_bit <= 55 && length == 16)
        printf("MASTERCARD\n");
    else if (head_bit >= 40 && head_bit <= 49 && (length == 13 || length == 16))
        printf("VISA\n");
    else
        printf("INVALID\n");
}
