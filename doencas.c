#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
#include <math.h>

typedef struct {
	int *v;
	int tamanho;
}lista;

typedef struct grafo{

	int **M;
	lista *lista_ver;
	int V;
	int A;
	int *grau;
	
} grafo;

typedef struct vert{

	int estado;//0-suscetível 1-morto  2 - infectado 3-recuperado
	int t_inf;
} vert;

void ins_lis(lista **lista, int a, int b,int incremento);

void aloca_vet(int **v,int tam){//aloca vetor dinamicamente

	int i=0;

	(*v) = (int *) malloc((tam+1)* sizeof(int));

	for(i=0 ; i<= tam ; i++){
		(*v)[i] = 0;
	}
}

void aloca_mat(int ***a, int nver){//aloca matriz dinamicamente
	
	int i=0,j=0;

	(*a) = (int **) malloc( (1+nver)*sizeof(int *));

	for( i=0 ; i<= nver ; i++){
	
		(*a)[i] = (int *) malloc( (nver+1) * sizeof(int));	
		for( j =0 ; j<= nver ; j++){
			(*a)[i][j] = 0;
		}
	}
}

void inici_grafo( grafo ** M, int nvert){//inicia grafo que representa a topologia

	int i=0;
	
	(*M) = (grafo*) malloc(sizeof(grafo));
	(*M)->A = 0;
	(*M)->V = nvert;
	(*M)->lista_ver = (lista *) malloc(sizeof(lista));
	aloca_vet(&((*M)->lista_ver->v),nvert);
	(*M)->lista_ver->tamanho=0;
	for( i=1 ; i <= nvert ; i++){
		ins_lis(&((*M)->lista_ver),i,0,1);
	}
	aloca_mat(&((*M)->M),nvert);
	aloca_vet(&((*M)->grau),nvert); 
	for( i=1 ; i<= nvert ; i++){	
		(*M)->grau[i] = 0;
	}
}

void inici_lver(vert *a,int nver,int op){//inicia a lista de vertices que controla o estado dos individuos

	int k=0,i=0,b=0,o=0;
	if(op==1){//se op == 1, os infectados serão escolhidos aleatoriamente
	printf("\nDIGITE UM NÚMERO <= 1000 QUE REPRESENTE OS INDIVÍDUOS INFECTADOS\n");
	scanf("%d",&k);
	srand(time(NULL));

	for(i=1;i<=nver;i++){
                a[i].t_inf=0;
		a[i].estado=0;
        }
	for(i=1;i<=k;i++){
		
		o=0;
		rand();
		rand();
		rand();

		while(o==0){
			b=rand()%(nver+1);
			if(a[b].estado==0){
			a[b].estado=2;
			o=1;
			}
		}
	}
	}
	else{//se op != 1 entao o usuario decide quais serao os individuos infectados
		printf("\nDIGITE QUANTOS INDIVIDUOS DESEJA INFECTAR:");
		scanf("%d",&k);

		for(i=1;i<=nver;i++){
                a[i].t_inf=0;
                a[i].estado=0;
	        }


		for(i=1 ; i <= k; i++){
			printf("Infectado%d: ",i);
			o=0;
			while(o==0){
				scanf("%d",&b);
				if(a[b].estado == 0){
					a[b].estado = 2;
					o=1;
				}
				else{	
					printf("\nINDIVÍDUO JÁ INFECTADO\n");
				}
			}
	}}
}

	


void ins_lis(lista **lista, int a, int b,int incremento){//insere em uma lista até dois elementos
	int c = (*lista)->tamanho;
	(*lista)->v[c] = a;
	(*lista)->v[c+1] = b;
	(*lista)->tamanho = (*lista)->tamanho + incremento;
}


int ins_ares(grafo *M , int orig , int dest){//insere aresta no grafo
	
	if(orig != dest && (*M).M[orig][dest] == 0 ){		
		(*M).M[orig][dest] = 1;
		(*M).M[dest][orig] = 1;
		(*M).A =+1;
		(*M).grau[orig] =+1;
		(*M).grau[dest] =+1;
		return 1;
	}
	else
		return 0;
}	

void zera(grafo *M, int nver){//zera o grafo
	
	int i=0,j=0;
	
	M->A = 0;
	for( i = 1 ; i <= nver ; i++ ){
		for( j = 1 ; j <= nver ; j++){
			M->M[i][j]=0;
		}
		M->grau[i] = 0;

	}
}

void grafo_regular(grafo *M, int nver,int grau){//gera um grafo regular com grau medio proximo do grau dado na funcao

	int i=0,j=1,a,b=0;

	zera(&(*M),nver);
	
	for(i = 1,b=1 ; i<= grau*nver/2 ; i++){
		printf("\n%d\n",i);
		if(b<1000)
			b++;
		else
			b=1;
		a=0;
		j=b;
		while(a == 0){
			if(j<nver)
				j=j+1;
			else 
				j=1;
			
			printf("\n  j: %d \n",j);		
			if( (*M).grau[b] != grau && (*M).grau[j] != grau){
				a=ins_ares(M,b,j);
			}
		}
	}
}

