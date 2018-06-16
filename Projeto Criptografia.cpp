#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

void gotoxy(int x, int y)
{ // serve para direcionar o cursor dentro do CMD
  COORD coord; 
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int criptografar(){      //Função que faz a criptografia do texto digitado pelo usuário
    
	char texto[25];
    int chave, tamanho_texto, cont;
 
    system("cls");
    //Sistema pede para que o usuário digite seu texto
 	printf("||========================================================================================||\n");
    printf("||Digite o texto a ser criptografado:                                                     ||\n||========================================================================================||\n\n\n");
    gotoxy(38,1);
    gets(texto);
 	 
 	//Usuário escolhe a chave a ser usada na criptografia 
    while(chave<1 || chave>25)
    {
    	printf("||========================================================================================||\n");
        printf("||Digite a chave desejada (Deve ser de 1 a 25):                                           ||\n||========================================================================================||\n\n");
        gotoxy(48,3);
		scanf("%d",&chave);
        fflush(stdin);
    }
 
 	/*Sistema pega a frase digitada e a chave escolhida pelo usuario, por metodo de substituição
	 é trocado os caracteres de acordo com a chave escolhida trocando de 1 em 1, 2 em 2 ate o limite de 25 os caracteres.*/
    tamanho_texto = strlen(texto); // ver quantos caracteres tem a string e salva no tamanho texto
    for(cont=0;cont<tamanho_texto;cont++) // enquanto o tam_text for menor q o cont, o for fica rodando
        texto[cont] = texto[cont]+chave*2; // aqui o texto é jogado em cada rodada do for, e a letra e trocada pela chave
 
 	printf("\n||========================================================================================||\n");
    printf("    RESULTADO = %s                                                                 ",texto);
    printf("\n||========================================================================================||\n");
    getchar();
}


int descriptografar(){ //Função que faz a descriptografia do texto digitado pelo usuário
	
    char texto[25];
    char texto_str[25];
    int chave, tamanho_texto, cont;
 
    system("cls");
 	 //Sistema pede para que o usuário digite seu texto a ser descriptografado
 	printf("||========================================================================================||\n");
    printf("||Digite o texto a ser descriptografado:                                                  ||\n||========================================================================================||\n\n");
    gotoxy(41,1);
    gets(texto);
 
 	//Usuário escolhe a chave a ser usada na descriptografia 
    while(chave<1 || chave>25)
    {
        printf("||========================================================================================||\n");
        printf("||Digite a chave utilizada na criptografia (Deve ser de 1 a 25):                          ||\n||========================================================================================||\n\n");
        gotoxy(65,3);
        scanf("%d",&chave);
        fflush(stdin);
    }
 
 	/*Sistema pega a frase digitada e a chave escolhida pelo usuario, por metodo de substituição
	 é trocado os caracteres de acordo com a chave escolhida trocando de 1 em 1, 2 em 2 ate o limite de 25 os caracteres.*/
    tamanho_texto = strlen(texto); // ver quantos caracteres tem a string e salva no tamanho texto
    for(cont=0;cont<tamanho_texto;cont++) // enquanto o tam_text for menor q o cont, o for fica rodando
        texto[cont] = texto[cont]-chave*2; // aqui o texto é jogado em cada rodada do for, e a letra e trocada pela chave

 
   printf("\n||========================================================================================||\n");
    printf("   RESULTADO = %s                                                             ",texto);
    printf("\n||========================================================================================||\n");
    getchar();
}
 
int main(int argc, char* argv[]){ //Menu principal do Sistema - 1ª Tela
	
    int escolha;
    do
    {
        system("cls");
		 
    printf("\n||===============================================||\n");
	printf("||                   PROJETO DE                  ||\n");
	printf("||         CRIPTOGRAFIA E DESCRIPTOGRAFIA        ||\n");
	printf("||===============================================||\n");
	printf("||            Escolha a opcao desejada:          ||\n");
	printf("||===============================================||\n");
	printf("||       1 -)         CRIPTOGRAFAR               ||\n");
	printf("||===============================================||\n");
	printf("||       2 -)        DESCRIPTOGRAFAR             ||\n");
	printf("||===============================================||\n");
	printf("||       3 -)               SAIR                 ||\n");
	printf("||===============================================||\n");
	printf("||                 ESCOLHA: (___)                ||\n");
	printf("||===============================================||\n"); 
	
 	gotoxy(30,13);
        scanf("%d",&escolha);
        fflush(stdin);
 
        switch(escolha)
        {
            case 1 : criptografar(); 
                     break;
            case 2 : descriptografar();
                     break;
            case 3 : 
            		exit(0);
            		break;
        }
    }
    while(escolha!=3);
}
 

