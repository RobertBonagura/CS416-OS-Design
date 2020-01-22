#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// run with ./a.out A & ./a.out B & ./a.out C
//
// this demonstrates virtual CPUs as all
// three run at the same time, even if you
// only have one or two CPUs.  You can view
// your CPUs on Linux with "cat /proc/cpuinfo"
//
// this demonstrates virtual memory as each
// process may have the same address for
// "msg", but each stores a different string
// there.
//
// Note that if you run this, you may happen
// to get different addresses for msg.  This
// is likely if your OS randomizes addresses
// (this makes it harder for hackers to take
// advantage of bugs, as you'll learn if you
// take the security course, CS 642).  I had
// to turn off randomization for the demo
// with this command:
//
// sudo sysctl -w kernel.randomize_va_space=0
int main(int argc, char *argv[]) {
  int i, j;
  char *hello = "Hello:";
  char *msg;
  assert(argc == 2);
  msg = malloc(strlen(hello) + strlen(argv[1]) + 1);
  assert(msg);
  sprintf(msg, "%s%s", hello, argv[1]);
  for (i=0; i<3; i++) {
    printf("msg is %s %p\n", msg, msg);
    for (j=0; j<500000000; j++); // spin
  }
  return 0;
}
