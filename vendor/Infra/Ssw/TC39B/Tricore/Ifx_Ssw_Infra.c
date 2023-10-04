/**
 * \file Ifx_Ssw_Infra.c
 * \brief Startup Software support functions.
 *
 * \version iLLD_1_0_1_16_0_1
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "Ifx_Cfg.h"
#include "Ifx_Ssw_Infra.h"

/******************************************************************************/
/*-------------------------Infrastructure Functions---------------------------*/
/******************************************************************************/

unsigned short Ifx_Ssw_getCpuWatchdogPassword(Ifx_SCU_WDTCPU *watchdog)
{
    return Ifx_Ssw_getCpuWatchdogPasswordInline(watchdog);
}


unsigned short Ifx_Ssw_getSafetyWatchdogPassword(void)
{
    return Ifx_Ssw_getSafetyWatchdogPasswordInline();
}


void Ifx_Ssw_clearCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_clearCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_setCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_setCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_clearSafetyEndinit(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinitInline(password);
}


void Ifx_Ssw_setSafetyEndinit(unsigned short password)
{
    Ifx_Ssw_setSafetyEndinitInline(password);
}


void Ifx_Ssw_serviceCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_setCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_serviceSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_setSafetyEndinitInline(password);
}


void Ifx_Ssw_disableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    /* Select CPU Watchdog based on Core Id */
    unsigned int    cpuIndex;
    cpuIndex = Ifx_Ssw_MFCR(CPU_CORE_ID);
    cpuIndex = (unsigned int)((unsigned int)cpuIndex >> IFX_CPU_CORE_ID_CORE_ID_OFF) & IFX_CPU_CORE_ID_CORE_ID_MSK;
    cpuIndex = Ifx_Ssw_MINU(cpuIndex, 5);
    Ifx_SCU_WDTCPU *wdt = &MODULE_SCU.WDTCPU[cpuIndex];

    Ifx_Ssw_clearCpuEndinit(wdt, password);
    wdt->CON1.B.DR = 1U;         /* Set DR bit in Config_1 register */
    Ifx_Ssw_setCpuEndinit(wdt, password);
}


void Ifx_Ssw_enableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    /* Select CPU Watchdog based on Core Id */
    unsigned int    cpuIndex;
    cpuIndex = Ifx_Ssw_MFCR(CPU_CORE_ID);
    cpuIndex = (unsigned int)((unsigned int)cpuIndex >> IFX_CPU_CORE_ID_CORE_ID_OFF) & IFX_CPU_CORE_ID_CORE_ID_MSK;
    cpuIndex = Ifx_Ssw_MINU(cpuIndex, 5);
    Ifx_SCU_WDTCPU *wdt = &MODULE_SCU.WDTCPU[cpuIndex];

    Ifx_Ssw_clearCpuEndinit(wdt, password);
    wdt->CON1.B.DR = 0U;         /* Clear DR bit in Config_1 register */
    Ifx_Ssw_setCpuEndinit(wdt, password);
}


void Ifx_Ssw_disableSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinit(password);
    SCU_WDTS_CON1.B.DR = 1U;     /* Set DR bit in Config_1 register */
    Ifx_Ssw_setSafetyEndinit(password);
}


void Ifx_Ssw_enableSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinit(password);
    SCU_WDTS_CON1.B.DR = 0U;     /* Clear DR bit in Config_1 register */
    Ifx_Ssw_setSafetyEndinit(password);
}


void Ifx_Ssw_startCore(Ifx_CPU *cpu, unsigned int programCounter)
{
    /* Set the PC */
    cpu->PC.B.PC = (unsigned int)programCounter >> 1U;

    /* release boot halt mode if required */
    Ifx_CPU_SYSCON syscon;
    syscon = cpu->SYSCON;

    if (syscon.B.BHALT)
    {
        syscon.B.BHALT = 0U;
        cpu->SYSCON    = syscon;
    }

}


void Ifx_Ssw_setCpu0Idle(void)
{
    Ifx_SCU_WDTCPU *wdt      = &MODULE_SCU.WDTCPU[0];
    unsigned short  cpuWdtPw = Ifx_Ssw_getCpuWatchdogPassword(wdt);
    Ifx_Ssw_clearCpuEndinit(wdt, cpuWdtPw);
    SCU_PMCSR0.B.REQSLP = 1U;
    Ifx_Ssw_setCpuEndinit(wdt, cpuWdtPw);
}


