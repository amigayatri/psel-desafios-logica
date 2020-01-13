#include <stdio.h>
#include <unordered_map>
using namespace std;

int compare (const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int main (void) {
  
  int tam; 
  unordered_map<int, int> indice;

  scanf("%d", &tam);
  int vetor[tam];
  for (int i = 0; i < tam; i++) {
    scanf("%d", &vetor[i]);
  } 

  //Uma sequencia de menos de 3 itens não pode ser fibonaccica
  if (tam < 3) {
    printf("0\n");
    return 0;
  }

  qsort(vetor, tam, sizeof(int), compare);

  for(int i = 0; i < tam; i++) {
    indice[vetor[i]] = i;
  }

  unordered_map<int, int> maior;
  int seqTam = 0;

  
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) { //Percorre todos os numeros para ver se existe uma sequencia com ele como segundo numero
      if(i != j && vetor[i] - vetor[j] < vetor[j] && indice.count(vetor[i]-vetor[j])) {
        int k = indice[vetor[i] - vetor[j]];
        maior[j*tam+i] = maior[k*tam+j] + 1;
        seqTam = max(seqTam, maior[j*tam+i] + 2);
      }
    }
  }

  //Caso a sequencia seja menor que 3 ela nao e fibonaccica
  if (seqTam >= 3) printf("%d\n", seqTam);
  else printf("0\n");

  return 0;
}