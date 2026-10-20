#include <iostream>
#include <cstdint>

bool is_even(unsigned long long value) {
    return value % 2 == 0;
}

bool is_prime(unsigned long long value) {
    if (value == 2l)
        return true;
    if (value < 2l || is_even(value))
        return false;
    
    for (size_t i = 3; i*i <= value;i += 2)
    {

        if (value % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        unsigned long long value;
        scanf("%lld", &value);
        std::cout << value << " " << is_prime(value) << '\n';
    }
    // unsigned long long value = UINT64_MAX;
    // while (true)
    // {
    //     std::cout << "checking" << value << '\n';
    //     if (is_prime(value))
    //     {
    //         std::cout << value << " " << is_prime(value) << '\n';
    //         break;
    //     }
        
    //     value -= 1;
    // }
    return 0;
}
