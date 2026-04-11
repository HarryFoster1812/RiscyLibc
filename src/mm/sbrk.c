#include <internal/syscall.h>
#include <internal/arch/riscv/syscall_list.h>
#include <stdint.h>

static uintptr_t current_brk = 0;

void *sbrk(uint32_t increment) {
    if (current_brk == 0) {
        current_brk = syscall(SYS_brk, 0);
    }

    uintptr_t new_brk = current_brk + increment;

    // Stack Pointer Safety Check
    register uintptr_t sp __asm__("sp");
    if (new_brk >= (sp - 128)) { // 128-byte safety margin
        return (void *)-1;
    }

    uintptr_t actual = syscall(SYS_brk, new_brk);
    if (actual < new_brk) return (void *)-1;

    void *old_brk = (void *)current_brk;
    current_brk = actual;
    return old_brk;
}
