#include <atmel_start.h>
#include <app_startup.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();


	/* Application startup */
	AppStartup();

	/* Replace with your application code */
	while (1) {

		ASSERT(0);
	}
}
