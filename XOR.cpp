#include <bits/stdc++.h>

using namespace std;

int main(){
	map <string, double> redes;
	map <string, double> :: iterator it;
	
	bool cumple = false;
	double pesos[100000], aleatorio, formula = 0, aprendizaje, peso, sigma[1000] = {0}, error, resul[4];
	char valor1[1000], valor2[1000], red[10000], compara[10000];
	int entrada, centro, salida, i, j, l=0, x0 = -1, x1[10], x2[10], t[10], entra[100000], cen[100000], sal[100000], q, pos, cont = 0;
	
	printf("Coloque la cantidad de redes de entrada\n");
	scanf("%d", &entrada);	
	printf("Coloque la cantidad de unidades en la capa oculta\n");
	scanf("%d", &centro);
	printf("Coloque la cantidad de redes de salida\n");
	scanf("%d", &salida);
	printf("Coloque el valor de aprendizaje\n");
	scanf("%lf", &aprendizaje);
	printf("Coloque el valor de error\n");
	scanf("%lf", &error);
	printf("Coloque los valores a aprender\n");
	
	for(i=0; i<4; i++)
		scanf("%d %d %d", &x1[i], &x2[i], &t[i]);
		
	for(i=0; i<=entrada; i++)
		entra[i] = i;
	
	
	for(i=entrada+1; i<=entrada+centro; i++){
		cen[l] = i;
		l++; 
	}
	l=0;
	
	for(i=entrada+centro+1; i<= entrada+centro+salida; i++){
		sal[l] = i;
		l++;
	}
	l=0;
	
	for(i=1; i<=entrada; i++){
		for(j=entrada+1; j<=centro+entrada; j++){
			
			fill(red, red+10000, 0);
			sprintf(valor1, "%d", i);
			sprintf(valor2, "%d", j);
			strcat(red, valor1);
			strcat(red, valor2);
			aleatorio = ((double) rand() / (RAND_MAX));
			redes[red] = aleatorio;
		}
	}
	
	for(i=0; i<=0; i++){
		for(j=entrada+1; j<=centro+entrada+salida; j++){
			fill(red, red+10000, 0);
			sprintf(valor1, "%d", i);
			sprintf(valor2, "%d", j);
			strcat(red, valor1);
			strcat(red, valor2);
			aleatorio = ((double) rand() / (RAND_MAX));
			redes[red] = aleatorio;
		}
	}
	
	for(i=entrada+1; i<centro+entrada+salida; i++){
		for(j=centro+entrada+1; j<=centro+entrada+salida; j++){
			
			fill(red, red+10000, 0);
			sprintf(valor1, "%d", i);
			sprintf(valor2, "%d", j);
			strcat(red, valor1);
			strcat(red, valor2);
			aleatorio = ((double) rand() / (RAND_MAX));
			redes[red] = aleatorio;			
		}
	}

	while(cumple == false){
		cont = 0;
		for(i=0; i<4; i++){
			
			for(j=0; j<centro; j++){
				formula = 0;
				for(q=0; q<=entrada; q++){
					fill(red, red+10000, 0);
					
					sprintf(valor1, "%d", cen[j]);
					sprintf(valor2, "%d", entra[q]);
					strcat(red, valor2);
					strcat(red, valor1);				
	
					if(q == 0)
						formula += x0 * (redes.at(red));
					
					if(q == 1)
						formula += x1[i] * (redes.at(red));
					
					if(q == 2)
						formula += x2[i] * redes.at(red);
					
				}
				pesos[j] = (1/(1+exp(-formula)));
				
				if(j == centro-1){
					l = 0;
					for(j=0; j<salida; j++){
						fill(red, red+10000, 0);
						formula = 0;
						l++;
						sprintf(valor1, "%d", 0);
						sprintf(valor2, "%d", entrada+centro+l);
						strcat(red, valor1);
						strcat(red, valor2);						
						formula += x0 * (redes.at(red));

						for(q=0; q<centro; q++){
							
							fill(red, red+10000, 0);
							sprintf(valor1, "%d", sal[j]);
							sprintf(valor2, "%d", cen[q]);
							strcat(red, valor2);
							strcat(red, valor1);
							formula += pesos[q] * (redes.at(red));
								
						}
					
					pos = centro;
					pesos[pos] = (1/(1+exp(-formula)));
					
					if(abs(pesos[pos] - t[i]) <= error)
						cont++, resul[i] = pesos[pos];
					else
						cont = 0;
												
				
					sigma[pos] = pesos[pos]*(1-pesos[pos])*(t[i] - pesos[pos]);
					pos++;
					}
				j = centro;					
				}
			}
			if(cont == 4){
				cumple = true;
				for(i=0; i<4; i++){
					printf("%d %d %d\n", x1[i], x2[i], t[i]);
					printf("%lf\n", resul[i]);
				}
			
			}			
			
			for(j=0; j<centro; j++){
				fill(red, red+10000,0);
				sprintf(valor1, "%d", sal[0]);
				sprintf(valor2, "%d", cen[j]);
				strcat(red, valor2);
				strcat(red, valor1);
				
				//printf("%s\n", red);
				sigma[j] = pesos[j]*(1-pesos[j]) * (redes.at(red)) * sigma[pos-1];
			}
			
			
			for(j=0; j<centro; j++){
				for(q=0; q<3; q++){
				
					fill(red, red+10000,0);				
					
					if(q == 0){
						sprintf(valor1, "%d", 0);
						sprintf(valor2, "%d", cen[j]);
						strcat(red, valor1);
						strcat(red, valor2);
						redes.at(red) = redes.at(red) + aprendizaje*sigma[j] * x0;
						
						printf("%s %lf\n", red, redes.at(red));
					}
				
					if(q == 1){
						sprintf(valor1, "%d", 1);
						sprintf(valor2, "%d", cen[j]);
						strcat(red, valor1);
						strcat(red, valor2);
						redes.at(red) = redes.at(red) + aprendizaje*sigma[j] * x1[i];	
						
						printf("%s %lf\n", red, redes.at(red));									
					}
				
					if(q == 2){
						sprintf(valor1, "%d", 2);
						sprintf(valor2, "%d", cen[j]);
						strcat(red, valor1);
						strcat(red, valor2);
						redes.at(red) = redes.at(red) + aprendizaje*sigma[j] * x2[i];
						
						printf("%s %lf\n", red, redes.at(red));					
					}
				
				}
				printf("\n");
				if(centro-1 == j){
					for(j=0; j<salida; j++){

						//j = 0;
						for(q=0; q<3; q++){
							fill(red, red+10000, 0);
							if(q == 0){
								sprintf(valor1, "%d", 0);
								sprintf(valor2, "%d", sal[j]);
								strcat(red, valor1);
								strcat(red, valor2);
								redes.at(red) = redes.at(red) + aprendizaje*sigma[pos-1] * x0;
								printf("%s %lf\n", red, redes.at(red));						
							}
							if(q == 1){
								sprintf(valor1, "%d", 3);
								sprintf(valor2, "%d", sal[j]);
								strcat(red, valor1);
								strcat(red, valor2);
								redes.at(red) = redes.at(red) + aprendizaje*sigma[pos-1] * pesos[q-1];
								
								printf("%s %lf\n", red, redes.at(red));											
							}
							if(q == 2){
								sprintf(valor1, "%d", 4);
								sprintf(valor2, "%d", sal[j]);
								strcat(red, valor1);
								strcat(red, valor2);
								redes.at(red) = redes.at(red) + aprendizaje*sigma[pos-1] * pesos[q-1];
								
								printf("%s %lf\n", red, redes.at(red));						
							}
						}			
					}
					j = centro;
				}
				
			}
			
		}
		
	}
	return 0;
}
