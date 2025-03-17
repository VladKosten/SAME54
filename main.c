#include <atmel_start.h>
#include <app_startup.h>

static void setIrqPrioNVIC(const IRQn_Type irqType, const uint8_t irqPrio);

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();

    for (int i = 0; i < 4; i++)
    {
        setIrqPrioNVIC(SERCOM2_0_IRQn + i, 4u);
    }

    /* Application startup */
    AppStartup();

    /* Replace with your application code */
    while (1)
    {

        ASSERT(0);
    }
}

/**
 * \brief      Set irq priority
 * \param[in]  no;
 * \param[out] no;
 * \return     no.
 */
static void setIrqPrioNVIC(const IRQn_Type irqType, const uint8_t irqPrio)
{
    NVIC_DisableIRQ(irqType);
    NVIC_ClearPendingIRQ(irqType);
    NVIC_SetPriority(irqType, irqPrio);
    NVIC_EnableIRQ(irqType);
}