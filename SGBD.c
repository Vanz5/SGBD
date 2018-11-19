#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CriarTabela () {
	char titulo [30];
	int tamanho;
	char tabelaDados [40];
	char tabelaMeta [50];
	char extensao[] = ".txt\0";
	char meta[] = "Meta.txt\0";
	int i;
	int tipoValido;

	printf ("Insira o nome da tabela (máximo de 30 caracteres):\n");
	scanf("%s", &titulo);

	strcpy (tabelaDados, titulo);
	strcpy (tabelaMeta, titulo);

	strcat (tabelaDados, extensao);
	strcat (tabelaMeta, meta);

	// ADICIONANDO O TÍTULO DA TABELA A SER CRIADA NO ARQUIVO QUE LISTA TODAS AS TABELAS EXISTENTES

	FILE *arquivo;
	arquivo = fopen("tabelas.txt","ab+");
	if (arquivo == NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else {
		fprintf(arquivo,"%s \n", titulo);
	}
	fclose(arquivo);

	// ADICIONAR NA LISTA DE TABELAS - FIM

	printf ("Insira o número de colunas desejadas:\n");
	scanf("%i", &tamanho); 

	char colunas[tamanho][30];
	char tipos[tamanho][30];

		printf ("Insira um nome para a chave primária (sugestão: 'id'): \n");
		scanf("%s", &colunas[0]);
		strcpy(tipos[0],"int\0");
    
	for (i = 1; i < tamanho; ++i) {
		printf ("Insira o nome da coluna:\n");
		scanf("%s", &colunas[i]);
		printf ("Insira o tipo de dado dessa coluna (char, int, float, double ou string):\n");
		scanf("%s", &tipos[i]);
		
		// CHECAR SE O TIPO DIGITADO É VÁLIDO
		/*
		tipoValido = 1;

		while (tipoValido != 0) {
			if (strcmp (tipos [i], "char\0")) {
				tipoValido = 0;
			} else if (strcmp (tipos [i], "int\0")) {
				tipoValido = 0;
			} else if (strcmp (tipos [i], "float\0")) {
				tipoValido = 0;
			} else if (strcmp (tipos [i], "double\0")) {
				tipoValido = 0;
			} else if (strcmp (tipos [i], "string\0")) {
				tipoValido = 0;
			} else {
				printf("Tipo inválido, tente novamente (char, int, float, double ou string):\n");
				scanf("%s", &tipos[i]);
			}
		}*/

		// CHECAR SE O TIPO DIGITADO É VÁLIDO - FIM
	}
	
	// CRIANDO TABELA DE METADADOS

	FILE *arquivo2;
	arquivo2 = fopen(tabelaMeta,"wb+");
	if(arquivo2 == NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else {
		for (i = 0; i < tamanho; ++i){
			fprintf(arquivo2, "%s;%s", colunas [i], tipos [i] );
			fprintf(arquivo2, "\n");
		}
	}
	fclose(arquivo2);

	// CRIANDO TABELA DE METADADOS - FIM

	//CRIANDO TABELA COM OS DADOS
		FILE *arquivo3;
	arquivo3 = fopen(tabelaDados,"wb+");
	if(arquivo3== NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else{
		for (int i = 0; i < tamanho - 1; i++){
			fprintf(arquivo3, "%s;", colunas [i] );
		}
		fprintf(arquivo3, "%s \n", colunas [tamanho - 1]);
		for (int i = 0; i < tamanho - 1; i++){
			fprintf(arquivo3, "%s;", tipos [i] );
		}
		fprintf(arquivo3, "%s \n",tipos [tamanho - 1]);
	}
	fclose(arquivo3);
	
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

void AdicionarLinhaTabela(){
	char titulo [30];
	int tamanho;
	char tabelaDados [40];
	char tabelaMeta [50];
	char extensao[] = ".txt\0";
	char meta[] = "Meta.txt\0";
	int nLinhas;
	char c;

	// PEGANDO O NOME DA TABELA PARA PODER SABER QUAIS ARQUIVOS MANIPULAR
	printf ("Insira o nome da tabela desejada:\n");
	scanf("%s", &titulo);
	
	strcpy (tabelaDados, titulo);
	strcpy (tabelaMeta, titulo);

	strcat (tabelaDados, extensao);
	strcat (tabelaMeta, meta);

	//CONTAR LINHAS DA TABELA META

	FILE *arquivo;
	arquivo = fopen(tabelaMeta,"rb");
	if(arquivo == NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else {
		nLinhas = 0;
		for (c = getc(arquivo); c != EOF; c = getc(arquivo)){
			if (c == '\n'){
				nLinhas++;
			} 
		}
	}
	fclose(arquivo);

	tamanho = nLinhas;

	//CRIAR COLUNAS [I] E TIPOS[I] COM OS DADOS DA TABELA META
	char colunas[tamanho][30];
	char tipos[tamanho][30];

	FILE *arquivo2;
	arquivo2 = fopen(tabelaMeta,"rb");
	if(arquivo2 == NULL){
		printf("Erro na abertura do arquivo!\n");
	}
	else {
		for (int i = 0; i < tamanho; ++i){
			
		}
	}
	fclose(arquivo2);

	//UTILIZAR COLUNAS [I] PARA PEDIR DADOS DE NOVALINHA[I] E TIPOS [I] PARA CHECAR SEUS TIPOS + CHECAR SE ID JÁ ESTÁ SENDO UTILIZADO

	//ADICIONAR DADOS AO ARQUIVO DA TABELA DE DADOS


}

void Menu () {

	int opcao = 0;
		printf ("Sistema de Gerenciamento de Banco de Dados (SGBD - ITP)\n");
		printf ("Autores: Maurício e Van Allen");

	do {
		printf ("\n\nPara realizar a função desejada, digite: \n\n");
		printf ("1 - Criar tabela\n2 - Listar todas as tabelas\n3 - Criar uma nova linha na tabela\n4 - Listar todos os dados de uma tabela\n");
		printf ("0 - Sair\n\n");
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
			case 3:
				AdicionarLinhaTabela();
				break;
			//case 4:
			//	ListarUmaTabela();
			//	break;	
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