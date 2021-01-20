#define N 26
#define K 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correrMatriz(int nif,  int mat[K][N][N]);
void escreveMatriz(int mat[N][N]);
int lugaresMatriz(int mat[N][N]);
void printprecos(int matriz[K][N][N]);
void bancada(int mat[K][N][N]);
void apresentacao();
int VerificaIdade(int idade);
int comprabilhetes(int max, int matriz[N][N]);
int QuantBilhetes();
int abrirSessao(int matriz[K][N][N]);
void fecharSessao(int matriz[K][N][N]);
int apresentaBilhete(char nome[], char apelido[], int nif, char linha, int coluna);
int loja(int money);
void escolherequipas();
int escolhertamanho(int money);
void troco(int money);
int querloja(int money);
int preco(int i, int idade);

int main(){
	int op, op1, op2;
	int matriz[K][N][N], nif;
	char linha = 0;
	int coluna, filaNum, i, j, k, l=0, money=0, idade, max;


	apresentacao();
	
    if(abrirSessao(matriz) == 2){
    	bancada(matriz);
    	for(k=0; k<K; k++) escreveMatriz(matriz[k]);
	}
		
    if((iniciarSessao())==3) {
		return 0; 
	}

	system("cls");
	
	do{
		printf("\n(1)-Tabela de Preços\n(2)-Bilhetes\n(3)-Check in\n(4)-Loja\n(5)-Sair\n");
		printf("\n\nIntroduza a operação desejada:");
		scanf("%d", &op);
		getchar();

		switch(op){
			case 1:
				printprecos(matriz);
				getchar();
				system("cls");
			break;
			case 2: 
				system("cls");
				printf("================Bilhetes==================");
				printf("\n(1)-Comprar bilhetes\n(2)-Trocar lugar\n(3)-Cancelar reserva\n");
				scanf("%d", &op1);
				getchar();
				switch(op1){
					case 1:
						printprecos(matriz);
						printf("Introduza a bancada que deseja:");
						scanf("%d", &op2);
						getchar();

						printf("\n=============================================Bancada %d===================================================\n", op2);
						printf("Introduza a sua idade");
						scanf("%d", &idade);
						getchar();
						
						max = QuantBilhetes();
						comprabilhetes(max, matriz[op2-1]);
						money = preco(op2-1, idade);
						money*=max;
						querloja(money);
						
						break;
					case 2:
						//Passar lugar do nif a 0 e devolver para a compra de bilhetes
						money=0;
						system("cls");
						printf("Introduza o NIF:");
						scanf("%d", &nif);
						getchar();
						money = correrMatriz(nif, matriz);
						printf("\nDevolver ao cliente a quantia de: %d €\n", money);
						getchar();
						system("cls");
						//retornar para a loja
						printprecos(matriz);
						printf("Introduza a bancada que deseja:");
						scanf("%d", &op2);
						getchar();

						printf("\n=============================================Bancada %d===================================================\n", op2);
						
						max = QuantBilhetes();
						comprabilhetes(max, matriz[op2-1]);
						money -= preco(op2-1, idade) * max;
						if(money<0){
							troco(-money);
						}else troco(money);
						system("cls");
					break;
					case 3:
						// Passar lugar do nif a 0
						money=0;
						system("cls");
						printf("Introduza o NIF:");
						scanf("%d", &nif);
						getchar();
						money = correrMatriz(nif, matriz);
						printf("\nDevolver ao cliente a quantia de: %d €\n", money);
						getchar();
				
						printf("Reserva Cancelada...");
						getchar();
						system("cls");
					break;
				}
			break;
			case 3:
				printf("\n=====================Check in============================");
				printf("\n\nIntroduza o NIF para confirmar entrada: ");
				scanf("%d", &nif);
				getchar();
				for(k=0; k<K; k++){
					for(i=0; i<N; i++){
						for(j=0; j<N; j++){
							if(matriz[k][i][j]==nif){
								l++;
								printf("\nEstá inscrito no sistema, pode prosseguir");
								getchar();
								system("cls");
								break;
							}	
						} 
					}
				}
				if(l==0){
					printf("Reserva nao encontrada...");
					getchar();
					system("cls");
				}	
						
			break;
			case 4:
				printf("\n=====================Loja===========================");
				money=0;
				loja(money);
			default:
				break;
		}
	}while(op!=5);

	fecharSessao(matriz);

	return 0;
}

