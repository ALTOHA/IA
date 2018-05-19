#include <bits/stdc++.h>
#define pi 3.1415926535897

using namespace std;

int main(){
	bool vez = false, salto = false;
	int i, poblacion, nuevos_individuos, random, j, formula, muta, cruz, max, min, cont = 0, random2, cont2=0, pos, ultimo, veces;
	double x[50] = {0}, y[50] = {0} ,z, mutacion, cruza, fit[50], mut, crossover, sup_x, sup_y, inf_x, inf_y, pobx[50], poby[50], aleatorio, uniform, minimo, valor, promedio, max_promedio = -500000;
	FILE *fp;

	srand (time(NULL));	
	printf("Bienvenido al Algortimo de Estrategias de Evolucion de Aldo T (JEI)\n");
	printf("Seleccione la formula que desea usar\n");
	scanf("%d", &formula);	
	printf("Coloque el rango inferior en X\n");
	scanf("%lf", &inf_x);
	printf("Coloque el rango superior en X\n");
	scanf("%lf", &sup_x);
	printf("Coloque el rango inferior en Y\n");
	scanf("%lf", &inf_y);
	printf("Coloque el rango superior en Y\n");
	scanf("%lf", &sup_y);	
	printf("Coloque el tamano de la poblacion\n");
	scanf("%d", &poblacion);
	printf("Coloque el numero de nuevos individuos\n");
	scanf("%d", &nuevos_individuos);
	printf("Coloque la fraccion de nueva poblacion generada por cruza\n");
	scanf("%lf", &cruza);
	printf("Coloque la fraccion de nueva poblacion generada por mutacion\n");
	scanf("%lf", &mutacion);
	
	fp = fopen("EvolutionStrategies.txt", "w");		
	
	for(i=0; i<poblacion; i++){
		
		aleatorio = ((double) rand() /(RAND_MAX));
		pobx[i] = inf_x + aleatorio *(sup_x - inf_x);
		
		aleatorio = ((double) rand()/(RAND_MAX));
		poby[i] = inf_y + aleatorio * (sup_y - inf_y);
		
		if(formula == 1)
			fit[i] = 21.5 + (pobx[i]*(sin(4*pi*pobx[i])))+(poby[i]*(sin(20*pi*poby[i])));
		else if(formula == 2)
			fit[i] = (1 - pobx[i])*(1 - pobx[i]) * exp (-(pobx[i] * pobx[i]) - (poby[i] + 1)*(poby[i] + 1)) - (pobx[i] - pow(pobx[i], 3)-pow(poby[i], 3))*exp (-(pobx[i] * pobx[i]) - (poby[i]*poby[i]));
		else if(formula == 3)
			fit[i] = pow(16*pobx[i]*(1-pobx[i]) * poby[i]*(1-poby[i])*sin(poblacion*(pi)*pobx[i]) * sin(poblacion*(pi)*poby[i]), 2);	
	}
	
	crossover = cruza * nuevos_individuos;
	cruz = crossover;
	crossover -= cruz;
	
	if(crossover >= .5)
		cruz ++;
	
	veces = 500;
	
	while(veces--){
		promedio = 0;
		
		mut = mutacion * nuevos_individuos;
		muta = mut;
		mut-=muta;
		
		if(mut >=.5)
			muta++;		
		
		for(i=0; i<muta; i++){

			cont=0;
			random = rand()%poblacion;
			valor = inf_x-5;
			
			while(valor < inf_x || valor > sup_x){
				uniform = 0;
				for(j=0; j<12; j++){
					z = ((double) rand() / (RAND_MAX));		
					uniform += z;
				}
				
				uniform-=6;
				
				pobx[poblacion+cont] = uniform +pobx[random];
				valor = pobx[poblacion+cont];			
			}			
			valor = inf_y-5;
			while(valor < inf_y || valor > sup_y){
				uniform = 0;
				for(j = 0; j<12; j++){
					z = ((double) rand() / (RAND_MAX));		
					uniform += z;			
				}
				
				uniform-=6;
				poby[poblacion+cont] = uniform + poby[random];
				valor = poby[poblacion+cont];
			}		
				
			if(formula == 1)
				fit[poblacion+cont] = 21.5 + (pobx[poblacion+cont]*(sin(4*pi*pobx[poblacion+cont])))+(poby[poblacion+cont]*(sin(20*pi*poby[poblacion+cont])));
			else if(formula == 2)
				fit[poblacion+cont] = (1 - pobx[poblacion+cont])*(1 - pobx[poblacion+cont]) * exp (-(pobx[poblacion+cont] * pobx[poblacion+cont]) - (poby[poblacion+cont] + 1)*(poby[poblacion+cont] + 1)) - (pobx[poblacion+cont] - pow(pobx[poblacion+cont], 3)-pow(poby[poblacion+cont], 3))*exp (-(pobx[poblacion+cont] * pobx[poblacion+cont]) - (poby[poblacion+cont]*poby[poblacion+cont]));
			else if(formula == 3)
				fit[poblacion+cont] = pow(16*pobx[poblacion+cont]*(1-pobx[poblacion+cont]) * poby[poblacion+cont]*(1-poby[poblacion+cont])*sin(poblacion*(pi)*pobx[poblacion+cont]) * sin(poblacion*(pi)*poby[poblacion+cont]), 2);
			
			cont++;
		}	
		
		for(i = 0; i<cruz*2; i++){
			random = rand()%poblacion;
			random2 = rand()%poblacion;
			
			pobx[poblacion + cont] = (pobx[random] + pobx[random2])/2;
			poby[poblacion + cont] = (poby[random] + poby[random2])/2;
			
			if(formula == 1)
				fit[poblacion+cont] = 21.5 + (pobx[poblacion+cont]*(sin(4*pi*pobx[poblacion+cont])))+(poby[poblacion+cont]*(sin(20*pi*poby[poblacion+cont])));
			else if(formula == 2)
				fit[poblacion+cont] = (1 - pobx[poblacion+cont])*(1 - pobx[poblacion+cont]) * exp (-(pobx[poblacion+cont] * pobx[poblacion+cont]) - (poby[poblacion+cont] + 1)*(poby[poblacion+cont] + 1)) - (pobx[poblacion+cont] - pow(pobx[poblacion+cont], 3)-pow(poby[poblacion+cont], 3))*exp (-(pobx[poblacion+cont] * pobx[poblacion+cont]) - (poby[poblacion+cont]*poby[poblacion+cont]));
			else if(formula == 3)
				fit[poblacion+cont] = pow(16*pobx[poblacion+cont]*(1-pobx[poblacion+cont]) * poby[poblacion+cont]*(1-poby[poblacion+cont])*sin(poblacion*(pi)*pobx[poblacion+cont]) * sin(poblacion*(pi)*poby[poblacion+cont]), 2);		
			
			cont++;
		}
		cont2 = cont;
		
		while(cont2 --){
			minimo = 5000000;
			
			
			for(i = 0; i<poblacion+cont; i++){
				if(minimo > fit[i] && fit[i] > -1)
					minimo = fit[i], pos = i;
				
				if(fit[i] > 0)
					ultimo = i;
					
			}
			
			pobx[pos] = pobx[ultimo], poby[pos] = poby[ultimo];
			fit[pos] = fit[ultimo];
			
			pobx[ultimo] = poby[ultimo] = fit[ultimo] = -1;			
		}
		
		for(i=0; i<poblacion; i++)
			promedio += fit[i];
		
		promedio/=poblacion;
		
		fprintf(fp, "%lf\n", promedio);
					
		if(max_promedio < promedio){
			max_promedio = promedio, veces = 501;
			if(vez == true)
				vez = false, mut /= 2;
		}
		
		if(veces == 1 && vez == false && salto == false){
			veces = 501;
			vez = true;
			mut*=2;
		}
		
		if(veces == 1 && vez == true && salto == false){
			mut/=4;
			veces = 501;
			vez = false;
			salto = true;
		}
		
	}
	
	fclose(fp);		
	
	return 0;
}
