#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void preenche_matriz(int mtx[10][10]);
void imprime_matriz(int mtx[10][10]);
float media_coluna_2(int mtx[10][10]);
void acha_multiplos(int mtx[10][10], int val);

int main() {
  setlocale(LC_ALL, "pt_BR");

  int mtx[10][10];

  preenche_matriz(mtx);
  imprime_matriz(mtx);

  float media_2 = media_coluna_2(mtx);

  printf("Média da segunda coluna: %.2f\n", media_2);

  int val = 0;
  printf("Digite um número que te falarei a posição de seus múltiplos na matriz acima\n> ");
  scanf("%d", &val);

  acha_multiplos(mtx, val);

}

void preenche_matriz(int mtx[10][10]) {
  srand(time(NULL));

  for (int i = 0; i < 10; i += 1) {
    for (int j = 0; j < 10; j += 1) {
      int num = 40 + (rand() % 10);
      mtx[i][j] = num;
    }
  }
}

void imprime_matriz(int mtx[10][10]) {
  for (int i = 0; i < 10; i += 1) {
    for (int j = 0; j < 10; j += 1) {
      printf("%02d\t", mtx[i][j]);
    }
    printf("\n");
  }
}

float media_coluna_2(int mtx[10][10]) {
  float media = 0;

  for (int i = 0; i < 10; i += 1) {
    media += (float) mtx[i][1];
  }

  media /= 10.0F;

  return media;
}

void acha_multiplos(int mtx[10][10], int val) {
  int counter = 0;
  if (val != 0 || val > 50) {
    for (int i = 0; i < 10; i += 1) {
      for (int j = 0; j < 10; j += 1) {
        int el = mtx[i][j];
        if (el % val == 0) {
          counter += 1;
          printf("Elemento: %02d; Posição (%02d, %02d)\n", el, i, j);
        }
      }
    }
  }

  if (counter == 0) {
    printf("Não encontrei nenhum elemento múltiplo de %d na matriz\n", val);
  }
}
