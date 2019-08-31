#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500
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

typedef struct neur{

	float I;
	float Si;
	float X;
	float Y;
} neuro;

void ins_lis(lista **lista, int a, int b,int incremento);

void aloca_vet(int **v,int tam){

	int i=0;

	(*v) = (int *) malloc((tam+1)* sizeof(int));

	for(i=0 ; i<= tam ; i++){
		(*v)[i] = 0;
	}
}

void aloca_mat(int ***a, int nver){

	int i=0,j=0;

	(*a) = (int **) malloc( nver*sizeof(int *));

	for( i=0 ; i<= nver ; i++){

		(*a)[i] = (int *) malloc( nver * sizeof(int));
		for( j =0 ; j<= nver ; j++){
			(*a)[i][j] = 0;
		}
	}
}

void inici_grafo( grafo ** M, int nvert){

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

void inici_neu( neuro **a,int x, int y,int nneu){

	float I;
	int j=0,k=0,b=0;

	srand(time(NULL));
	rand();
	rand();
	rand();

	(*a) = (neuro *) malloc( (nneu+1)*sizeof(neuro));

	for(j=1 ; j<= nneu ; j++){
		(*a)[j].I = 0;
		(*a)[j].X = 0;
		(*a)[j].Y = 0;
		(*a)[j].Si = 0;
	}

}


void ins_lis(lista **lista, int a, int b,int incremento){
	int c = (*lista)->tamanho;
	(*lista)->v[c] = a;
	(*lista)->v[c+1] = b;
	(*lista)->tamanho = (*lista)->tamanho + incremento;
}

int ins_ares(grafo *M , int orig , int dest){

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

void zera(grafo *M, int nver){

	int i=0,j=0;

	M->A = 0;
	for( i = 1 ; i <= nver ; i++ ){
		for( j = 1 ; j <= nver ; j++){
			M->M[i][j]=0;
		}
		M->grau[i] = 0;

	}
}

void grafo_regular(grafo *M, int nver){

	int i=0,j=1,a;

	zera(&(*M),nver);

	for(i = 1 ; i<= nver ; i++){

		a=0;
		j=i;
		while(a == 0){
			if(i!=nver)
				j=j+1;
			else
				j=1;

			if( (*M).grau[i] != 2 && (*M).grau[j] != 2){
				a=ins_ares(M,i,j);
			}
		}
	}
}

void grafo_aleatorio(grafo *M , int nver){

	int i=0,j=0,k=0,a=0;

	srand(time(NULL));
	rand();
	rand();
	rand();

	zera(&(*M),nver);

	for(i=1 ; i<= nver ; i++){
		a=0;
		while(a==0){

			j = rand()%(*M).lista_ver->tamanho;
			k = rand()%(*M).lista_ver->tamanho;
			a = ins_ares(M,k,j);

	}
}
}
void grafo_livrescala(grafo *M, int nver, int grau){

	int i = 0 , j = 0 , c = 0;
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

		j=rand()%(aux->tamanho);
		c=aux->v[j];
		ins_ares(M,i,c);
		ins_lis(&(aux),i,c,2);

		j=rand()%(aux->tamanho);
                c=aux->v[j];
                ins_ares(M,i,c);
                ins_lis(&(aux),i,c,2);



	}
}

void imprime(grafo* m){

	int i,j;
	FILE *saida = fopen("lala.txt","w+");

	for (i=1; i<= 500; i++){
                for(j=1; j <= 500; j++){
                        fprintf(saida,"%d ",m->M[i][j]);
                 }
                fprintf(saida,"\n");
        }

	fclose(saida);
}

void calcula(neuro **A, grafo *B,int nneu,int k){

	int j=0,a=0,b=0,c=0,i=0,d=0;
	float t=0, w_ij =0.5 , theta = 0.5 , alpha = 6.0 , epilson = 0.02 , beta = 0.1;
	float delta_t=0.01;
	float delta_x=0,delta_y=0;
	FILE* saida;
	if(k==0 ){
	saida = fopen("todos_ativos.txt","w+");
	}
	else if(k==100 ){
	saida = fopen("100_inativos.txt","w+");
	}
	else if(k==250 ){
	saida = fopen("250_inativos.txt","w+");
	}

	inici_neu(&(*A),0,0,nneu);

	for(i=1;i<=500;i++){
		(*A)[i].I=0.200;
	}


	for(i=1;i<=k;i++){
                (*A)[i].I = 0.02 * (-1);
        }

	for(t=0 ; t<=5000 ; t+=delta_t){


		for(a=1 ; a<= nneu ; a++){

			(*A)[a].Si=0;

			for(b=1;b<=nneu;b++){
				if((((*A)[b].X)-theta)>=0 &&  (B->M[a][b])==1){
					(*A)[a].Si+=w_ij;
				}
			}
		}

		for(i=1;i<=nneu;i++){

			delta_x =( 3.0*((*A)[i].X) - pow(((*A)[i].X),3.0) +2.0 - ((*A)[i].Y) + ((*A)[i].Si) + ((*A)[i].I))*delta_t;
			delta_y =( epilson*(alpha*(1.0+tanh(((*A)[i].X)/beta))-((*A)[i].Y)))*delta_t;

			(*A)[i].X += delta_x;
			(*A)[i].Y += delta_y;

		}

		for(j=1;j<=nneu;j++){
			(*A)[j].X+=j/10;
	}

		if(c%100 == 0){

				fprintf(saida," %f  ",t);
				for(j=1;j<=nneu;j+=50){
					fprintf(saida,"%f ",(*A)[j].X);
				}

				fprintf(saida,"\n");
		}

		c++;

		for(j=1;j<=nneu;j++){
			(*A)[j].X-=j/10;
		}
	}
}


int main(){

	grafo *m;
	neuro *ln;
	inici_grafo(&m,N);
//	grafo_regular(m,N);
	grafo_aleatorio(m,N);
//	grafo_livrescala(m,N,4);
//	calcula(&ln, m,N,0);
	calcula(&ln, &(*m),N,100);
//	calcula(&ln, &(*m),N,250);
    imprime(m);
}
