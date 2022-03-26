
#include <stdio.h>

#define SIDE 80

int main() {
	int array[SIDE][SIDE];
	int dists[SIDE][SIDE];
	int visit[SIDE][SIDE];
	int i, leastI;
	int j, leastJ;
	int leastDist;
	int leastSetV;

	FILE *fp = fopen("p083_matrix.txt", "r");

	for (i = 0; i < SIDE; i++)
		for (j = 0; j < SIDE; j++) {
			fscanf(fp, " %d ", array[i] + j);

			if (j != (SIDE - 1))
				fgetc(fp);

			dists[i][j] = -1;
			visit[i][j] = 0;
		}

	dists[0][0] = 0;

	int iterations = 0;

	while (1) {
		leastSetV = 0;

		for (i = 0; i < SIDE; i++)
			for (j = 0; j < SIDE; j++)
				if (visit[i][j] == 0 && dists[i][j] != -1)
					if (!leastSetV || dists[i][j] < leastDist) {
						leastSetV = 1;
						leastDist = dists[i][j];
						leastI = i;
						leastJ = j;
					}

		if (!leastSetV) {
			printf("%d -> %d, %d\n", iterations, leastI, leastJ);
			break;
		}

		if (leastI == (SIDE - 1) && leastJ == (SIDE - 1))
			break;

		if (leastI > 0 && visit[leastI - 1][leastJ] == 0)
			dists[leastI - 1][leastJ] = (dists[leastI - 1][leastJ] == -1 ||
										(dists[leastI][leastJ] + array[leastI - 1][leastJ]) < dists[leastI - 1][leastJ]) ?
										(dists[leastI][leastJ] + array[leastI - 1][leastJ]) : dists[leastI - 1][leastJ];
		if (leastI < (SIDE - 1) && visit[leastI + 1][leastJ] == 0)
			dists[leastI + 1][leastJ] = (dists[leastI + 1][leastJ] == -1 ||
										(dists[leastI][leastJ] + array[leastI + 1][leastJ]) < dists[leastI + 1][leastJ]) ?
										(dists[leastI][leastJ] + array[leastI + 1][leastJ]) : dists[leastI + 1][leastJ];
		if (leastJ > 0 && visit[leastI][leastJ - 1] == 0)
			dists[leastI][leastJ - 1] = (dists[leastI][leastJ - 1] == -1 ||
										(dists[leastI][leastJ] + array[leastI][leastJ - 1]) < dists[leastI][leastJ - 1]) ?
										(dists[leastI][leastJ] + array[leastI][leastJ - 1]) : dists[leastI][leastJ - 1];
		if (leastJ < (SIDE - 1) && visit[leastI][leastJ + 1] == 0)
			dists[leastI][leastJ + 1] = (dists[leastI][leastJ + 1] == -1 ||
										(dists[leastI][leastJ] + array[leastI][leastJ + 1]) < dists[leastI][leastJ + 1]) ?
										(dists[leastI][leastJ] + array[leastI][leastJ + 1]) : dists[leastI][leastJ + 1];

		visit[leastI][leastJ] = 1;

		iterations++;
	}

	printf("Answer: %d\n", dists[SIDE - 1][SIDE - 1] + array[0][0]);

	return 0;
}
