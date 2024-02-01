// MIT License

// Copyright (c) 2024 Ubeyda ALNACCAR (UnOSdev)

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/* code */

#include <stdio.h>
#include "matrix.h"

void initMatrix(Matrix* mat, const Index sizeI, const Index sizeJ){
	mat->I = sizeI;
	mat->J = sizeJ;
	mat->data = (Number**)malloc(sizeof(Number*) * sizeJ);
	for (size_t i = 0; i < sizeJ; i++)
	{
		mat->data[i] = (Number*)malloc(sizeof(Number) * sizeI);
	}
}

void freeMatrix(Matrix* mat){
	for (size_t i = 0; i < mat->J; i++)
	{
		free(mat->data[i]);
	}
	free(mat->data);
}

void setDataMatrix(Matrix* mat, Number* data){
	Number c = 0;
	for (Number j = 0; j < mat->J; j++)
	{
		for (Number i = 0; i < mat->I; i++)
		{
			mat->data[j][i] = data[c++];
		}	
	}	
}

void printMatrix(Matrix mat){
	printf("{\n");
	for (Index j = 0; j < mat.J; j++)
	{
		printf("\t");
		for (Index i = 0; i < mat.I; i++)
		{
			printf("%li, ", mat.data[j][i]);
		}
		printf("\n");
	}
	printf("}\n");
}

Number convoIndexCalc(Index wantedJ, Index wantedI, Matrix viewMatrix, Matrix filterMatrix){
	Number result = 0;
	Number div = 0;
	for (Index j = 0; j < filterMatrix.J; j++)
	{
		for (Index i = 0; i < filterMatrix.I; i++)
		{
			result += filterMatrix.data[j][i] * viewMatrix.data[(j + wantedJ)][i + wantedI];
			div += filterMatrix.data[j][i];
		}
	}
	result /= div;
	return result;
}

void convolutionMatrix(Matrix* resultMatrix, Matrix viewMatrix, Matrix filterMatrix){
	for (Index y = 0; y < resultMatrix->J; y++)
	{
		for (Index x = 0; x < resultMatrix->I; x++)
		{
			resultMatrix->data[y][x] = convoIndexCalc(y, x, viewMatrix, filterMatrix);
		}
	}
}