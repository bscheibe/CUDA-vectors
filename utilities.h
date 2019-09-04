/*
 * utilities.h
 *
 *  Created on: Feb 18, 2018
 *      Author: greagory
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stdlib.h>
#include <stdio.h>

void** malloc2D(size_t	rows,	size_t	cols,	size_t	sizeOfType);
void free2D(void***	matrix);
void*** malloc3D(size_t rows, size_t cols, size_t layers, size_t sizeOfType);
void free3D(void**** matrix);
void print2d(void*** matrix, int dim1, int dim2);
void print3d(void**** matrix, int dim1, int dim2, int dim3);

#endif /* UTILITIES_H_ */
