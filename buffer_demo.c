#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Sin argumentos: 1000 printf. Con cualquier argumento: 1000 write directos. */
int main(int argc, char **argv) {
    (void)argv;
    const char *linea = "linea de prueba\n";
    for (int i = 0; i < 1000; i++) {
        if (argc > 1)
            write(STDOUT_FILENO, linea, strlen(linea));
        else
            printf("%s", linea);
    }
    return 0;
}
