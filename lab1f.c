#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct {
  int ID;
  int quant;
  int numdist;
}galpao;


void insere_ordenado(galpao  **galpao, int g, int id, int qt);



int main(){
  int nsetor, mprodutos;
  int g, id, qt, aux[MAX];
  int i,j, flag=0;
  float total=0,media=0;
  galpao **galpao;
  /*Criacao de um vetor auxiliar, para saber se existem ID's iguais em diferentes galpoes*/
  for(i=0;i< MAX;i++){
    aux[i] = -1;
  }
  scanf("%d %d", &nsetor, &mprodutos);
  /*Alocacao da matriz de structs*/
  galpao = malloc(nsetor*sizeof(*galpao));
  for(i=0;i<nsetor;i++){
    galpao[i] = malloc(mprodutos*sizeof(galpao));
  }
  for(i=0;i<nsetor;i++){
    galpao[i][0].numdist = 0;
  }

  /*Leitura da entrada*/
  
  while(id != -1 ){
    scanf("%d %d %d", &g ,&id, &qt);
   
    insere_ordenado(galpao, g,id,qt); /*ja insere no galpao em ordem crescente pelo ID*/
    if(aux[id] == -1){ /*Apos dada a entrada, verifica se ja existe a ID em outro galpao*/
      aux[id] = g; /*Se esta vazio, coloca o numero do galpao*/
    }
    else if(aux[id] !=g){
      flag = -1;/*Se tem outro numero diferente de -1, indica que ja existe a ID em outro galpao*/
    }  
  }
  
  /*Impressao da saida*/
  for(i = 0; i<nsetor; i++){
    printf("%d ", i);
    for(j = 0; j < galpao[i][0].numdist ; j++){
      total  = total + galpao[i][j].quant;
    }
    media= total/(galpao[i][0].numdist);
    printf("%.0f %.2f\n", total, media);
    media = 0;
    total = 0;
  }
 
  if(flag == 0)
    printf("NÃO\n");
  else
    printf("SIM\n");

  free(galpao);
  return 0;

}


void insere_ordenado(galpao **galpao, int g, int id, int qt){
  int i, flag=0;
    printf("%d \n", galpao[g][0].numdist);
  for(i = galpao[g][0].numdist -1; i>=0;i--){
    if(galpao[g][i].ID == id){
      flag=1;
      galpao[g][i].quant += qt;
      i=0;
    }
    
  }
  if(flag ==0){
    i = galpao[g][0].numdist;
    galpao[g][i].ID = id;
    galpao[g][i].quant = qt;
    galpao[g][0].numdist ++;
  }
      printf("%d %d\n", g, galpao[g][0].numdist);
  return;
  
}
