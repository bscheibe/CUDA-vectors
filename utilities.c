/*
 * utilities.c
 *
 *  Created on: Feb 18, 2018
 *      Author: greagory
 */

#include "utilities.h"

void main() {
	printf("Dimensionality of 3-D matrix===> ");
	int dim1,dim2,dim3;
	scanf("%d", &dim1);
	scanf("%d", &dim2);
	scanf("%d", &dim3);

	void ***matrix3d = malloc3D(dim1,dim2,dim3,sizeof(float));
	void **matrix2d = malloc2D(dim1,(dim2*dim3),sizeof(float));
	float *array = (float*) malloc
			(dim1*dim2*dim3 * sizeof(float));
	int total = dim1*dim2*dim3;
	for (int i=0;i<total;i++){
		scanf("%0.2f", &array[i]);
	}
	for(int i=0;i<total;i++){
			matrix2d[i/dim1][i%dim1] = &array[i];
	}
	print2d(matrix2d,dim1,(dim2*dim3));
	print3d(matrix3d,dim1,dim2,dim3);
	free(array);
	free2D(matrix2d);
	free3D(matrix3d);
}

void print2d(void*** matrix, int dim1, int dim2){
	for(int i=0;i<dim1;i++){
			for(int j=0;j<dim2;j++)
				printf("%0.2f,",matrix[i]+j);
			printf(";");
		}
}

void print3d(void**** matrix, int dim1, int dim2, int dim3){
	for (int i=0; i<dim1;i++){
		print2d(matrix[i],dim2,dim3);
		printf("\n");
	}
}

void**	malloc2D(size_t	rows,	size_t	cols,	size_t	sizeOfType)	{
				void*	block	=	malloc(sizeOfType	*	rows	*	cols);
				void**	matrix	=	malloc(sizeof(void*)	*	rows);
				for	(int	row	=	0;	row	<	rows;	++row)	{
								matrix[row]	=	block	+	cols	*	row	*	sizeOfType;
				}
				return	matrix;
}
void	free2D(void***	matrix)	{
				free((*matrix)[0]);
				free((*matrix));
				matrix	=	NULL;
}

void*** malloc3D(size_t rows, size_t cols, size_t layers, size_t sizeOfType){
	void* block = malloc(sizeOfType * rows * cols * layers);
	void*** matrix = malloc(sizeof(void*) * rows);
	for (int column = 0; column < cols; ++cols){
	for (int row = 0; row < rows; ++row){
			matrix[column][row] = block + row * sizeOfType;
			}
		}
	return matrix;
}

void free3D(void**** matrix){
	free2D((**matrix)[0]);
	free((*matrix));
	matrix = NULL;
}
