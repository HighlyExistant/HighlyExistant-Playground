#include <iostream>
typedef long long int i64;
i64 div_ceil(i64 a, i64 b) {
    return (a+b-1)/b;
}
/// @brief This assumes that ind_cost < grp_cost < ind_cost*3.
/// @param ind_cost 
/// @param grp_cost 
/// @param count 
/// @return Max cost for case 3
i64 min_cost_case_3(i64 ind_cost, i64 grp_cost, i64 count) {
    if (count <= 0) {
        return 0;
    }
    int grp_count;
    // This can be either 0 or the number of individual groups.
    // if it is 0, it means count is either 1 or 2. If it it not
    // 0, then it is 3 or more.
    grp_count = count/3;
    if (grp_count == 0)
    {
        // Check whether it is cheaper to get individual tickets or 1 group ticket
        switch (count)
        {
        case 1: // Single person
            if (ind_cost < grp_cost)
            {
                return ind_cost;
            } else {
                return grp_cost;
            }
            break;
        case 2: // Two people
            if (ind_cost*2 < grp_cost)
            {
                return ind_cost*2;
            } else {
                return grp_cost;
            }
            break;
        default:
            break;
        }
    }
    // ind_count = count-(grp_count*3);
    // if (ind_count < 0) {
    //     ind_count = 0;
    // }
    // return grp_count*grp_cost+ind_count*ind_cost;
    return grp_count*grp_cost + min_cost_case_3(ind_cost, grp_cost, count-(grp_count*3));
}
// SOLVE TEST CASE 5 3 5
i64 min_cost(i64 ind_cost, i64 grp_cost, i64 count) {
    i64 ind_count = 0;
    i64 grp_count = 0;
    // Cases Identified:
    // 3a <= b
    // a < b < 3a
    // b <= a
    
    // if 3 individual tickets are cheaper than group tickets,
    // then just buy individual tickets and end early
    // 3a <= b
    if (ind_cost * 3 <= grp_cost)
    {
        ind_count = count;
        return ind_cost*count;
    } else if (grp_cost <= ind_cost) { // terrible business model b <= a
        grp_count = div_ceil(count, 3);
    } else { // regular business model a < b < 3a
        return min_cost_case_3(ind_cost, grp_cost, count);
    }
    return grp_count*grp_cost+ind_count*ind_cost;
}

int main(int argc, char const *argv[])
{
    i64 t;
    scanf("%lli", &t);

    for (int i = 0; i < t; i++)
    {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        std::cout << min_cost((i64)a, (i64)b, (i64)n) << '\n';
    }
    
    return 0;
}
