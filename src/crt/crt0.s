.section .text

.extern __libc_start_main
.extern main
.extern __exit
.global _start

_start:
		# set up arguments (init argc and argv)
    la sp, __heap_stack_end
		la a0, main
    call __libc_start_main
		
		tail __exit

