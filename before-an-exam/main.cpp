#include <iostream>
#include <vector>
// Input
// The first input line contains two integer numbers d, sumTime 
// (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during 
// which Peter studied, and the total amount of hours, spent on 
// preparation. Each of the following d lines contains two integer 
// numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), 
// separated by a space — minimum and maximum amount of hours that 
// Peter could spent in the i-th day.
// 
// Output
// In the first line print YES, and in the second line print d numbers 
// (separated by a space), each of the numbers — amount of hours, 
// spent by Peter on preparation in the corresponding day, if he 
// followed his parents' instructions; or print NO in the unique line. 
// If there are many solutions, print any of them.
int main(int argc, char const *argv[])
{
    
    int min_sum = 0, max_sum = 0;
    int d, sum_time;
    scanf("%d %d", &d, &sum_time); // 1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240

    std::vector<int> time_min_list = {};
    std::vector<int> time_max_list = {};
    std::vector<int> time_per_day = {};
    for (size_t i = 0; i < d; i++)
    {
        int min_time, max_time;
        scanf("%d %d", &min_time, &max_time); // 0 <= min <= max <= 8
        time_min_list.push_back(min_time);
        time_max_list.push_back(max_time);
        // Assume min_time is the sum, which will help us later
        time_per_day.push_back(min_time);

        // Obtain the min sum and max sum.
        min_sum += min_time;
        max_sum += max_time;
    }
    // if sum_time is not between min_sum <= sum_time <= max_sum
    // then it is not possible to reach the sum.
    if (!(min_sum <= sum_time && sum_time <= max_sum))
    {
        printf("NO");
        return 0;
    }
    int current_sum = min_sum;
    for (size_t i = 0; i < d; i++)
    {
        int min_time = time_min_list[i], max_time = time_max_list[i];
        int max_estimate = current_sum - min_time + max_time;
        if (max_estimate >= sum_time) // Number is over the range when in max, so the number we choose must be between range
        {
            time_per_day[i] += sum_time-current_sum;
            break; // Process should be finished
        }
        current_sum = max_estimate;
        time_per_day[i] = max_time;
    }
    printf("YES\n");
    for (size_t i = 0; i < d-1; i++)
    {
        printf("%d ", time_per_day[i]);
    }
    printf("%d", time_per_day[d-1]);
    return 0;
}
