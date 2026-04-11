#include <internal/types.h>
#include <internal/mm/mem_list.h>

static void init(void)
{
}

static void cleanup(void)
{
}

int __libc_start_main(int (*main_fn)(void))
{
	int exit_code;

	init();
	exit_code = main_fn();
	cleanup();

	return exit_code;
}
