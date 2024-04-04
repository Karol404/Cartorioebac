#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string



int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo,"w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a");
	fprintf(file,"; \n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,";\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	
	system("pause");
	
}	

int consultar() // Fun��o respons�vel por consultar usu�rios no sistema
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		// Declara��o de variav�is para armazenar CPF e conte�do do arquivo
		char cpf[40]; 
		char conteudo[200];
		//Fim da cria��o de v�riaveis/stings
		
		printf("Digite o CPF a ser consultado: "); //Solicita ao us�rio que digite o CPF a ser consultado 
		scanf("%s",cpf); //%s refere-se a string, l� o CPF digitado pelo us�ario
		
		
		
		FILE *file; 
		file = fopen(cpf,"r"); // Abre o arquivo CPF em modo leitura ("r")
		
			printf("\n Essas s�o as informa��es do usu�rio: "); //Exibe as informa��es do usu�rio 
			
		while(fgets(conteudo, 200, file) !=NULL) //L� e imprime o conte�do do arquivo linha por linha at� o final do arquivo
		{	
			printf("%s", conteudo); 
		}
		
		if(file == NULL) //Verifica se a abertura do arquivo foi bem-sucedida
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); // Se n�o foi possivel abri o arquivo, exibe essa mensagem de erro
		}
		
		printf("\n\n");
		system ("pause");
		
}
				
int deletar() // Fun��o respons�vel por deletar usu�rios no sistema
{
		char cpf[40]; // cria��o da v�riavel
		
		printf("Digite o CPF do usu�rio a ser deletado: "); 
		scanf("%s",cpf);
	
		remove(cpf); // Remove o arquivo
		
		printf("O usu�rio foi deletado com sucesso!.\n"); //Exibe essa mensagem ap�s deletar usu�rio
		system("pause");
		
		
		FILE *file;
		file = fopen(cpf,"r"); 

		if(file==NULL) //Verifica se abertura do arquivo foi bem sucedida 
		
		{
			printf("O Usu�rio n�o se encontra no sistema!.\n"); //Exibe mensagem de erro
			system("pause");
		}
		
		
		
		
}



int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco==1;)
	{
	
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
		
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sitema\n\n");
		printf("Op��o: ");	//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
		system("cls"); //respons�vel por limpar a tela
	
	
		switch(opcao)
		{
			case 1: 
			registrar(); //chama as fun��es 
			break;
			
			case 2: 
			consultar();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: 
				printf("Essa op��o n�o est� dispon�vel:\n");
				system("pause");
				break;	
			}
	}	
}
	





