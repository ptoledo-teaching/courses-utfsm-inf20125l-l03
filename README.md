# L03: Edición con vim y compilación en C

Esta sesión introduce el uso básico del editor `vim` junto con el flujo mínimo de desarrollo en C: edición, compilación y ejecución desde la terminal.

A diferencia de sesiones anteriores centradas en la terminal, aquí se incorpora el primer ciclo completo de desarrollo: escribir código, compilarlo y ejecutarlo.

## Prerrequisitos

- Tener sesión iniciada en la VM Lubuntu del equipo asignado
- Tener disponible el compilador `gcc`
- Haber trabajado previamente con comandos básicos de terminal

## Objetivo general

- Editar archivos de texto usando `vim`
- Comprender operaciones básicas de edición en un editor modal
- Escribir, compilar y ejecutar un programa simple en C usando el estándar C11
- Extender el programa para trabajar con tipos de datos, operaciones aritméticas y `sizeof`

## Objetivos específicos

- Abrir archivos con `vim`
- Entrar y salir del modo inserción
- Salir guardando y salir sin guardar
- Copiar, pegar, eliminar líneas y deshacer cambios
- Escribir un programa `Hello, World!` en C
- Compilar desde la terminal con `gcc -std=c11`
- Ejecutar el binario generado
- Extender el programa para mostrar operaciones básicas y tamaños de tipos de datos

## Metodología

A lo largo de esta sesión se trabajará directamente sobre archivos de código fuente en C usando `vim` como editor de texto. A medida que se incorporan comandos básicos del editor, se irá construyendo un pequeño programa en C, primero en su forma más simple y luego extendiéndolo para incorporar variables, operaciones y uso de `sizeof`.

El objetivo no es dominar `vim` en una sola sesión, sino adquirir una base mínima que permita usarlo para editar y corregir programas simples desde la terminal.

## Comandos y edición con `vim`

### 1. Abrir un archivo

Para crear o abrir un archivo desde la terminal:

```bash
vim example001.c
```

Si el archivo no existe, `vim` lo abrirá como un archivo nuevo. Si ya existe, mostrará su contenido.

### 2. Modos de `vim`

`vim` es un editor modal. Los dos modos más importantes en este laboratorio son:

- **Modo normal**: permite navegar y ejecutar comandos
- **Modo inserción**: permite escribir texto

Al abrir `vim`, normalmente se comienza en modo normal.

### 3. Entrar en modo inserción

Para comenzar a escribir texto, presionar:

```text
i
```

Con esto se entra en modo inserción.

### 4. Salir del modo inserción

Para volver al modo normal:

```text
ESC
```

### 5. Salir sin guardar

Desde modo normal, escribir:

```text
:q!
```

y luego presionar `Enter`.

Esto cierra el editor descartando todos los cambios realizados desde la última vez que se guardó.

### 6. Guardar y salir

Desde modo normal, escribir:

```text
:wq
```

y luego presionar `Enter`.

Esto guarda los cambios y cierra el editor.

### 7. Guardar sin salir

Desde modo normal:

```text
:w
```

## Edición básica en `vim`

Una vez dentro del editor y en modo normal, se pueden usar los siguientes comandos.

### 8. Copiar una línea

```text
yy
```

Copia la línea actual.

### 9. Pegar

```text
p
```

Pega debajo de la línea actual el contenido copiado.

### 10. Eliminar una línea

```text
dd
```

Elimina la línea actual.

### 11. Deshacer

```text
u
```

Deshace el último cambio realizado.

### 12. Rehacer

```text
Ctrl+r
```

Rehace un cambio deshecho.

## Actividad inicial con `vim`

Crear un archivo de prueba:

```bash
vim prueba.txt
```

Dentro de ese archivo:

1. Escribir tres líneas distintas
2. Copiar una de ellas con `yy`
3. Pegarla con `p`
4. Eliminar una línea con `dd`
5. Deshacer con `u`
6. Salir sin guardar con `:q!`

Luego volver a abrir el archivo, repetir el ejercicio y esta vez salir guardando con `:wq`.

## Primer programa en C: Hello World

Crear el archivo `example001.c` con `vim`:

```bash
vim example001.c
```

Ingresar el siguiente contenido:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

Guardar y salir.

## Compilación con `gcc`

Para compilar el programa desde la terminal:

```bash
gcc -Wall -std=c11 -o example001 example001.c
```

### Explicación del comando

- `gcc`: compilador de C
- `-Wall`: activa advertencias útiles
- `-std=c11`: indica que se usará el estándar C11
- `-o example001`: nombre del ejecutable de salida
- `example001.c`: archivo fuente

## Ejecución del programa

Una vez compilado:

```bash
./example001
```

Salida esperada:

```text
Hello, World!
```

## Extensión del programa: tipos de datos y `sizeof`

Crea un archivo llamado `example002.c` con el siguiente contenido:

```c
#include <stdio.h>

int main(void) {
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
```

Compilar nuevamente:

```bash
gcc -Wall -std=c11 -o example002 example002.c
```

Ejecutar:

```bash
./example002
```

## Extensión adicional: operaciones básicas

Ahora implementa un archivo `example003.c` con el siguiente contenido:

```c
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
```

Compilar y ejecutar:

```bash
gcc -Wall -std=c11 -o example003 example003.c
./example003
```
