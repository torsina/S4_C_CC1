#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

void childProcess() {
  pid_t fork1 = fork();
  int wstatus;
  switch (fork1) {
  case -1:
    exit(EXIT_FAILURE);
    break;

  case 0:
    printf("Je suis le fils, mon pid est %ld\n", (long)getpid());
    exit(EXIT_SUCCESS);
  }
  waitpid(fork1, &wstatus, 0);
}

int main() {
  printf("Je suis le père, mon pid est %ld\n", (long)getpid());
  if(getpid() % 2 == 0) {
    childProcess();
    childProcess();
  } else {
    childProcess();
  }
  return 0;
}

