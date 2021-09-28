#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int age, year, speed, y, x, z, w, k, n, between,
  divisor, digit, num, lowercase, ch, item, product;
  double water;
  /* Age is from 18 to 21 inclusive */
  18 <= age && age <= 21;
  /* Water is less than 1.5 and also greater than 0.1 */
  1.5 > water > 0.1;
  /* year is divisible by 4 */
  year % 4 == 0;
  /*speed is not greater than 55 */
  speed <= 55;
  /* yis greater than x and less than z */
  x < y && y < z;
  /* w is either equal to 6 or not greater than 3 */
  w == 6 || w >= 3;

  /*OPGAVE 2 
  Assign a value of 0 to int between if n is less than -k or greater than +k; otherwise, assign 1*/
  if (n < -k || n > +k)
  {
    between = 0;
  }
  else{
    between = 1;
  }
  /* Anden måde at gøre det på når det kun er 0 og 1, altså true or false */
  between = !(n < -k || n > +k);
  between = (n < -k || n > +k);

  /* Assign a value to int divisor is int digit is a divior of num; otherwise assign a value of 0 */
  if (num % digit == 0)
  {
    divisor = 1;
  }
  else{
    divisor = 0;
  }
  /* Assign a value of 1 to lowercase if ch is a lowercase letter; otherwise, assign a value of 0 */
 if ("a" <= ch && "z" >= ch)
 {
   lowercase = 1;
 }
  else{
    lowercase = 0;
  }

  if (item != 0)
  {
    product = product * item;
    printf("%d", &product);
  }
  else
  {
    print("%d", &product);
  }
  /* Store the absolute difference of x and y in y */
  if (x < y)
  {
    y = (y-x);
  }
  else{
    y = (x-y);
  }


  /* Brug af switch */
  /* Write a switch statement that assigns to the variable lumens the expected brightness of an 
  incandescent light bulb whose wattage has been stored in watts (Se table på side 243)*/
  int watts, lumens;
  switch (watts)
  {
  case 15:
    lumens = 125;
    break;
  case 25:
    lumens = 215;
    break;
  case 40:
    lumens = 500;
    break;
  case 60:
    lumens = 880;
    break;
  case 75:
    lumens = 1000;
    break;
  case 100:
    lumens = 1675;
  default:
    lumens = -1;
  } 

  /* Opgave 6 side 275 */
  int mult4;
  for(mult4 = 0; mult4 < 100; mult4 += 4){
    printf("%d", mult4);
  }
  /* Programmeringsopgave 1 side 267 */
  int n, n_sum;
  n_sum = 0;
  n = 0;
  scanf("%d", &n);
  
  return 0;
}


