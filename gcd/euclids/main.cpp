#include <stdio.h>

// This method of finding the gcd is very fast
// compared to the naive version, coming to around
// O(log(min(a,b))) worst case.
int euclid_gcd(int a, int b) {
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
    int i = 1;
    int remainder = -1;
    int minimum;
    int maximum;
    if (a < b) {
        minimum = a;
         maximum = b;
    } else {
        minimum = b;
        maximum = a;
    }
    
    while (remainder != 0) {
        remainder = maximum % minimum;
        maximum = minimum;
        minimum = remainder;
    }
    return maximum;
}

int main(int argc, char const *argv[])
{
    int a;
    int b;
    printf("PRINT 1ST NUMBER: ");
    scanf("%d", &a);
    printf("PRINT 2ND NUMBER: ");
    scanf("%d", &b);
    printf("gcd(%d, %d) = %d", a, b, euclid_gcd(a,b));
    return 0;
}
