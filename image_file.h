#ifndef __IMAGE_FILE_H
#define __IMAGE_FILE_H

#include "volume_container.h"

#define IMAGE_FILE_WRITE_ACCESS_FLAG 1

int raw_image_open(volume_container *v, char *pathname, int flags);
int raw_image_close(volume_container *v);

int hdf_image_open(volume_container *v, char *pathname, int flags);
int hdf_image_close(volume_container *v);
int image_file_is_hdf(char *pathname);

#endif /* #ifdef __IMAGE_FILE_H */

