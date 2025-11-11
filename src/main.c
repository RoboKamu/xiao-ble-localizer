/**
 * \brief Bluetooth observer sample + heartbeat blinky 
 */

#include <zephyr/sys/printk.h>
#include <zephyr/bluetooth/bluetooth.h>
#include "heartbeat.h"

int observer_start(void);

/* setup functions and timers  */
HEARTBEAT_SETUP(NULL);

int main(void)
{
	int err;

	printk("Starting Observer Demo\n");

	/* Initialize the Bluetooth Subsystem */
	err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return 0;
	}

	/* start heartbeat */
	heartbeat_init();

	(void)observer_start();

	printk("Exiting %s thread.\n", __func__);
	return 0;
}