void escolherequipas ()
{
    printf ("Selecione a equipa\n");
    printf ("|----------------------------------|\n");
    printf ("| Equipas         |     Preço      |\n");
    printf ("|----------------------------------|\n");
    printf ("| 1 - Mercedes     |     45€       |\n");
    printf ("|----------------------------------|\n");
    printf ("| 2 - Ferrari     |      35€       |\n");
    printf ("|----------------------------------|\n");
    printf ("| 3 - McLaren      |     40€       |\n");
    printf ("|----------------------------------|\n");
    printf ("| 4 - RedBull      |     30€       |\n");
    printf ("|----------------------------------|\n");
    printf ("| 5 - Renault      |     30€       |\n");
    printf ("|----------------------------------|\n");
}

int escolhertamanho (int money)
{
	int menutamanhos = 0;
    printf ("Selecione o seu tamanho\n");
    printf ("|------------------------|\n");
    printf ("|----- T a m a n h o ----|\n");
    printf ("|------------------------|\n");
    printf ("| 1-        S            |\n");
    printf ("|------------------------|\n");
    printf ("| 2-        M            |\n");
    printf ("|------------------------|\n");
    printf ("| 3-        L            |\n");
    printf ("|------------------------|\n");
    scanf("%d", &menutamanhos);
	
	switch(menutamanhos)
	{
		case 1:
			system ("cls");
			troco(money);
			break;
		case 2:
			system ("cls");
			troco(money);
			break;
		case 3:
			system ("cls");
			troco(money);
			break;
		default:
			break;
	}
}

void troco (int money)
{
    int quantia, troco,n500=0,n200=0,n100=0,n50=0,n20=0,n10=0,n5=0,m2=0,m1=0;
    printf("--------------Sistema de pagamento------------ \n");
    printf("\nTotal a pagar-------------------%d €\n", money);
    
    printf("\nInsira quanto recebeu do adepto:\n");
    scanf("%d", &quantia);
    getchar();
    
    // Calcular o troco//
    troco=quantia-money;
         
	if (troco!=0)
    {
        printf("O troco e: %d\n", troco);
		do
	    {
	        if(troco-500>=0)
	        {
	        	n500++;
	        	troco=troco-500;
	        }
	    }while(troco>=500);
	       
	    do
	    {
	        if(troco-200>=0)
	        {
	            n200++;
	            troco=troco-200;
	        }
	    }while(troco>=200);
	        
	    do
	    {
	        if(troco-100>=0)
	        {
	      	    n100++;
	            troco=troco-100;
	        }
	    }while(troco>=100);
	       
	    do
	    {
	        if(troco-50>=0)
	        {
	            n50++;
	            troco=troco-50;
	        }
	            
	         
	    }while(troco>=50);
	    
	    do
	    {
	    	if(troco-20>=0)
	        {
	        	n20++;
	            troco=troco-20;
	        }
	    }while(troco>=20);
	    
	    do
	    {
	        if(troco-10>=0)
	        {
	            n10++;
	            troco=troco-10;
	        }
	    }while(troco>=10);
	    
	    do
	    {
	        if(troco-5>=0)
	        {
	            n5++;
	            troco=troco-5;
	        }
	    }while(troco>=5);
	    
	    do
	    {
	        if(troco-2>=0)
	        {
	            m2++;
	            troco=troco-2;
	        }
	    }while(troco>=2);
	    
	    do
	    {
	        if(troco-1>=0)
	        {
	        	m1++;
	            troco=troco-1;
	        }
		}while(troco>=1);
	    
		if(n500>0)
	    {
	        printf("notas de 500 euros: %d \n", n500);
	    }
	     
		if(n200>0)
	    {
	        printf("notas de 200 euros: %d \n", n200);
	    }
	     
	    if(n100>0)
	    {
	        printf("notas de 100 euros: %d \n", n100);
	    }
	     
	    if(n50>0)
	    {
	        printf("notas de 50 euros: %d\n", n50);
	    }
	    if(n20>0)
	    {
	        printf("notas de 20 euros:%d \n", n20);
	    }
	    if(n10>0)
	    {
	        printf("notas de 10 euros: %d \n", n10);
	    }
	    if(n5>0)
	    {
	        printf("notas de 5 euros: %d \n", n5);
	    }
	    if(m2>0)
	    {
	        printf("moedas de 2 euros: %d \n", m2);
	    }
	    if(m1>0)
	    {
	        printf("moedas de 1 euros: %d \n", m1);
	    }
    }
    else
    {
        printf("Nao tem troco!");
    }
	
    printf("\n\nCompra efetuada com sucesso!\n");
    getchar();
}


