#include <stdio.h>
// One hot summer day Pete and his friend Billy decided to buy a watermelon. 
// They chose the biggest and the ripest one, in their opinion. After that 
// the watermelon was weighed, and the scales showed w kilos. They rushed 
// home, dying of thirst, and decided to divide the berry, however they 
// faced a hard problem.

// Pete and Billy are great fans of even numbers, that's why they want to divide 
// the watermelon in such a way that each of the two parts weighs even number of 
// kilos, at the same time it is not obligatory that the parts are equal. The boys 
// are extremely tired and want to start their meal as soon as possible, that's 
// why you should help them and find out, if they can divide the watermelon in 
// the way they want. For sure, each of them should get a part of positive weight.

// The first (and the only) input line contains integer number w 
// (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.

// Print YES, if the boys can divide the watermelon into two parts, each 
// of them weighing even number of kilos; and NO in the opposite case.

bool is_even(int number) {
    return (number & 1) == 0;
}

int main(int argc, char const *argv[])
{
    int weight = 0;
    scanf("%d", &weight);

    // The sum of 2 even numbers will be an even number
    // The sum of 1 even and 1 odd will be an odd number
    // The sum of 2 odd will be an even number
    //      2k+1 + 2h+1 => 2k+2h+2 => 2k+2(h+1) => 
    // This means that the sum of 2 odd numbers can be rewritten as the sum 
    // of two even numbers. That said when w=2 it will be an exception.
    if (weight == 2) {
        printf("NO");
        return 0;
    }
    if (is_even(weight))
    {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
