#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t p = fork();
    if (p < 0) { perror("fork"); return 1; }
    if (p == 0) {
        execl("/bin/echo", "echo", "hola desde hijo", (char *)NULL);
        perror("execl");
        _exit(1);
    }
    wait(NULL);
    printf("Padre finaliza\n");
    return 0;
}
