/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __SYSCALL_H__
#define __SYSCALL_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/arch/riscv/syscall_list.h>

long syscall(long n, ...);

#ifdef __cplusplus
}
#endif

#endif
