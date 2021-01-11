#include "stdio.h"
#ifndef UNTITLED2_READER_WRITER_H
#define UNTITLED2_READER_WRITER_H

enum read_status from_bmp(FILE* const in, struct image* img);

enum write_status to_bmp( FILE* const out, struct image const* img );
#endif //UNTITLED2_READER_WRITER_H
