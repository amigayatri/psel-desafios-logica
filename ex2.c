#include <stdio.h>

int main (void) {
  int nX = 0, n0 = 0;
  char grade[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%c", &grade[i][j]);
      if (grade[i][j] == 'X') nX++;
      else if (grade[i][j] == '0') n0++;
    }
    getchar();
  }

  for (int i = 0; i < 3; i++) {
    //Verifica se as colunas ou linhas sao compostas de 3 iguais, caso sejam, verifica de qual
    if ((grade[i][0] == grade[i][1]) && (grade[i][1] == grade[i][2])) {
      if (grade[i][0] == 'X') printf("primeiro_venceu");
      else printf("segundo_venceu");
      return 0;
    } else if ((grade[0][i] == grade[1][i]) && (grade[1][i] == grade[2][i])) {
      if (grade[0][i] == 'X') printf("primeiro_venceu");
      else printf("segundo_venceu");
      return 0;
    }
  }

  //Verifica as diagonais pra ver se alguma tem 3 iguais
  if (((grade[0][0] == grade[1][1]) && (grade[1][1] == grade[2][2]))
  ||  ((grade[0][2] == grade[1][1]) && (grade[1][1] == grade[2][0]))) {
    if (grade[1][1] == 'X') printf("primeiro_venceu");
    else printf("segundo_venceu");
  } else if (nX+n0 == 9) printf("empate"); //Se tem 9 e ninguem venceu, entao é empate
  //Como o X comeca, o numero de 0s nunca pode ser maior, e nem o de X ter mais de 1 de diferenca
  else if ((nX - n0) > 1 || n0 > nX) printf("invalido");
  else if (nX > n0) printf("segundo"); //X ja foi, entao vez do 0
  else if (nX == n0) printf("primeiro"); //0 ja foi, vez do X

  return 0;
}