/**
 * The main class of Electrotest
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libresistance/resistance.h"
#include "../libpower/power.h"


/**
 *  The main function
 *  @param argc number of arguments
 *  @param pointer to char array with the actual arguments
 */
int main(int argc, char **argv)
{
	float* resistances;  // Pekare till array med värden
	float inputvalue;
	float volt=0;
	float power;
	char buf[100];
	int count=0;
	float resistance;
	char method;
	int loop;

	/* Spänning */
	printf("Ange spänningskälla i V: ");
	if (fgets(buf, sizeof(buf), stdin) != NULL){
		volt = atof(buf);
	}

	/* Kopplingstyp */
	do {
		printf("Ange koppling [S|P]: ");
		if (fgets(buf, sizeof(buf), stdin) != NULL){
			method = buf[0];
		}
	}while(method!='S' && method!='P');

	/* Antal komponenter */
	do {
		printf("Antal komponenter: ");
		if (fgets(buf, sizeof(buf), stdin) != NULL){
			count = atoi(buf);
		}
	}while(count<=0);

	/* Reservera plats för komponenterna */
	resistances = malloc(sizeof(int)*count);

	/* Läs in komponenterna */
	for (loop=0 ; loop<count ; loop++){
		printf("Komponent %d i ohm: ", loop+1);
  		if (fgets(buf, sizeof(buf), stdin) != NULL){
    			inputvalue = atof(buf);
			if (inputvalue==0){
				count = loop;
				printf("Avbryter inmatningen. %d resistanser angivna.\n", count);
				break;
			}
			resistances[loop] = inputvalue;
 	 	}
	}

	if (count==0){
		fprintf(stderr, "Inga resistanser angivna. Avslutar!\n");
		goto error;
	}

	/* Gör beräkningar */
	resistance = calc_resistance(count, method, resistances);
	if (resistance == -1){
		fprintf(stderr, "Felaktigt indata!\n");
		goto error;
	}
	power = calc_power_r(volt, resistance);

	/* Skriv ut resultaten */
	printf("Ersättningsresistans:\n %.1f ohm\n", resistance);
	printf("Effekt:\n %.2f W\n", power);

	goto cleanup;

cleanup:
	free(resistances);
	exit(0);

error:
	free(resistances);
	exit(EXIT_FAILURE);

}
