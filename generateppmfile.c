#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printUsage(char *argv[]) {
	printf("Usage %s [options]\n", argv[0]);
	printf("Options:\n");
	printf("  -w, --width        Sets the width of the ppm file\n");
	printf("  -t, --height       Sets the height of the ppm file\n");
	return 1;
}

int main(int argc, char *argv[]) {
	// Declare height and width variables for the things
	int height;
	int width;

	// Get arguments for width and height
	if (argc < 3) {
		printUsage(argv);
	}

	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--height") == 0) {
			if (i + 1 < argc && strcmp(argv[i + 1], "-w") != 0 && strcmp(argv[i + 1], "--width") != 0) {
				height = atoi(argv[i + 1]);
			} else {
				printf("Error, height argument requires a valid integer value after it");
				return 1;
			}
		}

		if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--width") == 0) {
			if (i + 1 < argc && strcmp(argv[i + 1], "-t") != 0 && strcmp(argv[i + 1], "--height") != 0) {
				width = atoi(argv[i + 1]);
			} else {
				printf("Error, width argument requires a valid integer value after it");
				return 1;
			}
		}
		if (strcmp(argv[i], "-h") == 0) {
				printUsage(argv);
		}
		
		
	}	


	// Making the file
	const char *filename = "output.ppm";
	FILE *fyle = fopen(filename, "w");


	fprintf(fyle, "P3\n");
	fprintf(fyle, "%d %d\n", width, height);
	fprintf(fyle, "255\n");


	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			fprintf(fyle, "%d %d %d ", rand()%255, rand()%255, rand()%255);
		}
		fprintf(fyle, "\n");
	}

}
