#include "MapReader.h"

Image MapReader::Read(const char* path) {
	Image img = LoadImage(path);
	ImageBlurGaussian(&img, 1);
	ImageColorGrayscale(&img);

	return img;
}
/**
* Performs pixel convolution with the provided kernel
* @param pixels: K*K matrix of pixel values
* @param kernel: K*K matrix with one of the sobel kernels
* @returns center pixel value
*/
static float Convolve(float pixels[K][K], float kernel[K][K]) {
	float value = 0; // value variable for returning

	for (int i = 0; i < K; i++) { // pairwise multiplication of the kernel values and the pixel values
		for (int j = 0; j < K; j++) {
			value += pixels[i][j] * kernel[i][j];
		}
	}

	return value;
}

/**
* Extracts a K*K matrix of pixel values for convolution
* @param pixels: K*K matrix to store the pixel values
* @param image: source of pixels
* @param x: x dimension
* @param y: y dimension
*/
static void ExtractPixels(float pixels[K][K], Image image, int x, int y) {
	int W = image.width; int H = image.height; // stores image height and width

	int m = 0; int n = 0; // initializes index variables
	for (int i = x-1; i < x+2; i++) {
		n = 0;
		for (int j = y-1; j < y+2; j++) {
			if ((i >= 0 && i < W) && (j >= 0 && j < H)) {
				pixels[m][n] = GetImageColor(image, i, j).r;
			}
			else {
				pixels[m][n] = 0;
			}
			n++;
		}
		m++;
	}

}

void MapReader::Sobel(Image* image, uint8_t threshold) {
	float kernel_x[K][K] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
	float kernel_y[K][K] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

	int W = image->width; int H = image->height; // stores image height and width

	Image copy = ImageCopy(*image);

	for (int i = 1; i < W-1; i++) { // traverses the entire image
		for (int j = 1; j < H-1; j++) {
			float pixels[K][K];
			
			ExtractPixels(pixels, copy, i, j);
			uint8_t value = sqrt(pow(Convolve(pixels, kernel_x), 2) + pow(Convolve(pixels, kernel_y), 2));
			uint8_t magnitude = Clamp(value, 0, 255);
			
			if (magnitude > threshold) {
				ImageDrawPixel(image, i, j, RAYWHITE);
			}
			else {
				ImageDrawPixel(image, i, j, BLACK);
			}
			
			
		}
	}

}