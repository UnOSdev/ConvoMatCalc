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


// 'Valgrind' was used to check for any memory leaks.
// All heap blocks were freed -- no leaks are possible

#include "matrix.h"

int main(){
	Matrix viewMat, filterMat, resultMat;
	initMatrix(&viewMat, 4, 4);
	initMatrix(&filterMat, 3, 3);
	initMatrix(&resultMat, viewMat.I - filterMat.I + 1, viewMat.J - filterMat.J + 1);
	Number vmd[] = {
		0, 1, 2, 0,
		3, 4, 5, 2,
		6, 7, 1, 1,
		1, 2, 3, 4
	};
	Number fmd[] = {
		0, 1, 0,
		2, 3, 1,
		0, 1, 2
	};

	setDataMatrix(&viewMat, vmd);
	setDataMatrix(&filterMat, fmd);

	convolutionMatrix(&resultMat, viewMat, filterMat);
	printMatrix(resultMat);

	freeMatrix(&viewMat);
	freeMatrix(&filterMat);
	freeMatrix(&resultMat);
	return 0;
}	