#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t t;
  struct tm *tm;
  char fechayhora[100];

  t=time(NULL);
//  printf("time: %d  - %s \n",t);
  tm=localtime(&t);
//  printf("localtime: %d  - %s \n",tm);
  strftime(fechayhora, 100, "%d/%m/%Y", tm);
  printf ("Hoy es: %s\n", fechayhora);


  char dia[100];
  char mes[100];
  char ano[100];
  strftime(dia, 100, "%d", tm);
  strftime(mes, 100, "%m", tm);
  strftime(ano, 100, "%Y", tm);
  printf ("Hoy es: %s-%s-%s\n",dia,mes,ano);
}
