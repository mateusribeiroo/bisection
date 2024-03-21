#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef struct Bis {
  float a0;
  float b0;
  float x;
  float erro;

  uint8_t MAX_IT;

} Bis;

float func(float x){
  return (2*x)+8; //altere aqui para a funcao desejada
}

float find_root(Bis *b){
  int i = 0;
  float erro = 1, vlax, vlbx, vlx;
  b->x = (b->a0+b->b0) / 2.0;
  
  
  while(i != b->MAX_IT || erro >= b->erro){
    vlx = func(b->x);
    vlax = func(b->a0) * func(b->x);
    vlbx = func(b->b0) * func(b->x);

    if(vlax < 0){
      erro = (func(b->x) - func(b->b0))/func(b->x);
      b->b0 = b->x;
    }else if(vlbx < 0){
      erro = (func(b->x) - func(b->a0)/func(b->x));
      b->a0 = b->x;
    }
    
    b->x = (b->a0+b->b0)/2;

    i++;
  }


  return b->x;
}

int main(){
  Bis *bis = (Bis *)malloc(sizeof(Bis));

  printf("Digite o intervalo que deseja fazer a busca, digite o menor valor primeiro e depois o maior\n");
  scanf("%f", &bis->a0);
  scanf("%f", &bis->b0);

  printf("Digite o erro desejado\n");
  scanf("%f", &bis->erro);

  printf("Digite o número máximo de iterações que voce deseja\n");
  
  scanf("%hhd", &bis->MAX_IT);

  if(bis->MAX_IT == 0){
    printf("Número de iteracoes igual a zero, logo nao tem o que fazer, ate a proxima \n");
    return 0;
  }

  printf("\nEstes são os dados inseridos: \n");
  printf("Inicio: %f\n", bis->a0);
  printf("Fim: %f\n", bis->b0);
  printf("Erro: %f\n", bis->erro);
  printf("Iteracoes: %d\n", bis->MAX_IT);

  float res = find_root(bis);

  printf("A raiz encontrada eh: %2.f\n\n", res);

  free(bis);

  return 0;
}
