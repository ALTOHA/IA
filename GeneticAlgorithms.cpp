#include <bits/stdc++.h>
#define pi 3.1415926535897

using namespace std;

int main(){
	double fitness, threshold_fitness, r, m, bitsx, bitsy, rango_infx=-3, rango_supx=12.1, rango_totalx,fitn=0, rango_infy=4.1, rango_supy=5.8, rango_totaly, formulax, formulay, fit[50000], suma_fitness = 0, fitness_prob[50000], rul = 0, pass, crossover, mut, max_fitness = 0;
	int opcion, n, tamano_bitsx, tamano_bitsy, i, ruleta, j, cont = 1, q=0, decimalx=0, decimaly=0, pot=1, pasan, nueva_poblacion[50000], cross, cros[50000], l = 0, random, num_mut, formula =1, veces, min, max, cont2 = 1, pos, cont3=0;
	char x[500], y[500], hipotesis[50000];
	bool primer = false, mutacion = false;
	string cruza1, cruza2, cruza, cruza3, cruza4;
	FILE *fp, *pf;
	
	srand (time(NULL));
	map <int, string> poblacion; 
	map <int, string> :: iterator it;
	
	//inicializa los arreglos y la cadena
	fill(hipotesis, hipotesis+50000,0);
	fill(x, x+50000, 0);
	fill(y, y+50000, 0);
	fill(nueva_poblacion, nueva_poblacion+50000, 0);
	
	printf("Bienvenido al Algortimo Genetico de Aldo T (JEI)\n");
	printf("Seleccione la formula que desea usar\n");
	scanf("%d", &formula);
	printf("Seleccione el rango inferior de la funcion en X\n");
	scanf("%lf", &rango_infx);
	printf("Seleccione el rango superior de la funcion en X\n");
	scanf("%lf", &rango_supx);
	printf("Selecione el rango inferior de la funcion  en Y\n");
	scanf("%lf", &rango_infy);
	printf("Seleccione el rango superior de la funcion en Y\n");
	scanf("%lf", &rango_supy);
	printf("Seleccione la fraccion de la poblacion a ser remplazada por cruza\n");
	scanf("%lf", &r);
	printf("Seleccione el numero de poblacion\n");
	scanf("%d", &n);
	printf("Seleccione la proporcion de la mutacion\n");
	scanf("%lf", &m);
	fp = fopen("GA_promedio.txt", "w");
	pf = fopen("GA_maximo.txt", "w");	
	
	rango_totalx = abs(rango_supx - rango_infx);
	rango_totaly = abs(rango_supy - rango_infy);
	
	//tamaño de la cadena de la hipotesis
	bitsx = log2(rango_totalx*pow(10, 6) + 1);
	bitsy = log2(rango_totaly *pow(10, 6) +1 );
	
	tamano_bitsx = bitsx;
	
	if(tamano_bitsx != bitsx)
		tamano_bitsx++;
	
	tamano_bitsy = bitsy;
	
	if(tamano_bitsy != bitsy)
		tamano_bitsy++;
		
	//lenar n hipotesis con numeros random
	for(j=1; j<=n; j++){
		q = 0;
		pot = 1;

		for(i=0; i<tamano_bitsx+tamano_bitsy; i++){
			ruleta = rand() % 100;
			
			if(ruleta > 50)
				hipotesis[i] = '1';
				
			else 
				hipotesis[i] = '0';
				
			if(i <= tamano_bitsx-1)
				x[q] = hipotesis[i];
			else
				y[q] = hipotesis[i];
				
			q++;
			
			if(i == (tamano_bitsx)-1)
				q = 0;
		}
		
		//pasar las cadenas binarias a un valor decimal
		for(i=tamano_bitsx-1; i>=0; i--){
			decimalx += (pot*(x[i]-'0'));
			pot*=2;
		}		
		pot = 1;
		
		for(i=tamano_bitsy-1; i>=0; i--){
			decimaly += (pot*(y[i]-'0'));
			pot*=2;
		}
		pot = 1;


		formulax = rango_infx + decimalx*((rango_supx-rango_infx)/(pow(2, (tamano_bitsx))-1));
		formulay = rango_infy + decimaly*((rango_supy-rango_infy)/(pow(2, (tamano_bitsy))-1));		
		
		//sacar el fitness de cada valor en la formula deseada
		if(formula == 1)
			fit[j] = 21.5 + (formulax*(sin(4*pi*formulax)))+(formulay*(sin(20*pi*formulay)));
		else if(formula == 2)
			fit[j] = (1 - formulax)*(1 - formulax) * exp (-(formulax * formulax) - (formulay + 1)*(formulay + 1)) - (formulax - pow(formulax, 3)-pow(formulay, 3))*exp (-(formulax * formulax) - (formulay*formulay));
		else if(formula == 3)
			fit[j] = pow(16*formulax*(1-formulax) * formulay*(1-formulay)*sin(n*(pi)*formulax) * sin(n*(pi)*formulay), 2);
		
		suma_fitness += fit[j];
		if(max_fitness < fit[j]){
			max_fitness = fit[j];
		}
		
		decimalx=0, decimaly=0;
		poblacion[cont] = hipotesis;
		cont++;
		
	}
		
	printf("\n\n\n");*/
	min = 1, max = n;
	
	while(cont3 <= 500){
		cont3++;
		cont = max+1;
		fill(nueva_poblacion, nueva_poblacion+50000, 0);
		fill(fitness_prob, fitness_prob+50000, 0);
		fill(cros, cros+50000, 0);
		l = rul = fitn = 0;
		
		for(i = min; i<=max; i++){
			fitness_prob[i] = fit[i] / suma_fitness;

		}

		fill(fit, fit+50000, 0);
	
		//Se usa la formula para saber cuantos pasan directamente usando la ruleta	
		pass = n*(1-r);
		pasan = pass;
		
		if(pasan != pass)
			pasan++;
		
		//funcion para saber la cantidad de pares de hipotesis a cruzar
		
		crossover = (r*n)/2;
		cross = crossover;
		
		if(crossover != cross)
			cross++;
		
		cross*=2;
		pos = min;
		//funcion para saber cuantas hipotesis pasan directo
		while(pasan--){
			rul = static_cast<float> (rand() / static_cast <float> (RAND_MAX));
			if(rul > 1)
				rul--;
				
			for(i=pos; i<=max; i++){
				fitn+=fitness_prob[i];
				if(rul <= fitn){
					nueva_poblacion[i]++;
					pos = i;					
					i = max+1;
					}
				if(i == max && rul > fitn)
					i = min-1;				
			}
			fitn = 0;
			
		}
		
		//funcion para seleccionar las hipotesis a la cruza
		while(cross--){
			rul = static_cast<float> (rand() / static_cast <float> (RAND_MAX));		
				if(rul > 1)
					rul--;			
			fitn = 0;
			for(i=pos; i<=max; i++){
				

				fitn+=fitness_prob[i];				
				if(rul <=fitn){
					cros[l] = i;
					l++; 
					pos = i;
					i = max + 1;
				}
				if(i == max && rul > fitn)
					i = min-1;
			}
				
			if(l % 2 == 0){
					
				sort(cros, cros+l);
					
				ruleta += rand() % (tamano_bitsx+tamano_bitsy-1);
				
				if(ruleta <= 1)
					ruleta = 2;
					
				if(ruleta >= tamano_bitsx+tamano_bitsy)
					ruleta = tamano_bitsx+tamano_bitsy; 
				
				for(it = poblacion.begin(); it != poblacion.end(); it++){

					if(it->first == cros[0]){
						cruza1 = it->second.substr(0, ruleta-1);
						cruza3 = it->second.substr(ruleta-1, tamano_bitsx+tamano_bitsy-1);
					}
					
					if(it->first == cros[1]){
						cruza2 = it->second.substr(ruleta-1, tamano_bitsx+tamano_bitsy-1);
						cruza4 = it->second.substr(0, ruleta-1);					
					}
					
				}
				cruza = cruza1+cruza2;	
				
				poblacion[cont] = cruza;	
				cruza.clear();
				cont++;
				
				cruza = cruza3+cruza4;
				poblacion[cont] = cruza;	
				l = 0, cont++;
				
				cruza1.clear(), cruza2.clear();
				cruza3.clear(), cruza4.clear();
				}
				
		}
		//funcion para eliminar las hipotesis que no fueron seleccionadas
		for(i=min; i<=max; i++){
			if(nueva_poblacion[i] == 0){
				poblacion.erase(i);
			}
			//funcion por si llega salen dos hipotesis iguales en la ruleta
			if(nueva_poblacion[i] > 1){
				while(nueva_poblacion[i] != 1){
					cont++;
					
					for(it = poblacion.begin(); it!= poblacion.end(); it++){
						
						if(it->first == i)
							poblacion[cont] = it->second;
						
					}
					
					nueva_poblacion[i]--;
				}
			}
		}
		//impresion de las nuevas hipotesis
		mut = m * n;
		num_mut = mut;
		
		if(num_mut != mut)
			num_mut++;
			
		while(num_mut--){
		
			do{
				random = rand() % cont;
			}while(poblacion.count(random) != 1);
			
			ruleta = rand() % (tamano_bitsx+tamano_bitsy-1); 
			
			for(it = poblacion.begin(); it != poblacion.end(); it++){
				if(it->first == random){
					for(i=ruleta+1; i<tamano_bitsx+tamano_bitsy-1; i++){
						(it->second[i] == '0') ? it->second[i] = '1' : it->second[i] = '0', i = tamano_bitsx+tamano_bitsy;
					}
				}
			}
			
		}
		suma_fitness/=n;

		fprintf(fp, "%lf\n", suma_fitness);	

		cont2++;
		suma_fitness = max = 0;
		
		for(it = poblacion.begin(); it != poblacion.end(); it++){
			if(it == poblacion.begin())
				min = it->first;
			if(it->first > max)
				max = it->first;
			
			pot = 1;
			decimalx = decimaly = 0;
			
			for(i=tamano_bitsx+tamano_bitsy-1; i>=tamano_bitsx; i--){
				decimaly += (pot*(it->second[i] -'0'));
				pot*=2;

			}
			pot = 1;
			
			for(i=tamano_bitsx-1; i>=0; i--){
				decimalx += (pot*(it->second[i] -'0'));
				pot*=2;
			}
			pot = 1;
			
			formulax = rango_infx + decimalx*((rango_supx-rango_infx)/(pow(2, tamano_bitsx)-1));
			formulay = rango_infy + decimaly*((rango_supy-rango_infy)/(pow(2, tamano_bitsy)-1));	
			
			
			//sacar el fitness de cada valor en la formula deseada
			if(formula == 1)
				fit[it->first] = 21.5 + (formulax*(sin(4*pi*formulax)))+(formulay*(sin(20*pi*formulay)));
			else if(formula == 2)
				fit[it->first] = (1 - formulax)*(1 - formulax) * exp(-(formulax * formulax) - ((formulay + 1)*(formulay + 1))) - (formulax - pow(formulax, 3)-pow(formulay, 3))*exp (-(formulax * formulax) - (formulay*formulay));
			else if(formula == 3)
				fit[it->first] = pow(16*formulax*(1-formulax) * formulay * (1-formulay) * sin(n*pi*formulax) * sin(n*pi*formulay), 2);
			
			if(max_fitness < fit[it->first]){
				max_fitness = fit[it->first];
				cont3 = 0;
				if(mutacion == true)
					m/=2, mutacion = false;
			}			
			else if(cont3 == 500 && mutacion == false){
				m*=2;
				mutacion = true;
				cont3 = 0;
			}
			else if(cont3 == 500 && mutacion == true){
				cont3 = 1000;
			}
			suma_fitness += fit[it->first];
			decimalx=0, decimaly=0;
		}
			fprintf(pf, "%lf\n", max_fitness);			
	}
			fclose(fp);	
			fclose(pf);	
	return 0;
}
