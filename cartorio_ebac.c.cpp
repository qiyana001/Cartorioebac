#include <stdio.h> 
#include <stdlib.h> // BIBLIOTECA DE ALOCA��O DE ESPA�O NA MEM�RIA
#include <locale.h> // BIBLIOTECAC DE ALOCA��O POR REGI�O
#include <string.h> //BIBLIOTECA PARA USAR A STRING

int registrar()//fun��o responsavel por cadastrar usu�rios
{
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser registrado:\n");//coletando informa��o dos usu�rios
	scanf("%s" , cpf);//%s � para strings
	
	strcpy(arquivo,cpf);// responsavel por armazenar o valor das strings
	
	FILE *file; // criando arquivos na pasta
	file = fopen(arquivo, "w"); //criando arquivo
	fprintf(file,cpf);// salva o falor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" serve para adicionar no arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para adicionar no arquivo
	fprintf(file," ");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para adicionar no arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");// definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");

	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel localizar o arquivo");
	}
	
	while(fgets(conteudo,200,file) != NULL)//enquanto "fgets" vai buscar o arquivo, busca o conte�do, tamanho maximo � "200"
	{
		printf("\nEssas s�o as informa��es do usu�rios: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o esta mais no sistema.\n");
		system("pause");
    }
    

	system("pause");
}



int main()
{
int opcao=0;
int x=1;

for(x=1;x=1;)
{

    system("cls");//responsavel por limpar a tela


	setlocale(LC_ALL, "portuguese");

	printf("### CART�RIO DA EBAC ###\n\n");
	printf("escolha a op��o desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
    printf("\t4 - sair do sistema\n");
    printf("op��o:");
    
    scanf("%d" , &opcao);//armazenando a escolha do usu�rio

    system("cls");

    switch(opcao)
	{
	case 1:
    registrar();
    break;
  
    case 2:  
    consultar();
    break;
    
    case 3:
	deletar();
    break;
    
    case 4:
    printf("obrigado por utilizar o programa");
	return 0;
	break;
		
    
    default: 
	printf("ops! essa op��o n�o est� disponivel\n");
	system("pause");
    break;
    }
  }  
}








