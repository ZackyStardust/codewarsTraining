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
