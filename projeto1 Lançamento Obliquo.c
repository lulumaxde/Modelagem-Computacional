#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
int main(){
	double vy[1001], xy[1001], e[1001];
	double vx[1001],  xx[1001];
	float variacao, m , k ,poin[2],vin ;
	float g = -9.8,teta ;
	int i, j = 1;
    FILE *arq1 = fopen("situ_tempo.txt","w+");



	printf("\n\n-----LEITURA DE DADOS SIMLUCAÇAO %d-----\n\n",j);

	variacao = 0.01;
	printf("Digite valor em 2d para posicao inicial: ");			scanf("%f %f",&poin[1],&poin[2]);
	printf("Digite valor para massa do corpo: ");				scanf("%f",&m );
	printf("Digite valor para constante de atrito: ");			scanf("%f",&k );
	printf("Digite valor para velocidade inicial de lancamento: ");		scanf("%f",&vin);
	printf("Digite valor para ângulo de lançamento: ");			scanf("%f",&teta);


	for(i=0;i<=100;i++){
		vy[i] = 0;
		vx[i] = 0;
		xy[i] = 0;
		xx[i] = 0;
		e[i]  = 0;
	}

    vy[0] = vin*sin(teta*PI/180);
	xy[0] = poin[2];
for(i = 1;i<=1000;i++){

		vy[i] = vy[i-1]+(g-(k/m)*vy[i-1])*variacao;
        xy[i] = xy[i-1] + vy[i-1]*variacao +(g-(k/m)*vy[i-1])*variacao*variacao/2;
		e[i] = ((m*vy[i]*vy[i])/2);
	}





	vx[0] = vin*cos(teta*PI/180);
	xx[0] = poin[1];
for( i = 1 ; i<=1000 ; i++){
        vx[i] = vx[0];
		xx[i] = xx[i-1]+vx[i-1]*variacao;

	printf("\n\n-----IMPRESSAO DE DADOS SIMLUCAÇAO -----\n\n");
    for(i = 0; i<=1000 ; i++){
    fprintf(arq1,"%d %0.2f %0.2f %0.2f %0.2f %0.2f\n",i,vx[i],xx[i],vy[i],xy[i],e[i]);
}

fclose(arq1);
}
