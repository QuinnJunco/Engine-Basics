#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* shader_to_str(const char* path) {
	// file opening
	FILE* infile;
	infile = fopen(path, "r");
	if (!infile) {
		return NULL;
	}

	fseek(infile, 0, SEEK_END); // gets the index of the last character in the file
	char* str = (char*)malloc(sizeof(char)*(ftell(infile)+1));
	if (!str) {
		return NULL;
	}
	rewind(infile); // rewinds file read pointer

	/* Reads the file */
	char c;
	int i = 0;
	while (c = fgetc(infile) != EOF) {
		str[i] = c;
		i++;
	}
}
