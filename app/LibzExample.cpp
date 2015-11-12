/*
 * LibzExample.cpp
 *
 *  Created on: 2015-11-12
 *      Author: juns
 */

#include <iostream>
#include <stdlib.h>

#include <zlib.h>
#include<zconf.h>

using namespace std;

int main(int argc, char* argv[]) {
    Bytef src[] =
            "Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!";
    uLong srcSize = sizeof(src);
    Bytef* dest = NULL;
    uLong destSize = 0;

    cout << "srcSize = " << srcSize << endl;

    destSize = compressBound(srcSize);
    cout << "compressBound : \ndestSize = " << destSize << endl;

    if ((dest = (Bytef*) malloc(sizeof(Bytef*) * destSize)) == NULL) {
        cout << "no enough memory!\n" << endl;
        return -1;
    }

    if (compress(dest, &destSize, src, srcSize) != Z_OK) {
        cout << "compress failed!\n" << endl;
        return -1;
    }

    cout << "compress : \nsrc = " << src << "\nsrcSize = " << srcSize << "\ndest = " << dest << "\ndestSize = "
         << destSize << endl;

    if (uncompress(src, &srcSize, dest, destSize) != Z_OK) {
        cout << "uncompress failed!\n" << endl;
        return -1;
    }

    cout << "uncompress : \nsrc = " << src << "\nsrcSize = " << srcSize << "\ndest = " << dest << "\ndestSize = "
         << destSize << endl;

    if (dest != NULL) {
        free(dest);
        dest == NULL;
    }

    return 0;
}

