#include <stdio.h>

int main (void) {
  int posAmigo1, posAmigo2, distancia, cansaco;

  scanf("%d", &posAmigo1);
  scanf("%d", &posAmigo2);

  distancia = posAmigo2 - posAmigo1;
  if (distancia < 0) distancia*=-1;
  int metade = distancia / 2;
  
  //Calcula uma PA ate a metade da distancia, pois o cansaco minimo de cada um pode ser visto assim.
  //Nao tem o /2 pois tambem teria um *2 por serem 2 amigos, e uma operacao anula a outra.
  cansaco = ((1+metade)*metade);
  //Caso a distancia seja impar o amigo1 vai precisar andar mais um vez, entao calcula-se o cansaco dele
  if (distancia % 2 == 1) cansaco += (metade+1);

  printf("%d \n", cansaco);

  return 0;
}