#define NX 3
#define NY 4
#define NZ 5

void print_array_values(const int *values, const int *nvalues);

int main(void) {
	int index = 0;
	int i, j, k, nvals;

	int values[NZ][NY][NX];
	for (k = 0; k < NZ; k++)
		for (j = 0; j < NY; j++)
			for (i = 0; i < NX; i++)
				values[k][j][i] = index++;
	
	nvals = NX*NY*NZ;
	print_array_values((const int *)values, &nvals);

	return 0;
}
