// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void funcprint( int arr[], int size ){
	for( int i = 0; i < size; i++ )
		cout << arr[i] << " ";
	cout << endl;
}

int *ar; // ** Указатель на int

void quickSort( int a[], long N ) {
	if( N < 2 )
		return;

	long i = 0, j = N - 1; // -- begin and end of array
	int p = a[N >> 1]; // -- comparing element P

	while( i < j ) {
		while( a[i] < p ) i++; // -- elements before P is true order
		while( a[j] > p ) j--; // -- elements after P is true order

		if( i < j ) // -- do true order if is broken
			swap( a[i++], a[j--] );
	}
//	funcprint( ar, 9 ); // Выводить массив с первого элемента в текущем узле рекурсии
	quickSort( a, j ); // -- recursive sorting left part of array
	quickSort( a + i, N - i ); // -- recursive sorting right part of array
}


#include <vector>
#include <algorithm>
int main() {
	int a[10] = { 1,2,3,4,1,2,6,7,8 };
	//int a[10] = { 5,2,1,9,1,4,6,2,0 };
	ar = a; // ** Установить указатель на первый элемент массива
	int N = 8;

	const unsigned SZ = 2'000'000;
	std::vector<int> va;
	for( int i = 0; i < SZ; ++i )
		va.push_back( rand());

	std::vector<int> vb{ va };

	auto t = clock();
	quickSort( va.data(), SZ );
	std::cout << "Qsort " << SZ << " elements for: " << float( clock() - t ) / CLOCKS_PER_SEC << " s\n";

	t = clock();
	quickSort( va.data(), SZ );
	std::cout << "Qsort sorted elements for: " << float( clock() - t ) / CLOCKS_PER_SEC << " s\n";

	t = clock();
	std::sort( vb.begin(), vb.end() );
	std::cout << "std::sort elements for: " << float( clock() - t ) / CLOCKS_PER_SEC << " s\n";

	t = clock();
	std::sort( vb.begin(), vb.end() );
	std::cout << "std::sort sorted elements for: " << float( clock() - t ) / CLOCKS_PER_SEC << " s\n";

	funcprint( va.data(), 200);
}
