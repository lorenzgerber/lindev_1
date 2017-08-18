/**
 * resistance.c
 *
 * Library for calculating total resistance
 * from an array of resistances
 *
 * Peter Püschel, 24.10.2016
 *
 */

#include <stdio.h>
#include "libresistance.h"

/* Funktion för att beräkna den totala resistansen för olika kopplade resistanser.
 * Resistanserna kan kopplas parallellt eller i serie.
 *
 * Parametrar
 *
 * count: Antal resistanser
 * conn:  Kopplingstyp. Seriellt eller parallellt kopplade [ P | S ]
 * array: En pekare på en array av komponentvärden som är lika stor som count
 * Biblioteket kraschar inte om en "nollpekare" skickas till funktioen, dvs om array=0.
 *
 * Returvärde:
 * Returvärdet är den resulterande resistansen
 *
 * Värdet 0 returneras om något motstånd är noll vid parallellkoppling, dvs  R1||R2=0, om R1 eller R2 är 0 Ohm.
 * Om argumenten är felaktiga returnerar funktionen -1
 */

float calc_resistance(int count, char conn, float *array)
{
	float result=0;
	int i;

	if(array==0){
		return -1;
	}

	if (conn=='S'){
		/* Den totala resistansen för motstånd som kopplats i serie är summan av deras resistanser. */
		for (i=0;i<count;i++){
			result += array[i];
		}
	}
	else if (conn=='P'){
		/* Resistanser i parallellkoppling:
		   1) Tag 1 delat med varje resistans så att du får ett antal nya tal.
                   2) Addera ihop dessa nya tal så att du får deras summa.
		   3) Tag 1 delat med denna summa så får du totalresistansen. */
		for (i=0;i<count;i++){
			if (array[i] == 0){
				return 0;
			}
			result += 1.0/array[i];
		}
		result = 1.0/result;
	}
	else{
		return -1;
	}

	return result;
}
