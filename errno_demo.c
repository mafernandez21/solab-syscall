#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void probar(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        printf("open(%s): fd=%d errno=%d (%s)\n", path, fd, errno, strerror(errno));
        return;
    }
    printf("open(%s): fd=%d\n", path, fd);
    close(fd);
}

int main(void) {
    probar("no_existe.txt");
    probar("/etc/shadow");
    probar("/etc/hostname");
    return 0;
}
