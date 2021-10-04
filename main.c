#include "hunter.h"
#include "io.h"

main()
{
	gpio_init();
	setup();
	while (1)
	{
		loop();
	}
}
