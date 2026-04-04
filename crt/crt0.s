.section .text

.global _start

_start:
		# set up arguments (init argc and argv)
		la main
    call __libc_start_main
		
		li a7, SYSCALL_EXIT
		ecall

