#pragma once

#include "internal/arch/riscv/syscall_list.h"
#include "internal/types.h"
#include <internal/syscall.h>


int execve(char const * filename, char * const argv[])
{
	return syscall(SYS_execve, filename, argv);
}

int execv(char const * filename, char * const argv[])
{
	return execve(filename, argv);
}

pid_t fork(){
	return syscall(SYS_fork);
}
