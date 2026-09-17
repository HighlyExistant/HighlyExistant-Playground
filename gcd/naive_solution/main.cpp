#include <stdio.h>


// This method of finding the gcd is very naive
// and lends itself to a time complexity of O(min(a,b))
int naive_gcd(int a, int b) {
    // Ensure a and b are positives
    if (a < 0) {
        a = a * -1;
    }
    if (b < 0) {
        b = b * -1;
    }
    // Use properties of gcd to quickly assess 0 case.
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    int minimum;
    if (a < b) {
        minimum = a;
    } else {
        minimum = b;
    }
    int i = 1;
    int greatest_common_factor = 1;

    while (i <= a)
    {
        if ((a % i == 0) && (b % i == 0)) {
            greatest_common_factor = i;
        }
        i = i + 1;
    }
    return greatest_common_factor;
}

int main(int argc, char const *argv[])
{
    int a;
    int b;
    printf("PRINT 1ST NUMBER: ");
    scanf("%d", &a);
    printf("PRINT 2ND NUMBER: ");
    scanf("%d", &b);
    printf("gcd(%d, %d) = %d", a, b, naive_gcd(a,b));
    return 0;
}
