// LZ4frame API example : compress a file
// Based on sample code from Zbigniew Jędrzejewski-Szmek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <lz4frame.h>

#define BUF_SIZE 16*1024
#define LZ4_HEADER_SIZE 19
#define LZ4_FOOTER_SIZE 4

static const LZ4F_preferences_t lz4_preferences;

static size_t compress_file(FILE *in, FILE *out, size_t *size_in, size_t *size_out) ;

static size_t get_block_size(const LZ4F_frameInfo_t* info) ;

static size_t decompress_file(FILE *in, FILE *out);

int compare(FILE* fp0, FILE* fp1);