#include "float_Vector.h"
#include <stdio.h>

int main(){
  FloatVector *vec = create(2);
  print(vec);
  append(vec, 1.0);
  append(vec, 2.0);
  print(vec);
  
 
  destroy(&vec);
  return 0;
}