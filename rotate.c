#include <stdio.h>
#include <stdlib.h>
#include "ImageDescription.h"


    struct image rotate( struct image const source ){
    size_t x = source.width;
    size_t y = source.height;
    struct pixel* temp_pixel = malloc(x*y*sizeof(struct pixel));
    for (size_t j = 0; j < y; j++){
        for (size_t i = 0; i < x; i++){
            temp_pixel[y*i + y-j-1] = source.data[x*j + i];
        }
    }
    struct image rotate_image = {source.height,source.width,temp_pixel};
    return rotate_image;
}