float Ifx_Ssw_getStmFrequency(void)
{
    float        oscFreq    = IFX_CFG_SSW_XTAL_FREQUENCY;
    float        sourcefreq = IFX_CFG_SSW_EVR_OSC_FREQUENCY;
    unsigned int insel      = SCU_SYSPLLCON0.B.INSEL;

    if (insel == 2U)
    {
        oscFreq = IFX_CFG_SSW_SYSCLK_PIN_FREQUENCY;
    }
    else if (insel == 1U)
    {
        oscFreq = IFX_CFG_SSW_XTAL_FREQUENCY;
    }
    else
    {
        oscFreq = IFX_CFG_SSW_EVR_OSC_FREQUENCY;
    }

    if (SCU_CCUCON0.B.CLKSEL != 0U)
    {
        sourcefreq = (oscFreq * (SCU_SYSPLLCON0.B.NDIV + 1U)) /
                     ((SCU_SYSPLLCON0.B.PDIV + 1U) * (SCU_SYSPLLCON1.B.K2DIV + 1U));
    }

    return sourcefreq / SCU_CCUCON0.B.STMDIV;
}

void Ifx_Ssw_doCppInit(void)
{
    Ifx_Ssw_C_InitInline();

#ifdef __TASKING__
extern void _main(void); /* cpp initialization */
    _main();
#endif
#ifdef __HIGHTEC__
extern void _init(void); /* cpp initialization */
    _init();
#endif
}

void Ifx_Ssw_doCppExit(int status)
{
#ifdef __TASKING__
extern void _doexit(void); /* cpp deinitialization */
    _doexit();
#endif
#ifdef __HIGHTEC__
extern void exit(int); /* cpp deinitialization */
    exit(status);
#endif
}

#if defined(__TASKING__)
#pragma optimize RL
#elif defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#endif

#if (IFX_CFG_SSW_ENABLE_MONBIST == 1U)

static void Ifx_Ssw_MonbistCheck(void);

void Ifx_Ssw_Monbist(void)
{
     uint32 timeout;

     /* Disable the write-protection for registers */
    IFX_CFG_SSW_CLEAR_SAFETY_ENDINIT();
    /* Enable SMU Standby */
    PMS_CMD_STDBY.U    = 0x40000001U;
    /* clears the TSTEN, TSTRUN, TSTDONE, TSTOK, SMUERR and PMSERR flags */
    PMS_MONBISTCTRL.U  = 0x40000002U;
    /* Clear the filter */
    PMS_MONFILT.U = 0x20000000U;
    /* Wait until register is updated */
    timeout = 0x1000U;
    while ((PMS_MONFILT.U != 0x20000000U) && (timeout--))
    {};
    /* Activate under voltage and over voltage alarms */
    PMS_MONCTRL.U = 0xa5a5a5U;
    /* Wait until register is updated */
    timeout = 0x1000U;
    while ((PMS_MONCTRL.U != 0xa5a5a5U) && (timeout--))
    {};
    /* corresponding Over-voltage and Under-voltage interrupts are disabled */
    PMS_PMSIEN.U &= ~0x00000FFFU;
    /* Fault Signal reaction on alarms are disabled */
    PMS_AGFSP_STDBY0.U = 0x40000000U;
    PMS_AGFSP_STDBY1.U = 0x40000000U;
    /* FSP0EN and FSP1EN configuration bits are cleared to avoid spurious Error pin activation */
	/* ASCE bit is set and respective alarms are cleared */
    PMS_CMD_STDBY.U |= 0x40000008U;
	PMS_AG_STDBY0.U = 0xFFF0U;
	PMS_CMD_STDBY.U |= 0x40000008U;
	PMS_AG_STDBY1.U = 0x1FFFFU;
    /* Reset the MONFILT register */
    PMS_MONFILT.U = 0x00000000U;
    /* Start MONBIST test */
    PMS_MONBISTCTRL.U = 0x40000001U;

    /* Wait until MONBIST execution is done */
    timeout = 0x1000U;
    while (((PMS_MONBISTSTAT.B.TSTRUN == 1) || (PMS_MONBISTSTAT.B.TSTDONE == 0)) && (timeout--))
    {};

    /* Disable SMU Standby */
    PMS_CMD_STDBY.U    = 0x40000000U;
    IFX_CFG_SSW_SET_SAFETY_ENDINIT();

    Ifx_Ssw_jumpToFunction(&Ifx_Ssw_MonbistCheck);
}

void Ifx_Ssw_MonbistCheck(void)
{
    /* Check for MONBIST error state */
    if ((PMS_MONBISTSTAT.B.TSTOK == 0U) || (PMS_MONBISTSTAT.B.SMUERR == 1U) || (PMS_MONBISTSTAT.B.PMSERR == 1U))
    {
        __debug();
    }

    Ifx_Ssw_jumpBackToLink();
}
#endif

#if (IFX_CFG_SSW_ENABLE_EMEM_INIT == 1U)

void Ifx_Ssw_UnlockEmem(void)
{
    if(SCU_CHIPID.B.EEA == 1U)
    {
      /* Enable EMEM clock */
      EMEM_CLC.U = 0x00000000U;
      /* sync access */
      EMEM_CLC.U;
      /* Disable Lock */
      EMEM_SBRCTR.U = 0x00000002U;
      EMEM_SBRCTR.U = 0x00000006U;
      EMEM_SBRCTR.U = 0x0000000EU;
    }
}
#endif

#if defined(__TASKING__)
#pragma endoptimize
#elif defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
