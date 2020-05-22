#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pixelThreshold(float *r, float *g, float *b);

int main() {
	float image[4][4][3];
	int x, y;

	// Don't change this srand() line!
	srand(0);

	for(y = 0; y < 4; y++) {
		for(x = 0; x < 4; x++) {
			image[x][y][0] = (float)rand()/(float)RAND_MAX;
			image[x][y][1] = (float)rand()/(float)RAND_MAX;
			image[x][y][2] = (float)rand()/(float)RAND_MAX;
		}
	}
	// ----------------------------------------
	// Write your code below this comment block
	// ----------------------------------------

	//Black & White converter
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            //Calls pixelThreshold function
            pixelThreshold(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
        }
    }

    //Print results/write results to file
    FILE *output;
    output = fopen("output.txt", "w"); //Opens file for output
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 4; x++) {
            printf("%d %d: %f %f %f\n", x, y, image[x][y][0], image[x][y][1], image[x][y][2]);
            fprintf(output, "%d %d: %f %f %f\n", x, y, image[x][y][0], image[x][y][1], image[x][y][2]);
        }
    }
    int fclose(FILE *output); //Closes file

	return 0;
}

void pixelThreshold(float *r, float *g, float *b) {
    if (*r > 0.5) {
        //Set pixel to white
        *r = 1.0;
        *g = 1.0;
        *b = 1.0;
    } else {
        //Set pixel to black
        *r = 0.0;
        *g = 0.0;
        *b = 0.0;
    }
}
