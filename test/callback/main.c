#include <stdio.h>

void A(){ 
  printf("I am function A\n");
}
 
void B(void ptr())
{
    ptr();
}
 
int main()
{
    B(&A);
 
    return 0;
}