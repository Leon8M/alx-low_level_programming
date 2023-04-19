#include <stdio.h>
#include <stdlib.h>

void print_opcodes(char *addr, int n);

int main(int argc, char **argv)
{
if (argc != 2) {
printf("Error\n");
return 1;
}
int n = atoi(argv[1]);
if (n <= 0) {
printf("Error\n");
return 2;
}
char *addr = (char *)main;
print_opcodes(addr, n);
return 0;
}

void print_opcodes(char *addr, int n)
{
int i;
for (i = 0; i < n - 1; i++) {
printf("%02hhx ", addr[i]);
}
printf("%02hhx\n", addr[i]);
}
