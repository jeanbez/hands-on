#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "array.h"

int write_data(char *filename)
{
    science data = {
        .row = YDIM,
        .col = XDIM,
        .iter = 1
    };

    int *array;
    int fd;
    int ret=0;

    array = buffer_create(0, XDIM, YDIM);

    fd = open(filename, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    if (fd < 0) goto fn_error;

    /* HANDS-ON: write our "array" data to a file, but also write some metadata
     * so we know what is stored in the file.  The metadata is stored in the
     * 'data' struct declared above */

    ret = close(fd);
    if (ret < 0) goto fn_error;

    free(array);
    return ret;

fn_error:
    perror("Error:");
    return ret;
}

int main(int argc, char **argv)
{
    int ret;

    ret = write_data(argv[0]);
}
