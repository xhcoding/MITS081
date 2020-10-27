#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char* argv[])
{
  int p[2];
  pipe(p);

  int p2[2];
  pipe(p2);
  if (fork() == 0) {
    char buffer[1];
    close(p[1]);
    read(p[0], buffer, 1);
    printf("%d: received ping!\n", getpid());
    close(p[0]);
    close(p2[0]);
    write(p2[1], "b", 1);
    close(p2[1]);
    exit(0);
  } else {
    char buffer[1];
    close(p[0]);
    close(p2[1]);
    write(p[1], "a", 1);
    close(p[1]);
    read(p2[0], buffer, 1);
    close(p2[0]);
    printf("%d: received pong!\n", getpid());
    int ret;
    wait(&ret);
  }
  exit(0);
}
