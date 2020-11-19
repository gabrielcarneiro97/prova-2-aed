#include "gabriel.h"

float calcula_h(int qnt) {
  float dividendo = 2;
  float divisor = 3;
  float sinal = 1;

  float h = 0;

  for (int i = 0; i < qnt; i += 1) {
    h += sinal * (dividendo / divisor);

    sinal = -sinal;
    dividendo += 2;
    divisor += 2;
  }

  return h;
}
