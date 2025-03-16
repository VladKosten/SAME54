#ifndef USHELL_STARTUP_CFG_H_
#define USHELL_STARTUP_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*================================================================[INCLUDE]=================================================*/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/*===========================================================[MACRO DEFINITIONS]============================================*/

/**
 * \brief Matrix Kbd assert definition
 */
// #define USHELL_STARTUP_ASSERT(cond) ASSERT((cond))

/* Define the OSAL port type */

/**
 * \brief FreeRTOS OSAL port
 * \note Uncomment this line to use the FreeRTOS OSAL port
 *       Recommended use CMake to define this option
 */
#define USHELL_STARTUP_OSAL_PORT_FREERTOS

/* Define the HAL port type */

/**
 * \brief ATMEL HAL port
 * \note Uncomment this line to use the ATMEL HAL port
 *      Recommended use CMake to define this option
 * \todo Add the ATMEL HAL port implementation
 */
#define USHELL_STARTUP_HAL_PORT_ATMEL

/* Include port-specific headers: */

/* Include OSAL port-specific headers here: */
#ifdef USHELL_STARTUP_OSAL_PORT_FREERTOS
    #include "ushell_osal_freertos.h"
#endif

/* Include HAL port-specific headers here: */
#ifdef USHELL_STARTUP_HAL_PORT_ATMEL
    #include "ushell_hal_asf.h"
    #include "atmel_start.h"
#endif

/* Include other port-specific headers here: */
// ... //

/**
 * \brief uShell name by default
 */
#ifndef USHELL_STARTUP_NAME
    #define USHELL_STARTUP_NAME "uShell"
#endif

#define USHELL_STARTUP_AUTH_IS_EN    false
#define USHELL_STARTUP_ECHO_IS_EN    false
#define USHELL_STARTUP_HISTORY_IS_EN false
#define USHELL_STARTUP_PROMPT_IS_EN  false

/**
 * \brief Define the OSAL port type
 */
#ifndef USHELL_STARTUP_OSAL_PORT_TYPE
    #ifdef USHELL_STARTUP_OSAL_PORT_FREERTOS

        /* For startup */
        #define USHELL_STARTUP_OSAL_PORT_TYPE UShellOsalFreertos_s
        #define USHELL_STARTUP_OSAL_PORT_NAME "uShellOsal"
    #endif
    /* Add definition for other ports here: */
    // ... //
#endif

/**
 * \brief Define the HAL port type
 */
#ifndef USHELL_STARTUP_HAL_PORT_TYPE
    #ifdef USHELL_STARTUP_HAL_PORT_ATMEL
        #define USHELL_STARTUP_HAL_PORT_TYPE                          UShellHalPort_s
        #define USHELL_STARTUP_HAL_PORT_UART_DESC                     &SERVICE_PORT
        #define USHELL_STARTUP_HAL_PORT_NAME                          "uShellHal"
        #define USHELL_STARTUP_HAL_PORT_ASF_TRANSCEIVER_ENABLED       false
        #define USHELL_STARTUP_HAL_PORT_ASF_TRANSCEIVER_RX_PIN        0
        #define USHELL_STARTUP_HAL_PORT_ASF_TRANSCEIVER_RX_PIN_ACTIVE false
        #define USHELL_STARTUP_HAL_PORT_ASF_TRANSCEIVER_TX_PIN        0
        #define USHELL_STARTUP_HAL_PORT_ASF_TRANSCEIVER_TX_PIN_ACTIVE false
    #endif
    /* Add definition for other ports here: */
    // ... //
#endif

#ifdef __cplusplus
}
#endif

#endif