#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    const char *path = "demo.txt";
    const char *msg = "Hola syscalls\n";
    int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) { perror("open"); return 1; }
    if (write(fd, msg, strlen(msg)) < 0) { perror("write"); return 1; }
    close(fd);

    fd = open(path, O_RDONLY);
    if (fd < 0) { perror("open2"); return 1; }
    char buf[64] = {0};
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    if (n < 0) { perror("read"); return 1; }
    close(fd);

    printf("Leido: %s", buf);
    return 0;
}
