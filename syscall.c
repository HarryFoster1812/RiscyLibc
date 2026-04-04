#include <internal/arch/riscv/syscall_arch.h>
#include <stdarg.h>

long syscall(long num, ...)
{
    va_list valist;
    long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

    va_start(valist, num);
    a = va_arg(valist, long);
    b = va_arg(valist, long);
    c = va_arg(valist, long);
    d = va_arg(valist, long);
    e = va_arg(valist, long);
    f = va_arg(valist, long);
    va_end(valist);

    // Call the correct function depending on which arguments are used
    if (f != 0) return __syscall6(num, a, b, c, d, e, f);
    if (e != 0) return __syscall5(num, a, b, c, d, e);
    if (d != 0) return __syscall4(num, a, b, c, d);
    if (c != 0) return __syscall3(num, a, b, c);
    if (b != 0) return __syscall2(num, a, b);
    if (a != 0) return __syscall1(num, a);
    return __syscall0(num);
}
