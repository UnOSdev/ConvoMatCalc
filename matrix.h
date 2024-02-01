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

#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include <stdlib.h>

//We'll be setting new types for better understanding.
//And to save time not writing long data type names.
typedef uint64_t Index;//Unsigned 64-bit integer. Ranges 0 .. 1,844674407×10¹⁹ (approximately)
typedef int64_t Number;//Signed 64-bit integer. Ranges -9,223372037×10¹⁸ .. 9,223372037×10¹⁸ (approximately)
//64-bit used for precision and high value range.
//Really big operations can be done using this structure without any problems.


//A matrix is basically 2 dimensional array.
//'I' represents the horizontal index.
//'J' represents the vertical index.
typedef struct{
	Index I, J;
	Number** data;
} Matrix;

//Initialize matrix by setting its size and allocating required memory.
void initMatrix(Matrix* mat, const Index sizeI, const Index sizeJ);
//Free-ing all allocated memory of the matrix.
void freeMatrix(Matrix* mat);
//Set raw data to the matrix data variable.
void setDataMatrix(Matrix* mat, Number* data);
//Print matrix's data to the standart output.
void printMatrix(Matrix mat);


//Calculate each value of the result matrix in respect to the wanted indexes.
Number convoIndexCalc(Index wantedJ, Index wantedI, Matrix viewMatrix, Matrix filterMatrix);
//Calculate the resulting convolution matrix.
void convolutionMatrix(Matrix* resultMatrix, Matrix viewMatrix, Matrix filterMatrix);
#endif