#include <stdio.h>

int main(void)
{
    int a = 10;
    float b = 3.14f;
    double c = 2.71828;
    char d = 'A';

    printf("Valores:\n");
    printf("int: %d\n", a);
    printf("float: %.2f\n", b);
    printf("double: %lf\n", c);
    printf("char: %c\n", d);

    printf("\nTamaños en memoria (bytes):\n");
    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(float): %zu\n", sizeof(float));
    printf("sizeof(double): %zu\n", sizeof(double));
    printf("sizeof(char): %zu\n", sizeof(char));

    return 0;
}
