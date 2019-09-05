#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(){
	FILE *lista,*artigo,*final;
	char pri[50],seg[50],ter[50],c;
	int tamlis,tamfin;
//	Uso do srand() para o numero semi aleatório.
	srand(time(NULL));
	printf("Nao tem direito nenhum reservado nao, avisa que e do octavio so.\n");

//	Abrindo os arquivos.
	lista=fopen("listadefante.txt","r");
	artigo=fopen("artigosdefante.txt","r");
	final=fopen("finaldefante.txt","r");

//	A unica diferença entre o programa compilado PE e ELF, comente a linha abaixo pra linux.
//	freopen("CON","w",stdout);	

	if(lista==NULL || artigo==NULL || final==NULL)
		printf("deu erro no arquivo ai brother\n");	

//	Eu dou um seek até o final do arquivo (lista e final) e o ftell dá o numero de bytes no arquivo, 
//	dividindo pela quantidade de bytes por linha (já setado) se consegue a quantidade de linhas.
//	Assim o arquivo pode ser alterado e o programa se adapta dinamicamente. 
	fseek(lista,0,SEEK_END);
	tamlis=ftell(lista);
	tamlis=(tamlis/26);
	
	fseek(final,0,SEEK_END);
	tamfin=ftell(final);
	tamfin=(tamfin/26);
	printf("frases no lista:%d | frases no final:%d.\n",tamlis,tamfin);
	printf("aperte Enter: \n");

//	Loop para facilitar a repetiçao, com o tamanho das linhas setado o fseek() pula linhas inteiras, a quantidade de 
//	linhas o rand() define de 0-a quantidade de linhas definidas pelo ftell()
	while(1){
	getchar();
	fseek(lista,26*(rand() % tamlis),SEEK_SET);
	fseek(artigo,3*(rand() % 3),SEEK_SET);
	fseek(final,26*(rand() % tamfin),SEEK_SET);
//	Com o fgets() lendo dois bytes a menos que uma linha inteira o '\0' nao é lido já que é acrescentado pelo proprio
//	fgets() no buffer.
	if(!(fgets(pri,24,lista) && fgets(seg,3,artigo) && fgets(ter,24,final)))
		puts("nao sonseguiu ler dos arquivos show");

	printf("%s %s %s\n",pri,seg,ter);
	};
	fclose(artigo);
	fclose(lista);
	fclose(final);
	
	return 0;
};
