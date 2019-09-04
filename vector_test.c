/*
 * types.c
 *
 *  Created on: Feb 18, 2018
 *      Author: greagory
 */

#include "types.h"

int smallest(const Vector3t* pts, int n);

void main() {
	int N;
	printf("Number of elements===>");
	scanf("%d", &N);
	struct Vector3t *points = (struct Vector3t *)
			malloc (N * sizeof(struct Vector3t));
	int x,y,z;
	for(int i=0; i<N; i++) {
		scanf("%d,%d,%d", &x, &y, &z);
		points[i].x = x;
		points[i].y = y;
		points[i].z = z;
	}
	int result = smallest(points, N);
	printf("The point closest to the origin is (%d,%d,%d)",
			points[result].x,
			points[result].y,
			points[result].z);
	free(points);
}

int smallest(const Vector3t* pts, int n) {
	int bestValue =  (int) sqrt(pts[0].x * pts[0].x
			+ pts[0].y * pts[0].y
			+ pts[0].z * pts[0].z);;
	int result;
	int temp;
	for (int i = 1; i < n; i++) {
		temp = (int) sqrt(pts[i].x * pts[i].x
				+ pts[i].y * pts[i].y
				+ pts[i].z * pts[i].z);
		if (bestValue > temp) {
			bestValue = temp;
			result = i;
		}
	}
	printf("%d\n",bestValue);
	return result;
}

