
#ifndef UNTITLED2_ENUM_H
#define UNTITLED2_ENUM_H

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_INVALID_COMPRESSION,
    READ_INVALID_PLANES
    /* коды других ошибок  */
};

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
    /* коды других ошибок  */
};

#endif //UNTITLED2_ENUM_H
