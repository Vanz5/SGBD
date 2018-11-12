#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CriarTabela () {
	char titulo[30];
	int tam;
	printf ("Insira o nome da tabela: (máximo 30 letras)\n");
	scanf("%s", &titulo);

	// adicionando ao arquivo com todas as tabelas para poder listar depois

	FILE *arquivo;
	arquivo = fopen("tabelas.txt","ab+");
	if(arquivo== NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else{
		fprintf(arquivo,"%s \n",titulo);
	}
	fclose(arquivo);

	printf ("Insira o numero de colunas desejadas:\n");
	scanf("%i", &tam); 

	char colunas[tam][30];
	char tipos[tam][30];

		printf ("Insira o nome para a chave primaria (sugestão: id)\n");
		scanf("%s", &colunas[0]);
		strcpy(tipos[0],"int");
    
	for (int i = 1; i < tam; ++i){
		printf ("Insira o nome da coluna\n");
		scanf("%s", &colunas[i]);
		printf ("Insira o tipo de dado dessa coluna (char,int,float,double ou string):\n");
		scanf("%s", &tipos[i]);
		/* fazer os testes pra saber se está escrito corretamente
		if (){
			printf("Tipo inválido, insira novamente (char,int,float,double ou string):\n");
		}*/
	}

	//char nomeArquivo[40];
	//strcat(titulo,".txt"); não deu certo e tive que usar "teste.txt" para checar se o resto estava correto
	FILE *arquivo2;
	arquivo2 = fopen("teste.txt","wb+");
	if(arquivo2== NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else{
		for (int i = 0; i < tam; ++i){
			fprintf(arquivo2, "\t%s\t",colunas[i] );
		}
		fprintf(arquivo2, "\n");
		for (int i = 0; i < tam; ++i){
			fprintf(arquivo2, "\t%s\t",tipos[i] );
		}
		fprintf(arquivo2, "\n");
	}
	fclose(arquivo2);
	
}

void ListarTabelas () {
	FILE *arquivo = fopen("tabelas.txt","rb");
	if(arquivo== NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else{
		printf("\nTabelas disponiveis: \n\n");
		char * buffer = malloc( sizeof( char ) * 101 );
		while( fgets( buffer , 100, arquivo ) != NULL ){
		printf( "%s", buffer );
		}
		fclose( arquivo );
		free( buffer );

		printf("\n\n");
	}
}

void Menu () {

	int opcao = 0;

	printf ("Sistema de Gerenciamento de Banco de Dados (SGBD - ITP)\n");
	printf ("Autores: Maurício e Van Allen\n\n");
	printf ("Para realizar a função desejada, digite: \n\n");
	printf ("1 - Criar tabela\n2 - Listar todas as tabelas\n");
	printf ("0 - Sair\n\n");

	do {
		printf ("Opção: ");
		scanf ("%i", &opcao);

		switch (opcao) {
			case 0:
				break;
			case 1:
				CriarTabela();
				break;
			case 2:
				ListarTabelas();
				break;
			default:
				printf ("Opção inválida, tente novamente.\n");
				break;
		}
	} while (opcao != 0);

}

int main(void) {
  
	Menu ();

  return 0;
}