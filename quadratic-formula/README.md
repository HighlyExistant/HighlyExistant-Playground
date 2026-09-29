# The Quadratic Formula
Here is a very basic implementation of the quadratic formula.
``` C++
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
```
It first checks the discriminant to see the number of solutions that it can contain, and then it solves it using the formula. The result is contained in `x_0` and `x_1`.