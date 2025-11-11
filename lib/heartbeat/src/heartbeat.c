/**
 * \file    heartbeat.h
 * \brief   Simple 1 second led heartbeat and status print running in background 
 * \author  Karzan M.
 */

#include "heartbeat.h"

/* definetree alias for led on board*/
#define LED0_NODE DT_ALIAS(led0)

/* build error here means board is unsupported */
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* user defined via HEARTBEAT_SETUP() macro in source */
extern struct k_timer heartbeat_timer;


extern void heartbeat_callback(struct k_timer *timer_id) {
	gpio_pin_toggle_dt(&led);
	// static bool led_state;
	// led_state = !led_state
	// log_led_status()
}

int heartbeat_init(void) {
	/* configure led */
	if (!gpio_is_ready_dt(&led)) {
		return 1;
	}
	if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) {
		return 1;
	}

	/* init timer peripheral <-- extra feature */
	// k_timer_init(&heartbeat_timer, heartbeat_callback, NULL);

	/* start timer peripheral */
	k_timer_start(&heartbeat_timer, K_SECONDS(1), K_SECONDS(1));

	return 0;
}

void log_led_status(bool led_state) {
	printf("LED state: %s\n", led_state ? "ON" : "OFF");
}
