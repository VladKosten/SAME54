/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

/*! The buffer size for USART */
#define SERVICE_PORT_BUFFER_SIZE 256

struct usart_async_descriptor SERVICE_PORT;

static uint8_t SERVICE_PORT_buffer [SERVICE_PORT_BUFFER_SIZE];

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void SERVICE_PORT_CLOCK_init()
{

    hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM2_GCLK_ID_CORE, CONF_GCLK_SERCOM2_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
    hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM2_GCLK_ID_SLOW, CONF_GCLK_SERCOM2_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

    hri_mclk_set_APBBMASK_SERCOM2_bit(MCLK);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void SERVICE_PORT_PORT_init()
{

    gpio_set_pin_function(SERVICE_PORT_TX, PINMUX_PB25D_SERCOM2_PAD0);

    gpio_set_pin_function(SERVICE_PORT_RX, PINMUX_PB24D_SERCOM2_PAD1);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void SERVICE_PORT_init(void)
{
    SERVICE_PORT_CLOCK_init();
    usart_async_init(&SERVICE_PORT, SERCOM2, SERVICE_PORT_buffer, SERVICE_PORT_BUFFER_SIZE, (void*) NULL);
    SERVICE_PORT_PORT_init();
}

void system_init(void)
{
    init_mcu();

    // GPIO on PC18

    gpio_set_pin_level(LED0,
                       // <y> Initial level
                       // <id> pad_initial_level
                       // <false"> Low
                       // <true"> High
                       true);

    // Set pin direction to output
    gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);

    gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);

    SERVICE_PORT_init();
}
