/*
Name: Greed is Good
Kata: 5 kyu
Link: https://www.codewars.com/kata/5270d0d18625160ada0000e4

Description: Greed is a dice game played with five six-sided dice. Your mission, should you choose to
accept it, is to score a throw according to these rules. You will always be given an array with five
six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a given "5" can only count as
part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
In some languages, it is possible to mutate the input to the function. This is something that you
should never do. If you mutate the input, you will not be able to pass all the tests.
*/

#include <stdbool.h>

bool find_triples(int *tempdice, int num)
{
  int triple = 0;
  
  for (int i = 0; i < 5; i++)
  {
    if (tempdice[i] == num)
      triple++;
    if (triple == 3)
      return true;
  }
  return false;
}

void dice_clean(int *tempdice, int num)
{
  int triple = 0;
  
  for (int i = 0; i < 5; i++)
    if (tempdice[i] == num)
    {
      tempdice[i] = 0;
      triple++;
      if (triple == 3)
        return ;
    }
}

int score(const int dice[5])
{
  int tempdice[5];
  int score = 0;
  
  for (int i = 0; i < 5; i++)
    tempdice[i] = dice[i];
  for (int num = 1; num < 7; num++)
    if (find_triples(tempdice, num))
    {
      if (num == 1)
        score += 1000;
      else
        score += num * 100;
      dice_clean(tempdice, num);
    }
  for (int i = 0; i < 5; i++)
  {
    if (tempdice[i] == 1)
      score += 100;
    else if (tempdice[i] == 5)
      score += 50;
  }
  return score;
}