int loja(int money) {
    
    // Entrada na loja
    
    int menuloja, menuequipas = 0;
    
    
    printf("-----------Bem vindo à loja-------------");
    
              // Tabela de artigos com o menu switch
    system("cls");
     
    printf("\nEscolha o artigo\n");
    printf("|--------------------|\n");
    printf("|1-     T-shirt      |\n");
    printf("|--------------------|\n");
    printf("|2-     Bones        |\n");
    printf("|--------------------|\n");
    scanf("%d", &menuloja);
    

    switch(menuloja)
    
                        
                              // T-shirt, Menu equipas (Mercedes S)
        {
            case 1:
            system ("cls");
        
                escolherequipas();
                scanf("%d", &menuequipas);
                
                switch(menuequipas)
                {
                    case 1:
                    	money+=45;
						escolhertamanho(money);
                    	break;
                    case 2:
                    	money+=35;
                    	escolhertamanho(money);
                    	break;
                    case 3:
                    	money+=40;
                    	escolhertamanho(money);
                    	break;
                    case 4:
                    	money+=30;
                    	escolhertamanho(money);
                    	break;
                    case 5:
                    	money+=30;
						escolhertamanho(money);
                    	break;
                    default: 
						break;
				}
			    break;
			case 2:
            system ("cls");
        
                escolherequipas();
                scanf("%d", &menuequipas);
                
                switch(menuequipas)
                {
                    case 1:
                    	money+=45;
                    	escolhertamanho(money);
                    	break;
                    case 2:
                    	money+=35;
                    	escolhertamanho(money);
                    	break;
                    case 3:
                    	money+=40;
                    	escolhertamanho(money);
                    	break;
                    case 4:
                    	money+=30;
                    	escolhertamanho(money);
                    	break;
                    case 5:
                    	money+=30;
						escolhertamanho(money);
                    	break;
                    default: 
						break;
				}
			    break;
			default: 
				break;
        }
    system("cls");
        
    return 0;
}


void escreveMatriz(int mat[N][N])
{
    int i,j;
    int letra = 65;
    
    printf("   |");
    for(j=1;j<=N;j++)
    {
        if(j<10)
        {
            printf(" %d |", j);
        }
        else
        {
            printf(" %d|", j);
        }
    }
    printf("\n");
    for(j=1;j<=N+1;j++)
    {
        printf("----");
    }
    printf("\n");
       for(i=0; i<N; i++)
         {
             printf(" %c |", letra++);
                for(j=0;j<N;j++){
				
        			if(mat[i][j]!=0 && mat[i][j]!=2){
                    	printf(" O %c", j == N ? ' ':'|');
                	}else if(mat[i][j]==2){
                		printf(" X %c", j == N ? ' ':'|');
					}else{
						printf("   %c", j == N ? ' ':'|');
					}
                }
                        
             printf("\n");
               for(j=1;j<=N+1;j++)
                {
                printf("----");
                }
                printf("\n");
        }
    printf("\nX->Lugar nao disponibilizado devido as normas da DGS\nO->Lugares ocupados\n");
}

int lugaresMatriz(int mat[N][N]){
	int i, j, k=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(mat[i][j] == 0) k++;
		}
	}
	return k;
}

int correrMatriz(int nif, int mat[K][N][N])
{
	int idade;
	printf("=====Confirmação de idade pelo CC=====\n\nIntroduza a idade:");
	scanf("%d", &idade);
	getchar();
	
	int max=0; 
	int i, j, k;
	for(k=0; k<K; k++){
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(mat[k][i][j]==nif){
					mat[k][i][j]=0;
					max+= preco(k, idade);
				}
			}
		}
	}
	return max;
}

