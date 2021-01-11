#include <stdio.h>
#include "READER_WRITER.h"
#include "OPEN_CLOSE_FILE.h"
#include "ImageDescription.h"
#include "rotate.h"


int main(int argc, char* argv[]) {
    if (argc < 3){
        printf("Not enough arguments.\n");
        printf("Check if you entered file paths.!\n");
    }

    struct image temp_img;
    from_bmp(open_file_toREAD(argv[1]), &temp_img);
    struct image rotate_img = rotate(temp_img);
    to_bmp(open_file_toWRITE(argv[2]), &rotate_img);
    return 0;
}
