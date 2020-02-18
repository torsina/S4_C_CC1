#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(void) {
  pid_t p;
  int wstatus;
  p = fork();

  switch (p) {
  case -1:
    exit(EXIT_FAILURE);
    break;

  case 0:
    printf("Je suis le fils, mon pid est %ld\n", (long)getpid());
    char* args[3] = {"apt", "moo", NULL};
    execvp("apt", args);
    return 187;
    break;

  default:
    printf("Je suis le pere, mon pid est %ld\n", (long)getpid());
    break;
  }
  waitpid(p, &wstatus, 0);
  printf("Mon fils: %ld à retourné: %d\n", (long)p, WEXITSTATUS(wstatus));

}
