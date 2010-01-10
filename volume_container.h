#ifndef __VOLUME_CONTAINER_H
#define __VOLUME_CONTAINER_H

#include <linux/types.h> /* for off64_t */
#include <unistd.h> /* for ssize_t */

typedef struct st_volume_container {
	ssize_t (*read) (struct st_volume_container *v, off64_t position, void *buf, size_t count);
	ssize_t (*write) (struct st_volume_container *v, off64_t position, void *buf, size_t count);
	unsigned int bytes_per_sector;
	union {
		struct st_volume_container_file {
			int fd;
			off64_t data_offset;
		} file;
		struct st_volume_container_partition {
			struct st_volume_container *parent;
			off64_t data_offset;
		} partition;
	} data;
} volume_container;

#endif /* #ifdef __VOLUME_CONTAINER_H */

