#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 3;

    printf("Operaciones con enteros:\n");
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);

    float a = 10.0f;
    float b = 3.0f;

    printf("\nOperaciones con float:\n");
    printf("a / b = %.2f\n", a / b);

    printf("\nTamaños:\n");
    printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("char: %zu bytes\n", sizeof(char));

    return 0;
}
