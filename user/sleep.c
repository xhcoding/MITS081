#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char* argv[])
{
  if (argc != 2)
  {
    const char* error = "sleep: missing operand\n";
    write(2, error, strlen(error));
    exit(-1);
  }
  int n = atoi(argv[1]);
  
  int ret = sleep(n);
  exit(ret);
}
