#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

std::string ariel::mat(int i, int j, char c1, char c2)
{
	char* mat = (char*) malloc (sizeof(char) * i * j);
	if (mat == NULL)
	{
		return "Malloc error";
	}
	
	// init matrice with c2
	for (int k = 0; k < i*j; k++)
	{
		mat[k] = '|';
	}
	
	// paint matrice with c1
	for (int k = 0; k < i; k = k + 2)
	{
		// top and bottom
		for (int l = k; l < i - k; l++)
		{
			int top = l + k*i;
			int bot = (i*j) - top - 1;
			mat[top] = c1;
			mat[bot] = c1;
		}

		// left
		for (int l = k*(i+1); l < i * (j-k); l = l + i)
		{	
			mat[l] = c1;
		}
		
		// right
		for (int l = (i * j) - 1 - (i*k) - k; l >= k*i - k; l = l - i)
		{
			mat[l] = c1;
		}
	}

	// print matrice
	for (int k = 0; k < i*j; k++)
	{
		if(k != 0 && k % i == 0)
			std::cout << "\n";
		std::cout << mat[k];
	}

	std::string myRug = "";


	free(mat);
	return myRug;
}
