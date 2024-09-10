#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%$ se refere a string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das Strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");  //abre o arquivo e o "w" significa escrever
	fprintf(file,cpf);  //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //%s se refere a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s se refere a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informçaõ do usuário
	scanf("%s", cargo); //%$ se refere a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela
		
}

int consulta() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	//início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%$ se refere a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file); //fecha o arquivo
}

int deletar() //função responsável por deletar os usuários no sistema
{
	//início da criação de variáveis/strings
	char cpf[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //%$ se refere a string 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");	
		printf("Opção: "); //fim do Menu
	
		scanf ("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");	//responsável por limpar a tela
		
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		} //fim da seleção
		
	}	

}