void grafo_aleatorio(grafo *M , int nver,int grau){//gera grafo aleatorio com grau medio proximo de grau dado na funcao

	int i=0,j=0,k=0,a=0;

	srand(time(NULL));
	rand();
	rand();
	rand();

	zera(&(*M),nver);

	for(i=1 ; i<= grau*nver/2 ; i++){
		a=0;
		while(a==0){
			j = rand()%(*M).lista_ver->tamanho;
			k = rand()%(*M).lista_ver->tamanho;
			a = ins_ares(M,k,j);
		}
	}
}
		
void grafo_livrescala(grafo *M, int nver, int grau){//grafo livre de escala com grau medio proximo de grau dado na funcao

	int i = 0 , j = 0 , c = 0,k=0;;
	lista* aux = (lista*) malloc(sizeof(lista));
	aux->v = (int *) malloc((grau*nver)*sizeof(int));
	aux->tamanho = 0;
		
	zera(&(*M),nver);

	srand(time(NULL));
	rand();
	rand();
	rand();

	ins_ares(M,1,2);
	ins_lis(&aux,1,2,2);
	
	for( i = 3; i<= nver ; i++){
		for(k=1;k<=grau/2;k++){
			j=rand()%(aux->tamanho);
			c=aux->v[j];
			ins_ares(M,i,c);
			ins_lis(&(aux),i,c,2);
		}
	}	
}

void grafo_modularizado(grafo* M){//gera grafo modularizado escaneado de arquivo

	FILE *arq;
	int a=0 , b=0;

	arq = fopen("network.txt", "r");

	

	while(!feof(arq)){

		fscanf(arq, "%d %d\n", &a, &b);

		ins_ares(M,a,b);

	}

	fclose(arq);

}

void calcula(grafo* m , int nver , vert *a){

	int b[101],rec[101],c=0,i=0,t=0,j=0,por=0,zero=0,um=0,dois=0,tres=0,def =0;
	
	FILE *arq = fopen("estado_tempo.txt","w+");	
	FILE *arq1 = fopen("situ_tempo.txt","w+");
	
	printf("\nDIGITE A PROBABILIDADE DE INFECCAO NO COTATO COM INDIVÍDUO INFECTADO: ");
	scanf("%d",&c);

	for(i=0;i<=100;i++){

                b[i]=0;//vetor usado para probabilidade de infeccao
        }


	for(i=0;i<c && i<=100;i++){

		b[i]=1;
	}
	
	printf("\nDIGITE A PORCENTAGEM DE RECUPERAÇÃO DO INDIVÍDUO INFECTADO: ");
        scanf("%d",&c);

        for(i=0;i<=100;i++){

                rec[i]=0;//vetor usado probabilidade de recuperacao
        }


        for(i=0;i<c;i++){

                rec[i]=1;
        }

	srand(time(NULL));
	rand();
	rand();

	for(t=1;t<=260;t++){

		srand(time(NULL));
	
		for(i=1;i<=nver;i++){
			if(a[i].estado == 2){
				a[i].t_inf++;
				if(a[i].t_inf >10){//ou morre ou se recupera
					
					def = rand() % 100;
					if(rec[def] == 0)//se nao se recupera-> morte
						a[i].estado = 1;
					else if(rec[def] == 1){// recupera-se -> recuperacao e imunidade
						a[i].estado = 3;	
						a[i].t_inf = 100;
					}
				}
		}}

		srand(time(NULL));
			
		for(i=1;i<=nver;i++){
			for(j=1;j<=nver;j++){
				if(m->M[i][j]==1 && a[i].estado != 1 && a[j].estado == 2 && a[j].t_inf <=10){
					por = rand()%100;	
					if(b[por] == 1){//verificando se os vizinhos sao infectados e probabilidade de ser infectado
							
						a[i].estado=2;
					}
				}	
			}
		}
		
		fprintf(arq,"%d ",t);
		for(i=1;i<=N ;i++){
			fprintf(arq,"%d ",a[i].estado);		

		}	
		fprintf(arq,"\n");
		
		if(t<=260){	
		zero=0;
                um=0;
                dois=0;
		tres=0;

		 for(i=1;i<=nver;i++){
			
			if(a[i].estado == 0)
				zero++;
			else if(a[i].estado == 1)
				um++;
			else if(a[i].estado == 2)
				dois++;
           		else if(a[i].estado == 3)
				tres++;     

        	}

		fprintf(arq1,"%d %d %d %d %d\n",t,zero,um,dois,tres);
	
		}


	}

	



	fclose(arq1);
	fclose(arq);
}
		
void imprime(grafo* m,int nver){
	
	int i,j;
	FILE *saida = fopen("matriz.txt","w+");
	
	for (i=1; i<=nver; i++){
                for(j=1; j <= nver; j++){
                        fprintf(saida,"%d ",m->M[i][j]);
                 }
                fprintf(saida,"\n");
        }
	
	fclose(saida);
}


						
int main(){

	int i=0;
	grafo *m;
	inici_grafo(&m,N);
	vert lver[N+1];
	inici_lver(lver,N,0);//0-> os individuos infectados forem dados pelos usuarios e 1 ->individuos infectados sao escolhidos aleatoriamente
//	grafo_regular(m,N,8);//8->grau medio escolhido assim como as outras topologias
//	grafo_aleatorio(m,N,8);
//	grafo_livrescala(m,N,8);
	grafo_modularizado(m);// grafo disponibilizado

	calcula(m,N,lver);//interação de propagação de infecção

	imprime(m,N);//impressao da matriz de adjacencia final
}


