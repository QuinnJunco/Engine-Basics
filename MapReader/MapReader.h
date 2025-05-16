#ifndef MAP_READER_H
#define MAP_READER_H
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <iostream>

#define K 3 // defines the size of the K*K kernels

namespace MapReader {
	/**
	* Reads the image in from a string path then converts it to grayscale
	* @param path: Image file path
	* @returns Image*
	*/
	Image Read(const char* path);

	void Sobel(Image* image, uint8_t threshold);

}
#endif // !MAP_READER_H
