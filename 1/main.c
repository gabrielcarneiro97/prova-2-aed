#include <stdio.h>
#include <locale.h>
#include "gabriel.h"

int main() {
  setlocale(LC_ALL, "pt_BR");

  int qnt = 0;

  printf("Olá, esse programa calcula a seguinte equação:\n H = 2/3 - 4/5 + 6/7 - 8/9...\nMas para isso preciso que você entre com o número de termos que quer que sejam calculados.\nDigite o número de termos:\n> ");
  scanf("%d", &qnt);

  float res = calcula_h(qnt);

  printf("A quantidade solicitada foi %d, a resposta é %.5f\n", qnt, res);

  return 0;
}
