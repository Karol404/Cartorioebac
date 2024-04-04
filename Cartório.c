#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string



int registrar() //Função responsável por cadastrar os usuários no sistema
{
	
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
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

int consultar() // Função responsável por consultar usuários no sistema
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		// Declaração de variavéis para armazenar CPF e conteúdo do arquivo
		char cpf[40]; 
		char conteudo[200];
		//Fim da criação de váriaveis/stings
		
		printf("Digite o CPF a ser consultado: "); //Solicita ao usário que digite o CPF a ser consultado 
		scanf("%s",cpf); //%s refere-se a string, lê o CPF digitado pelo usúario
		
		
		
		FILE *file; 
		file = fopen(cpf,"r"); // Abre o arquivo CPF em modo leitura ("r")
		
			printf("\n Essas são as informações do usuário: "); //Exibe as informações do usuário 
			
		while(fgets(conteudo, 200, file) !=NULL) //Lê e imprime o conteúdo do arquivo linha por linha até o final do arquivo
		{	
			printf("%s", conteudo); 
		}
		
		if(file == NULL) //Verifica se a abertura do arquivo foi bem-sucedida
		{
			printf("Não foi possivel abrir o arquivo, não localizado!. \n"); // Se não foi possivel abri o arquivo, exibe essa mensagem de erro
		}
		
		printf("\n\n");
		system ("pause");
		
}
				
int deletar() // Função responsável por deletar usuários no sistema
{
		char cpf[40]; // criação da váriavel
		
		printf("Digite o CPF do usuário a ser deletado: "); 
		scanf("%s",cpf);
	
		remove(cpf); // Remove o arquivo
		
		printf("O usuário foi deletado com sucesso!.\n"); //Exibe essa mensagem após deletar usuário
		system("pause");
		
		
		FILE *file;
		file = fopen(cpf,"r"); 

		if(file==NULL) //Verifica se abertura do arquivo foi bem sucedida 
		
		{
			printf("O Usuário não se encontra no sistema!.\n"); //Exibe mensagem de erro
			system("pause");
		}
		
		
		
		
}



int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco==1;)
	{
	
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sitema\n\n");
		printf("Opção: ");	//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário 
	
		system("cls"); //responsável por limpar a tela
	
	
		switch(opcao)
		{
			case 1: 
			registrar(); //chama as funções 
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
				printf("Essa opção não está disponível:\n");
				system("pause");
				break;	
			}
	}	
}
	





