#ifndef __IO_H__
#define __IO_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

size_t write(int fd, const void *buf, size_t len);
size_t read(int fd, void *buf, size_t len);

#ifdef __cplusplus
}
#endif

#endif