void printprecos(int matriz[K][N][N]){
	system("cls");
    printf("****************************************************************************************\n");
    printf("| Bancadas                       | Maiores de 12 | Menores de 12 | Lugares disponíveis |\n"); 
	printf("****************************************************************************************\n");
	printf("| (1)Peao                        |     100€      |      85€      |         %d          |\n", lugaresMatriz(matriz[0]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (2)Solverde                    |     145€      |      120€     |         %d          |\n", lugaresMatriz(matriz[1]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (3)Sagres                      |     175€      |      150€     |         %d          |\n", lugaresMatriz(matriz[2]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (4)Sul                         |     225€      |      190€     |         %d          |\n", lugaresMatriz(matriz[3]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (5)Portimao 2                  |     265€      |      225€     |         %d          |\n", lugaresMatriz(matriz[4]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (6)Portimao                    |     290€      |      245€     |         %d          |\n", lugaresMatriz(matriz[5]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (7)Lagos                       |     335€      |      285€     |         %d          |\n", lugaresMatriz(matriz[6]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (8)Norte                       |     350€      |      310€     |         %d          |\n", lugaresMatriz(matriz[7]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (9)Oeste                       |     380€      |      325€     |         %d          |\n", lugaresMatriz(matriz[8]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (10)Bancada Principal Inferior |     450€      |      390€     |         %d          |\n", lugaresMatriz(matriz[9]));
	printf("----------------------------------------------------------------------------------------\n");
	printf("| (11)Bancada Principal Superior |     655€      |      585€     |         %d          |\n", lugaresMatriz(matriz[10])); 
	printf("****************************************************************************************\n");
}

void bancada(int mat[K][N][N]){
    
	int i,j,k;
	
	for(k=0; k<K; k++){
		for(i=0; i<N ; i++){
	        for(j=0; j<N; j++){
	            if ((i+j)%2==0)
	                mat[k][i][j]= 2;
	            else
	                mat[k][i][j]= 0;
	        }
	    }  
   }
}

int VerificaIdade(int idade)
{
    if (idade>=12 && idade<150){
        return 1;
        
	}else if(idade>0 && idade<12){
	    return 2;
	    
	}else if(idade<=0 && idade >150){
		printf("Idade inválida");
		getchar();
		return;
	}
}

int QuantBilhetes()
{
	int max;
	printf("\nQuantos bilhetes quer comprar?");
    scanf("%d", &max);
    return max;
    getchar();
}


int comprabilhetes(int max, int matriz[N][N]){
	
	int i, nif, coluna, filaNum;
	char linha = 0;
	char nome[50], apelido[50];
    escreveMatriz(matriz);
    FILE *fp = fopen("bilhetes.txt","wb");
    
	printf("\nIntroduza o primeiro e ultimo nome:");
    scanf("%s %s", nome, apelido);
    getchar();
    
   	printf("\n Introduza o NIF (9 dígitos):");
   	scanf("%d", &nif);
   	getchar();
  	if(nif<99999999 || nif>999999999){
       printf("NIF inexistente...");
       getchar();
       system("cls");
       return;
   }

   for(i=0; i<max; i++){

	   printf("\nSelecione o seu lugar, introduzindo a letra da fila:");
	   scanf("%c", &linha);
	   getchar();
	   printf ("\nSelecione o seu lugar, introduzindo a coluna:");
	   scanf("%d", &coluna);
	   getchar();

	   if(coluna <= 0) return;

	   filaNum = (int) linha - 65;
	   coluna--;


	   if(matriz[filaNum][coluna] >= 1){

	       printf("\n\nEsse lugar já está ocupado! Escolha outro:\n\n");
	       i-=1;
	   }
	   else{
	       	matriz[filaNum][coluna] = 0;
	       	printf("\n\nLugar reservado com sucesso!\n\n");
	       	apresentaBilhete(nome, apelido, nif, linha, coluna);
			
			fprintf(fp,"\n=================Bilhete Fórmula 1=================\n");
		    fprintf(fp,"|                                                 |\n");
		    fprintf(fp,"  Nome: %s %s                                \n", nome, apelido);
		    fprintf(fp,"| NIF: %d                                  |\n", nif);
		    fprintf(fp,"  Lugar: %c %d                                       \n", linha, coluna+1);
		    fprintf(fp,"|                                           F1    |\n");
		    fprintf(fp,"===================================================\n");
		    
	   	   matriz[filaNum][coluna] = nif;
	    }
    }
	getchar();
    fclose(fp);
	system("cls");
    
}
int apresentaBilhete(char nome[], char apelido[], int nif, char linha, int coluna)
{
	printf("\n=================Bilhete Fórmula 1=================\n");
    printf("|                                                 |\n");
    printf("  Nome: %s %s                               \n", nome, apelido);
    printf("| NIF: %d                                  |\n", nif);
    printf("  Lugar: %c %d                                      \n", linha, coluna+1);
    printf("|                                           F1    |\n");
    printf("===================================================\n");
}
void apresentacao(){
	printf("*************************************************************************");
	printf("\n|                                                                       |");
    printf("\n|  FFFFFFF  OOOOOOO  RRRRRRR M     M  U     U  L        AAAAAAA      1  |");
	printf("\n|  F        O     O  R     R MM   MM  U     U  L        A     A     11  |");
	printf("\n|  FFFFFFF  O     O  RRRRRRR M  MM M  U     U  L        AAAAAAA    1 1  |");
	printf("\n|  F        O     O  R  R    M     M  U     U  L        A     A      1  |");
	printf("\n|  F        OOOOOOO  R   R   M     M  UUUUUUU  LLLLLLL  A     A      1  |");
	printf("\n|                                                                       |");
	printf("\n|                                                                       |");
	printf("\n|                     GRANDE PREMIO ALGARVE                             |");
	printf("\n|                                                                       |");
	printf("\n*************************************************************************\n");
}

int abrirSessao(int matriz[K][N][N]){
	FILE *fp = fopen("estado.txt", "rb");
	int i, k;
	if(fp != NULL){
		for(k=0; k<=K; k++){
			for(i=0; i<N; i++){
				fread(&matriz[k][i], sizeof(int), N, fp);
			}
		}
		fclose(fp);
		return 3;
	}else return 2;
}

void fecharSessao(int matriz[K][N][N]){
	FILE *fp = fopen("estado.txt", "wb");
	int i, k;
	for(k=0; k<=K; k++){
		for(i=0; i<N; i++){
			fwrite(&matriz[k][i], sizeof(int), N, fp);
		}
	}
	fclose(fp);
}

int querloja(int money)
{
	int op;
	printf("Deseja ir para a loja?\n(1)Sim\n(2)Nao\n\n");
	scanf("%d", &op);
	switch(op)
	{
		case 1:
			loja(money);
			break;
		case 2:
			troco(money);
			break;
		default: break;
	}
	system("cls");
}

int preco(int i, int idade){
	switch(i){
		case 0:	
			if(VerificaIdade(idade)==2){
			   return 85;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 100;
			}
			break;
		case 1: 
			if(VerificaIdade(idade)==2){
			   return 120;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 145;
			}
			break;
		case 2:
			if(VerificaIdade(idade)==2){
			   return 150;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 175;
			}
			break;
		case 3:
			if(VerificaIdade(idade)==2){
			   return 190;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 225;
			}
			break;
		case 4:
			if(VerificaIdade(idade)==2){
			   return 225;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 265;
			}
			break;
		case 5:
			if(VerificaIdade(idade)==2){
			   return 245;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 290;
			}
			break;
		case 6:
			if(VerificaIdade(idade)==2){
			   return 285;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 335;
			}
			break;
		case 7:
			if(VerificaIdade(idade)==2){
			   return 310;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 350;
			}
			break;
		case 8:
			if(VerificaIdade(idade)==2){
			   return 325;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 380;
			}
			break;
		case 9:
			if(VerificaIdade(idade)==2){
			   return 390;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 450;
			}
			break;
		case 10:
			if(VerificaIdade(idade)==2){
			   return 585;
			}
			else if(VerificaIdade(idade)==1){ 
			   return 655;
			}
			break;
		default: break;
	}
}

int iniciarSessao(){
	char username[4]; 
	char password[10];

	printf("\nEnter your username:\n"); 
	fgets(username, 4, stdin); 
	username[strlen(username)-1] = '\0';


	printf("Enter your password:\n"); 
	fgets(password, 10, stdin); 
	password[strlen(password)-1] = '\0';

	if((strcmp(username,"ff")==0)&&(strcmp(password,"ffcodigo")==0)){ 
		printf("\nWelcome.Login Success!\n"); 
	}else{ 
		printf("\nWrong password"); 
		return 3;
	}
}






