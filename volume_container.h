#ifndef __VOLUME_CONTAINER_H
#define __VOLUME_CONTAINER_H

#include <linux/types.h> /* for off64_t */

typedef struct st_volume_container {
	ssize_t (*read) (struct st_volume_container *v, off64_t position, void *buf, size_t count);
	ssize_t (*write) (struct st_volume_container *v, off64_t position, void *buf, size_t count);
	union {
		struct st_volume_container_file {
			int fd;
			off64_t data_offset;
		} file;
	} data;
} volume_container;

#endif /* #ifdef __VOLUME_CONTAINER_H */

