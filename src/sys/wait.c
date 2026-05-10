#pragma once
#include "internal/arch/riscv/syscall_list.h"
#include <sys/types.h>
#include <internal/syscall.h>

pid_t wait(int *stat_loc){
	return syscall(SYS_wait4, stat_loc);
}
