#pragma once

#include <stdio.h>
#include <cassert>

void satisfies_properties(int(*gcd)(int, int)) {
    int list_a[] = { 50, 7, 5 };
    int list_b[] = { 20, 7, 15 };
    assert((gcd(list_a[0], list_b[0]) == 10, "Should have evaluated to 10"));
    assert((gcd(list_a[1], list_b[1]) == 7, "Should have evaluated to 7"));
    assert((gcd(list_a[2], list_b[2]) == 5, "Should have evaluated to 5"));

    assert((gcd(-50, -20) == gcd(50, 20), "Should be the same (10)"));
    assert((gcd(-50, 0) == 50, "Should be |-50|"));
    assert((gcd(20*34, -20*57) == 20*gcd(34, 57), "Should be |-50|"));
    
    printf("Passed Tests\n");
}