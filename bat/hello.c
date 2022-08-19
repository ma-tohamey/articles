#include <stdio.h>

int main(void)
{
  char* name[10];
  printf("what is your name? ");
  scanf("%s", &name);
  printf("hello, %s", name);
}
