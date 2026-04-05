# L03: Edición con vim y compilación en C

## Introducción

Esta sesión introduce el uso básico del editor `vim` junto con el flujo mínimo de desarrollo en C: edición, compilación y ejecución desde la terminal. A diferencia de sesiones anteriores centradas en la terminal, aquí se incorpora el primer ciclo completo de desarrollo: escribir código, compilarlo y ejecutarlo.

### Prerrequisitos

- Tener sesión iniciada en la VM Lubuntu del equipo asignado
- Tener disponible el compilador `gcc`
- Haber trabajado previamente con comandos básicos de terminal

### Objetivo general

- Editar archivos de texto usando `vim`
- Comprender operaciones básicas de edición en un editor modal
- Escribir, compilar y ejecutar un programa simple en C usando el estándar C11
- Extender el programa para trabajar con tipos de datos, operaciones aritméticas y `sizeof`

### Objetivos específicos

- Abrir archivos con `vim`
- Entrar y salir del modo inserción
- Salir guardando y salir sin guardar
- Copiar, pegar, eliminar líneas y deshacer cambios
- Escribir un programa `Hello, World!` en C
- Compilar desde la terminal con `gcc -std=c11`
- Ejecutar el binario generado
- Extender el programa para mostrar operaciones básicas y tamaños de tipos de datos

### Metodología

A lo largo de esta sesión se trabajará directamente sobre archivos de código fuente en C usando `vim` como editor de texto. A medida que se incorporan comandos básicos del editor, se irá construyendo un pequeño programa en C, primero en su forma más simple y luego extendiéndolo para incorporar variables, operaciones y uso de `sizeof`.

El objetivo no es dominar `vim` en una sola sesión, sino adquirir una base mínima que permita usarlo para editar y corregir programas simples desde la terminal.

### Estructura del repositorio

Este repositorio solo contiene una carpeta `code` con los archivos fuente de ejemplo idénticos a los que se proveen como parte del README. No se incluyen archivos de prueba ni otros recursos para esta sesión ya que el foco está en la edición y compilación básica.

Si bien se recomienda un trabajo directo sobre la terminal para preparar estos archivos, también es posible usar los archivos provistos para compilar y ejecutar sin necesidad de escribirlos desde cero, aunque se pierde la oportunidad de practicar los comandos básicos de `vim`.

## Actividad

### 1. Uso básico de `vim`

#### Abrir vim

Para abrir el editor `vim` desde la terminal, simplemente escribir:

```bash
> vim
```

`vim` es un editor modal. Los dos modos más importantes son:

- **Modo normal**: permite navegar y ejecutar comandos
- **Modo inserción**: permite escribir texto

Al abrir `vim`, normalmente se comienza en modo normal. En este modo, al escribir no se insertará texto, sino que cada tecla se interpreta como un comando. En esta primera incursión solo cerraremos `vim` sin guardar, así que no es necesario entrar en modo inserción aún. Para salir sin guardar, debemos estar en modo normal (al que podemos acceder con `ESC`) y luego escribir `:q`.

#### Abrir un archivo

Para crear o abrir un archivo desde la terminal llamamos a vim seguido del nombre del archivo:

```bash
> vim example.c
```

Si el archivo no existe, `vim` lo abrirá como un archivo nuevo. Si ya existe, mostrará su contenido.

Aquí podemos empezar a editar nuestro archivo. Para ello primero debemos entrar en modo inserción, apretando la tecla `i` en modo normal. Luego podremos escribir texto normalmente. Para volver a modo normal, presionamos `ESC`.

Una vez que hemos editado el archivo intentamos salir con `:q`, pero `vim` nos indicará que hay cambios sin guardar. Para salir sin guardar, debemos usar `:q!`.

Al revisar la consola notaremos que aunque hayamos abierto el archivo, no se ha creado ningún archivo nuevo en el sistema de archivos. Esto se debe a que `vim` solo crea el archivo cuando se guarda por primera vez.

#### Guardar y salir

Abrimos nuevamente el archivo con `vim example.c`, entramos en modo inserción con `i`, escribimos algo de texto y luego queremos salir guardando los cambios. Para eso, estando en modo normal, escribimos `:wq`.

y luego presionar `Enter`. Esto guarda los cambios y cierra el editor. Ahora al revisar el sistema de archivos, veremos que el archivo `example.c` ha sido creado con el contenido que escribimos.

#### Guardar sin salir

No es necesario salir para guardar los cambios. Si queremos guardar pero seguir editando, estando en modo normal, escribimos `:w`.

### 2. Comandos básicos de edición en modo normal

Una vez dentro del editor y en modo normal, se pueden usar diversos comandos para manipular el texto. A continuación se muestran algunos comandos básicos.

#### Copiar una línea

```text
yy
```

Copia la línea actual.

#### Pegar

```text
p
```

Pega debajo de la línea actual el contenido copiado.

#### Eliminar una línea

```text
dd
```

Elimina la línea actual.

#### Deshacer

```text
u
```

Deshace el último cambio realizado.

#### Rehacer

```text
Ctrl+r
```

Rehace un cambio deshecho.

### 3. Primer programa en C: Hello World

Crear el archivo `example001.c` con `vim`:

```bash
> vim example001.c
```

Ingresar el siguiente contenido:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

Guardar y salir.

Para compilar el programa desde la terminal:

```bash
> gcc -Wall -std=c11 -o example001 example001.c
```

De esta compilación podemos recordar los siguientes elementos:

- `gcc`: compilador de C
- `-Wall`: activa advertencias útiles
- `-std=c11`: indica que se usará el estándar C11
- `-o example001`: nombre del ejecutable de salida
- `example001.c`: archivo fuente

Una vez compilado el programa se puede ejecutar con:

```bash
> ./example001
```

Salida esperada:

```text
Hello, World!
```

### 4. Extensión del programa: tipos de datos y `sizeof`

Crea un archivo llamado `example002.c` con el siguiente contenido:

```c
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
```

Compilar nuevamente:

```bash
> gcc -Wall -std=c11 -o example002 example002.c
```

Ejecutar:

```bash
> ./example002
```

### 5. Adicional: Operaciones básicas

Ahora implemente un archivo `example003.c` con el siguiente contenido:

```c
#include <stdio.h>

int main(void)
{
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
> gcc -Wall -std=c11 -o example003 example003.c
> ./example003
```
