#include <math.h>
#include <stdio.h>

int solve_quadratic(float a, float b, float c, float &x_0, float &x_1) {
    float discriminant = b*b - 4.0*a*c;
    if (discriminant > 0.0)
    {
        float sqrt_d = sqrt(discriminant);
        float two_a = 2.0*a;
        x_0 = (-b + sqrt_d)/two_a;
        x_1 = (-b - sqrt_d)/two_a;
        return 2;
    } else if (discriminant == 0.0) {
        x_0 = -b/(2.0*a);
        return 1;
    } else {
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    float a, b, c, x_0, x_1;
    scanf("%f %f %f", &a, &b, &c);
    int solution_count = solve_quadratic(a, b, c, x_0, x_1);
    printf("Solution count %d\n", solution_count);
    if (solution_count == 2)
    {
        printf("x_0 = %f, x_1 = %f\n", x_0, x_1);
    } else if (solution_count == 1) {
        printf("x_0 = %f\n", x_0);
    }
    
    return 0;
}
