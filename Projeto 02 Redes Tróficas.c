#include <stdlib.h>
#include <stdio.h>
#define e 0.01


int main (){

	int Simulacoes,op;
	printf("Quantidade de Simulacoes \n");
	scanf("%d", &Simulacoes);
	printf("----------------------------------\n");
	float Grama[Simulacoes], Impala[Simulacoes], Gnus[Simulacoes], Hiena[Simulacoes], Leao[Simulacoes];
    printf("Valores iniciais \n\n");
	printf("Quantidade de Grama Inicial\n");
	scanf("%f", &(Grama[0]));
	printf("Quantidade Inicial de Impalas\n");
	scanf("%f", &(Impala[0]));
	printf("Quantidade Inicial de Gnus\n");
	scanf("%f", &(Gnus[0]));
	printf("Quantidade Inicial de Hienas\n");
	scanf("%f", &(Hiena[0]));
	printf("Quantidade Inicial de Leoes\n");
	scanf("%f", &(Leao[0]));
	printf("Opcoes de desastres \n");
    printf("Opcao 1 simulacao normal \n");
    printf("Opcao 2 Queimada \n");
    printf("Opcao 3 Temporada de Caca \n");
    printf("Opcao 4 Extincao de especie \n");
    scanf("%d", &op);

	printf("------------------------------------\n");
    int i;

    if(op == 1){
	for(i = 1; i < Simulacoes; i++){
		Grama[i] = Grama[i-1]*((103.93*(1-((Grama[i-1])/1300)) - 0.02*Impala[i-1] - 0.035*Gnus[i-1])*e) + Grama[i-1]; // Vegetação
        Impala[i] = Impala[i-1]*(0.025*Grama[i-1] - 0.005*Hiena[i-1] - 0.008*Leao[i-1] - 3.2)*e + Impala[i-1]; // Herbibovo 1
		Gnus[i] = Gnus[i-1]*(0.02*Grama[i-1] - 0.009*Hiena[i-1] - 0.005*Leao[i-1] - 2.9)*e + Gnus[i-1]; // Herbibovo 2
		Hiena[i] = Hiena[i-1]*(0.02*Impala[i-1] + 0.025*Gnus[i-1] - 22.2)*e + Hiena[i-1]; // Carnivoro 1
		Leao[i] = Leao[i-1]*(0.025*Impala[i-1] + 0.017*Gnus[i-1] - 22.8)*e + Leao[i-1]; // Carnivoro 2


        }
    }


    if (op == 2){
        for(i = 1; i < Simulacoes; i++){
		Grama[i] = Grama[i-1]*((103.93*(1-((Grama[i-1])/1300)) - 0.02*Impala[i-1] - 0.035*Gnus[i-1])*e) + Grama[i-1]; // Vegetação
		 if(i == 150){
         Grama[i] *= 0.1;
         }         // Queimada repentina
		Impala[i] = Impala[i-1]*(0.025*Grama[i-1] - 0.005*Hiena[i-1] - 0.008*Leao[i-1] - 3.2)*e + Impala[i-1]; // Herbibovo 1
		Gnus[i] = Gnus[i-1]*(0.02*Grama[i-1] - 0.009*Hiena[i-1] - 0.005*Leao[i-1] - 2.9)*e + Gnus[i-1]; // Herbibovo 2
		Hiena[i] = Hiena[i-1]*(0.02*Impala[i-1] + 0.025*Gnus[i-1] - 22.2)*e + Hiena[i-1]; // Carnivoro 1
		Leao[i] = Leao[i-1]*(0.025*Impala[i-1] + 0.017*Gnus[i-1] - 22.8)*e + Leao[i-1]; // Carnivoro 2
    }
    }

    if (op == 3){
            for(i = 1; i < Simulacoes; i++){
		Grama[i] = Grama[i-1]*((103.93*(1-((Grama[i-1])/1300)) - 0.02*Impala[i-1] - 0.035*Gnus[i-1])*e) + Grama[i-1]; // Vegetação

		Impala[i] = Impala[i-1]*(0.025*Grama[i-1] - 0.005*Hiena[i-1] - 0.008*Leao[i-1] - 3.2)*e + Impala[i-1]; // Herbibovo 1
		Gnus[i] = Gnus[i-1]*(0.02*Grama[i-1] - 0.009*Hiena[i-1] - 0.005*Leao[i-1] - 2.9)*e + Gnus[i-1]; // Herbibovo 2
		Hiena[i] = Hiena[i-1]*(0.02*Impala[i-1] + 0.025*Gnus[i-1] - 22.2)*e + Hiena[i-1]; // Carnivoro 1
		Leao[i] = Leao[i-1]*(0.025*Impala[i-1] + 0.017*Gnus[i-1] - 22.8)*e + Leao[i-1]; // Carnivoro 2

            if(i == 200){
            Impala[i] *= 0.9;
            Gnus[i] *=  0.8;
            Hiena[i] *= 0.5;
            Leao[i] *= 0.2;
            }  //Temporada de caca
        }

    }
    if (op == 4){

               for(i = 1; i < Simulacoes; i++){
		Grama[i] = Grama[i-1]*((103.93*(1-((Grama[i-1])/1300)) - 0.02*Impala[i-1] - 0.035*Gnus[i-1])*e) + Grama[i-1]; // Vegetação

		Impala[i] = Impala[i-1]*(0.025*Grama[i-1] - 0.005*Hiena[i-1] - 0.008*Leao[i-1] - 3.2)*e + Impala[i-1]; // Herbibovo 1
		Gnus[i] = Gnus[i-1]*(0.02*Grama[i-1] - 0.009*Hiena[i-1] - 0.005*Leao[i-1] - 2.9)*e + Gnus[i-1]; // Herbibovo 2
		Hiena[i] = Hiena[i-1]*(0.02*Impala[i-1] + 0.025*Gnus[i-1] - 22.2)*e + Hiena[i-1]; // Carnivoro 1
		Leao[i] = Leao[i-1]*(0.025*Impala[i-1] + 0.017*Gnus[i-1] - 22.8)*e + Leao[i-1]; // Carnivoro 2

            if(i == 100){
            Impala[i] *= 0;

            }  //Extinção de Impalas
        }
    }

    for(i=0;i<Simulacoes;i++){
	printf("%d       %.2f      %.2f      %.2f      %.2f     %.2f", i, Grama[i], Impala[i], Gnus[i], Hiena[i], Leao[i]);
	printf("\n");
	}

}
