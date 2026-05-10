#include "internal/arch/riscv/syscall_list.h"
#include <internal/io.h>
#include <internal/syscall.h>

size_t write(int fd, const void *buf, size_t len){
	if(!buf || fd < 0 || len <=0) return 0;
	return syscall(SYS_write, fd, buf, len);
}

size_t read(int fd, void *buf, size_t len){
	if(!buf || fd < 0 || len <=0) return 0;
	return syscall(SYS_read, fd, buf, len);
}
