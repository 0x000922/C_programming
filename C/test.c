#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
// #define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int main() {
  int link[2];
  int pid;
  char foo[4096];

  if (pipe(link)==-1)
    exit(0);

  if ((pid = fork()) == -1)
    exit(0);

  if(pid == 0) {

    dup2 (link[1], STDOUT_FILENO);
    close(link[0]);
    close(link[1]);
    execl("/bin/ls", "ls", "-l", NULL);
    // die("execl");

  } else {

    close(link[1]); int n;
    while (n = read(link[0], foo, sizeof(foo)) > 0)
    puts(foo);
    // printf("Output: (%.*s)\n", nbytes, foo);
    // wait(NULL);

  }
  return 0;
}