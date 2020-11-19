#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int *cria_array(int len);
int *inverte_array(int *arr1, int len);
void imprime_array(int *arr, int len);

int main() {
  setlocale(LC_ALL, "pt_BR");

  int len = 0;

  printf("Olá, esse programa cria um array de tamanho qualquer com elementos entre 1 e 15, depois inverte esse array.\nPor favor digite o tamanho do array:\n> ");
  scanf("%d", &len);

  if (len <= 0) {
    printf("tamanho inválido!\n");
    return -1;
  }

  int *arr = cria_array(len);
  int *arr_invertido = inverte_array(arr, len);

  printf("O array gerado foi:");
  imprime_array(arr, len);
  printf("Esse array invertido fica assim:");
  imprime_array(arr_invertido, len);


  free(arr);
  free(arr_invertido);

  return 0;
}

int *alloca_array(int len) {
  int *arr = (int *) malloc(sizeof(int) * len);
  return arr;
}

int *cria_array(int len) {
  int *arr = alloca_array(len);

  srand(time(NULL));

  for (int i = 0; i < len; i += 1) {
    int num = 1 + (rand() % 15);
    arr[i] = num;
  }

  return arr;
}

int *inverte_array(int *arr1, int len) {
  int *arr2 = alloca_array(len);

  for (int i = 0; i < len; i += 1) {
    arr2[i] = arr1[len - 1 - i];
  }

  return arr2;
}

void imprime_array(int *arr, int len) {
  printf("\n[ ");

  for (int i = 0; i < len; i += 1) {
    printf("%02d", arr[i]);

    if (i < len - 1) {
      printf(", ");
    }
  }

  printf(" ]\n");
}
