/**
 * \file    heartbeat.h
 * \brief   Simple 1 second led heartbeat and status print running in background 
 * \author  Karzan M.
 * 
 * To use: 
 * User has to call HEARTBEAT_SETUP(stop_fn) macro first after includes
 * -> intended use is HEARTBEAT_SETUP(NULL) 
 * Then in source code
 * -> heartbeat_init()
 */

#ifndef HEARTBEAT_H_
#define HEARTBEAT_H_

#include <stdbool.h>
#include <stdio.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

/* init functions, set stop_fn to NULL unless stop function is desired */
#define HEARTBEAT_SETUP(stop_fn) \
    K_TIMER_DEFINE(heartbeat_timer, heartbeat_callback, stop_fn);

/* prints the led heartbeat status to serial*/
void log_led_status(bool led_state);

/* initializes the timer peripheral for heartbeat */
int heartbeat_init(void);

/* handler for the timer expire */
void heartbeat_callback(struct k_timer *timer_id);

#endif /* HEARTBEAT_H_ */
