//Bibliotek 3, libcomponent.so, Burleigh HT16
#include <stdio.h>
#include <math.h>
#include "libcomponent.h"

//declarations
int countplaces(float resid);
float* calcE12(float remaining);

//main function, accepts argument (resistor value) from Lib1
//************************************************************
int e_resistance (float orig_resistance, float *res_array){
	//declare function vars
	int resisnum = 0;  //counter for calcE12 while loop
	float *resisandresid;  //returned array with best resistor and the resid
	int resistorsneeded = 0;  //actual resistors needed- the output

	//temp print function
	//printf("\nE12 resistors (first three values in *res_array) that best match the orig_resistance value of %f: \n", orig_resistance);

	//while loop to find closest matching set of resistors for a given input resistor value
	while (resisnum < 3){  //only want three values returned (from 0-x)
		//calc closest e12 resistor and return resid
		resisandresid = calcE12(orig_resistance);

		//process resisandresid results-save best resis val to res_array, resend resid (if >3 runs)
		res_array[resisnum] = resisandresid[0];
		orig_resistance = resisandresid[1];

		//continue (to 3 runs)
		resisnum = resisnum + 1;
	}

	//count up the non-zero resistors in res_array
	int counter3;
	for(counter3 = 0; counter3 < 3; counter3++){
		if (res_array[counter3] != 0){
			resistorsneeded += 1;
		}
	}
	//send the number of resistors needed back to main
	return resistorsneeded;
}

//subfunctions
//**************
//find closest e12 resistor, return this and the remaining resid (returned as a 2-member array)
float* calcE12(float remaining){
	//define e12 series
	double e12[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

	//count places for e12 multiplier
	int places;
	places = countplaces(remaining);

	//convert places value into the e12 multiplier
	int i;
	int Power;
	Power = pow(10, places);

	//adjust e12 series according to multiplier
	for (i = 0; i < 12; i++){
		e12[i] = e12[i] * Power;
	}
	//identify best matching e12 resistor
	//declare vars
	int e12index;
	float best;
	float resid;
	static float resisandresid[2];
	//find equal to or next lowest e12 resistor
	for (e12index = 11; e12index > -1; e12index--){
		if (remaining < 1){
			resisandresid[0] = 0;
			resisandresid[1] = 0;
			//e12index == -1;
			return resisandresid;
		}
		if (e12[e12index] <= remaining){
			best = e12[e12index];
			resid = remaining - best;
			resisandresid[0] = best;
			resisandresid[1] = resid;
			//e12index == -1;
			return resisandresid;
		}
	}
	return 0;
}

//count places of resistor value for calculating the e12 multiplier
int countplaces(float resid){
	if (resid <= 0){
		int count = 0;
		return count;
	}
	int count = 0;
	int rounded;
	rounded =(int)(resid + 0.5);
	while(rounded != 0){
        rounded /= 10;
        ++count;
    }
	count = count -1; //adj multiplier so ex. 400 = a count of 2 -> multiplier of 100
	return count;
}
