#define N 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printprecos(){
	system("cls");
		    printf("\n==========================Bilhetes================================\n\n"); 
    	    printf("******************************************************************\n");
    	    printf("| Bancadas                       | Maiores de 12 | Menores de 12 |\n"); 
			printf("******************************************************************\n");
			printf("| (1)Peao                        |     100€      |      85€      |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (2)Solverde                    |     145€      |      120€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (3)Sagres                      |     175€      |      150€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (4)Sul                         |     225€      |      190€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (5)Portimao 2                  |     265€      |      225€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (6)Portimao                    |     290€      |      245€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (7)Lagos                       |     335€      |      285€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (8)Norte                       |     350€      |      310€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (9)Oeste                       |     380€      |      325€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (10)Bancada Principal Inferior |     450€      |      390€     |\n");
			printf("------------------------------------------------------------------\n");
			printf("| (11)Bancada Principal Superior |     655€      |      585€     |\n"); 
			printf("******************************************************************\n");
}


void escreveMatriz(int mat[N][N]){
    
	int i,j;
    for(i=0; i<N ; i++){
        for(j=0; j<N; j++){
            if(mat[i][j]!=0 && mat[i][j]!=2){
            	printf("1  ");
			}else{	
			    printf("%d  ", mat[i][j]);
			}
		
			
        }
        printf("\n");
    }
}


void bancada(int mat[N][N]){
    // 1 0 0
    // 0 1 0
    // 0 0 1
    
    int i,j;
    int letra = 65;
	for(i=0; i<N ; i++){
        for(j=0; j<N; j++){
            if ((i+j)%2==0)
                mat[i][j]= 2;
            else
                mat[i][j]= 0;
        }
    }
}

void *comprabilhetes(int matriz[N][N]){
	
	int i, max, nif, coluna, filaNum, nome, idade, money;
	char linha = 0;
    escreveMatriz(matriz);
    /*printf("\nIntroduza o primeiro e ultimo nome:");
    scanf("%c ", &nome);
    getchar();
    printf("\nInsira a idade:");
    scanf("%d ", &idade);
    getchar();
    if (idade>=12){
    money=100;
	}else{
	money=85;
	}*/
    
   printf("\n Introduza o NIF:");
   scanf("%d", &nif);
   getchar();
   if(nif<99999999 || nif>999999999){
       printf("NIF inexistente...");
       return matriz;
   }
   printf("Quantos bilhetes quer comprar?");
   scanf("%d", &max);
   getchar();
   for(i=0; i<max; i++){

   printf("\nSelecione o seu lugar, introduzindo a letra da fila:");
   scanf("%c", &linha);
   getchar();
   printf ("\nSelecione o seu lugar, introduzindo a coluna:");
   scanf("%d", &coluna);
   getchar();

   if(coluna == -1) return matriz;

   filaNum = (int) linha - 65;
   coluna--;


   if(matriz[filaNum][coluna] >= 1){

       printf("\n\nEsse lugar já está ocupado! Escolha outro:\n\n");
   }
   else{
       matriz[filaNum][coluna] = 0;
       printf("\n\nLugar reservado com sucesso!\n\n");
       

       matriz[filaNum][coluna] = nif;
       matriz[N][N] = matriz[filaNum][coluna];
    }
    }
    /*printf("\n=================Bilhete Fórmula 1=================\n");
    printf("|                                                 |\n");
    printf("| Nome: %c                                        |\n", nome);
    printf("| NIF: %d                                         |\n", nif);
    printf("| Lugar: %c %d                                    |\n", linha, coluna);
    printf("|                                           F1    |\n");
    printf("===================================================\n");*/
    
    return 0;
}

void apresentacao(){
	printf("*************************************************************************");
    printf("\n\n*  FFFFFFF  OOOOOOO  RRRRRRR M     M  U     U  L        AAAAAAA      1  *");
	printf("\n*  F        O     O  R     R MM   MM  U     U  L        A     A     11  *");
	printf("\n*  FFFFFFF  O     O  RRRRRRR M  MM M  U     U  L        AAAAAAA    1 1  *");
	printf("\n*  F        O     O  R  R    M     M  U     U  L        A     A      1  *");
	printf("\n*  F        OOOOOOO  R   R   M     M  UUUUUUU  LLLLLLL  A     A      1  *");
	printf("\n*                                                                       *");
	printf("\n*                                                                       *");
	printf("\n*                     GRANDE PREMIO ALGARVE                             *");
	printf("\n\n*************************************************************************\n");
}

int main() {
	
	char username[50]; 
    char password[12];
	char nome[50];
    int op, op1, op2;
    int matriz[N][N], nif;
    char linha = 0;
    int coluna, filaNum, i, j, ocup=0, money=0, idade;


    apresentacao();
    bancada(matriz);


    printf("\nEnter your username:\n"); 
    scanf("%s",username); 
    getchar();
 
	printf("Enter your password:\n"); 
    scanf("%s",password); 
    getchar();
  
    if(strcmp(password,"fartodisto")==0){ 
 
    printf("\nWelcome.Login Success!\n"); 

    }
	else
	{ 
    printf("\nWrong password"); 
    return 0;
    }  
	system("cls");
    do{
    printf("\n(1)-Tabela de Preços\n(2)-Bilhetes\n(3)-Check in\n(4)-Loja\n(5)-Sair\n");
    printf("\n\nIntroduza a operação desejada:");
    scanf("%d", &op);
    getchar();
    
    switch(op)
    {
    	case 1:
			printprecos();
    		break;
    	case 2: 
    	    system("cls");
			printf("================Bilhetes==================");
    	    printf("\n(1)-Comprar bilhetes\n(2)-Trocar lugar\n(3)-Cancelar reserva\n");
			scanf("%d", &op2);
			getchar();
			
			switch(op2){
				case 1:
		            printprecos();
			
			printf("Introduza a bancada que deseja:");
			scanf("%d", &op1);
			getchar();
			
			switch(op1)
			{
				case 1:
				    comprabilhetes(matriz);
					break;
				case 2:
					//Passar lugar do nif a 0 e devolver para a compra de bilhetes
					system("cls");
					printf("Intrduza o NIF:");
					scanf("%d", &nif);
					getchar();
					break;
				case 3:
					// Passar lugar do nif a 0
					system("cls");
					printf("Introduza o NIF:");
					scanf("%d", &nif);
					getchar();
					
					
					break;
			}
			
					break;
				case 2:
					printf("a");
					break;
				case 3:
					printf("a");
				    break;
				case 4:
					printf("a");
					break;
				case 5:
					printf("a");
				    break;
				case 6:
					printf("a");
					break;
				case 7:
					printf("a");
					break;
				case 8:
					printf("a");
					break;
				case 9:
					printf("a");
					break;
				case 10:
					printf("a");
					break;
				case 11:
					printf("a");
					break;
			}
    	    break;
    	case 3:
    	    printf("\n=====================Check in============================");
    	        printf("Introduza o NIF para confirmar entrada");
    	        scanf("%d", &nif);
    	        getchar();
    	    break;
    	case 4:
    		printf("\n=====================Loja===========================");
    		break;
    	case 5:
    		printf("\nSair");
    		break;
    	default:
    		break;
	}
   }while(op!=5);
	
	return 0;
	
}




