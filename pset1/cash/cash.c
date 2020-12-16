// get_float to get user's change owed DONE
// re-prompt if negative DONE
// convert dollars to cents (float to int) TODO
// round to nearest penny (eg. round (dollars * 100) to int value) TODO
// implement greedy algorithm TODO
// last line = "%i\n" TODO
#include <cs50.h>
#include <stdio.h>

int main(void)
{
  float input = 0; 
  while (!(input > 0))
  {
    input = get_float("Please enter the change owed (ex. '$$.CC'): ");
  }
  printf("%f", input);
}
