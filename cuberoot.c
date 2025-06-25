#include <stdio.h>
#include <math.h>


#define MAX_VAL(type) ((type)((1U << (sizeof(type) * 8 - 1)) - 1))


void IncorrectInput() {
  while (getchar() != '\n');
}

float cuberoot(float x); 

int main() {
  const float FLT_MAX = 3.40282347e+38F;
  printf("Cube root calculator!");
  do {
    float x;
    unsigned int decimalPlaces;
	char term;
    printf("\nType x: ");
	
    if (scanf("%f%c", &x, &term) != 2 || term != '\n') {
      printf("Incorrect x!\n");
      IncorrectInput();
      continue;
    } else if (x > MAX_VAL(float)) {
      printf("x must be a float and be beetwen %f and %f\n", -FLT_MAX, FLT_MAX);
      continue;        
    } else if (x < -MAX_VAL(float)) {
      printf("x must be a float and be beetwen %f and %f\n", -FLT_MAX, FLT_MAX);
      continue;
    }
	
    printf("Type number of places to which you want to round the result: ");

    if (scanf("%d%c", &decimalPlaces, &term) != 2 || term != '\n') {
      printf("Incorrect input!\n");
      IncorrectInput();
      continue;
    } else if (decimalPlaces < 0 || decimalPlaces > MAX_VAL(unsigned int)) {
      printf("Value of decimal places must be > than 0 and < than %d\n", MAX_VAL(unsigned int));
      continue;
    }

    float result = cuberoot(x);
printf("%f\n", result);
    printf("Cube root of x = %.*f\n", decimalPlaces, result);



    printf("Exit program? (y/n) ");
    char c;
    scanf(" %c", &c);
    if (c != 'n') {
      break;
    }
  } while (1);

  return 0;
}