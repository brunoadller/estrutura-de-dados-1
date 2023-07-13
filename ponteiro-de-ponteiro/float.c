#include <stdio.h>
#include <stdlib.h>

int main(){
  float z = 2.5;
  float *fp;

  fp = &z;

  //*&z = *(5000) = 2.5 
  printf("*&z = %f\n", *&z);
  //*fp = *(5000) = 2.5
  printf("*fp = %f\n", *fp);
  //**&fp = **(5004) = *(5000) = 2.5
  printf("**&fp = %f\n", **&fp);
  return 0;
}