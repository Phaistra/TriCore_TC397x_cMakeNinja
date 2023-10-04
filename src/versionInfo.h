/* **************************************
	File Name: Generated version Info
	File Generated: 2023-10-02 : 18:04:42
*************************************** */
#ifndef _VERSION_INFO_H_
#define _VERSION_INFO_H_

/* **************************************
	#defines
*************************************** */


/* **************************************
	Declarations
*************************************** */
#define APP_NAME "NinjaCmakeTaskingTriCoreProject"


/* SW Version */
#define RELEASE_VERSION "1.0.0.0"
#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define PATCH_VERSION 0
#define REVISION 0

/* Git Tags */
#define GIT_BUILD_VERSION b73eefd
#define GIT_BUILD_VERSION_TAG "b73eefd"

/* Data about system which compiled this file */
#define ARCH Generic-ELF
#define COMP tricore
#define BUILD_TYPE Debug 
#define BUILD_ROOT_DIR "C:/dev/refProj_tc397x"

/* CMake Data */
#define APP_BUILD_WITH_CMAKE_VERSION "3.27.1"
#define COMPILER "Tasking"
#define CMAKE_COMPILER_VERSION "6.3r1"
#define APP_BUILD_ON_PLATFORM "Generic-ELF"


/* Timestamps */
#define PROJ_GENERATED_TIMESTAMP "2023-10-02T18:04:42"
#define PROJ_GENERATED_PRETTY_TIMESTAMP "2023-10-02 : 18:04:42"
/* ********************************************************
	Build Stuff
	===========
	CMAKE_C_FLAGS         = --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc39xb -Y0 -N0 -Z0

	CMAKE_C_FLAGS_DEBUG   = -O0 -g

	CMAKE_C_FLAGS_RELEASE = -O2 -DNDEBUG

	COMMON_LINKER_FLAGS   = -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.s19:SREC:4 -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.hex:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:SREC:4 -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1

	CMAKE_EXE_LINKER_FLAGS_DEBUG          = -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.s19:SREC:4 -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.hex:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:SREC:4 -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1 -O1 -dC:/dev/refProj_tc397x/vendor/linkerscript/Lcf_Tasking_Tricore_Tc.lsl

	CMAKE_EXE_LINKER_FLAGS_RELEASE        = -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.s19:SREC:4 -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.hex:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:SREC:4 -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1 -O2 -dC:/dev/refProj_tc397x/vendor/linkerscript/Lcf_Tasking_Tricore_Tc.lsl

	CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO = -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.s19:SREC:4 -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.hex:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:SREC:4 -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1 -O1 -dC:/dev/refProj_tc397x/vendor/linkerscript/Lcf_Tasking_Tricore_Tc.lsl

	CMAKE_EXE_LINKER_FLAGS_MINSIZEREL     = -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++  -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.s19:SREC:4 -Wl--output=bin/NinjaCmakeTaskingTriCoreProject.hex:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:IHEX:4 --chip-output=bin/flash/NinjaCmakeTaskingTriCoreProject:SREC:4 -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=1 -O2 -dC:/dev/refProj_tc397x/vendor/linkerscript/Lcf_Tasking_Tricore_Tc.lsl	
	
	

	COMPILE_DEFINITIONS = 
	
	INC DIRS = vendor/Configurations;vendor/iLLD;vendor/Infra;vendor/linkerscript;vendor/Service;vendor/Configurations/Debug;vendor/iLLD/TC39B;vendor/iLLD/TC39B/Tricore;vendor/iLLD/TC39B/Tricore/Asclin;vendor/iLLD/TC39B/Tricore/Can;vendor/iLLD/TC39B/Tricore/Ccu6;vendor/iLLD/TC39B/Tricore/Convctrl;vendor/iLLD/TC39B/Tricore/Cpu;vendor/iLLD/TC39B/Tricore/Dma;vendor/iLLD/TC39B/Tricore/Dts;vendor/iLLD/TC39B/Tricore/Ebu;vendor/iLLD/TC39B/Tricore/Edsadc;vendor/iLLD/TC39B/Tricore/Emem;vendor/iLLD/TC39B/Tricore/Eray;vendor/iLLD/TC39B/Tricore/Evadc;vendor/iLLD/TC39B/Tricore/Fce;vendor/iLLD/TC39B/Tricore/Flash;vendor/iLLD/TC39B/Tricore/Geth;vendor/iLLD/TC39B/Tricore/Gpt12;vendor/iLLD/TC39B/Tricore/Gtm;vendor/iLLD/TC39B/Tricore/Hspdm;vendor/iLLD/TC39B/Tricore/Hssl;vendor/iLLD/TC39B/Tricore/I2c;vendor/iLLD/TC39B/Tricore/Iom;vendor/iLLD/TC39B/Tricore/Msc;vendor/iLLD/TC39B/Tricore/Mtu;vendor/iLLD/TC39B/Tricore/Pms;vendor/iLLD/TC39B/Tricore/Port;vendor/iLLD/TC39B/Tricore/Psi5;vendor/iLLD/TC39B/Tricore/Psi5s;vendor/iLLD/TC39B/Tricore/Qspi;vendor/iLLD/TC39B/Tricore/Rif;vendor/iLLD/TC39B/Tricore/Scu;vendor/iLLD/TC39B/Tricore/Sdmmc;vendor/iLLD/TC39B/Tricore/Sent;vendor/iLLD/TC39B/Tricore/Smu;vendor/iLLD/TC39B/Tricore/Spu;vendor/iLLD/TC39B/Tricore/Src;vendor/iLLD/TC39B/Tricore/Stm;vendor/iLLD/TC39B/Tricore/_Build;vendor/iLLD/TC39B/Tricore/_Impl;vendor/iLLD/TC39B/Tricore/_Lib;vendor/iLLD/TC39B/Tricore/_PinMap;vendor/iLLD/TC39B/Tricore/Asclin/Asc;vendor/iLLD/TC39B/Tricore/Asclin/Lin;vendor/iLLD/TC39B/Tricore/Asclin/Spi;vendor/iLLD/TC39B/Tricore/Asclin/Std;vendor/iLLD/TC39B/Tricore/Can/Can;vendor/iLLD/TC39B/Tricore/Can/Std;vendor/iLLD/TC39B/Tricore/Ccu6/Icu;vendor/iLLD/TC39B/Tricore/Ccu6/PwmBc;vendor/iLLD/TC39B/Tricore/Ccu6/PwmHl;vendor/iLLD/TC39B/Tricore/Ccu6/Std;vendor/iLLD/TC39B/Tricore/Ccu6/Timer;vendor/iLLD/TC39B/Tricore/Ccu6/TimerWithTrigger;vendor/iLLD/TC39B/Tricore/Ccu6/TPwm;vendor/iLLD/TC39B/Tricore/Convctrl/Std;vendor/iLLD/TC39B/Tricore/Cpu/Irq;vendor/iLLD/TC39B/Tricore/Cpu/Std;vendor/iLLD/TC39B/Tricore/Cpu/Trap;vendor/iLLD/TC39B/Tricore/Dma/Dma;vendor/iLLD/TC39B/Tricore/Dma/Std;vendor/iLLD/TC39B/Tricore/Dts/Dts;vendor/iLLD/TC39B/Tricore/Dts/Std;vendor/iLLD/TC39B/Tricore/Ebu/BFlashSpansion;vendor/iLLD/TC39B/Tricore/Ebu/BFlashSt;vendor/iLLD/TC39B/Tricore/Ebu/Dram;vendor/iLLD/TC39B/Tricore/Ebu/Sram;vendor/iLLD/TC39B/Tricore/Ebu/Std;vendor/iLLD/TC39B/Tricore/Edsadc/Edsadc;vendor/iLLD/TC39B/Tricore/Edsadc/Std;vendor/iLLD/TC39B/Tricore/Emem/Std;vendor/iLLD/TC39B/Tricore/Eray/Eray;vendor/iLLD/TC39B/Tricore/Eray/Std;vendor/iLLD/TC39B/Tricore/Evadc/Adc;vendor/iLLD/TC39B/Tricore/Evadc/Std;vendor/iLLD/TC39B/Tricore/Fce/Crc;vendor/iLLD/TC39B/Tricore/Fce/Std;vendor/iLLD/TC39B/Tricore/Flash/Std;vendor/iLLD/TC39B/Tricore/Geth/Eth;vendor/iLLD/TC39B/Tricore/Geth/Std;vendor/iLLD/TC39B/Tricore/Gpt12/IncrEnc;vendor/iLLD/TC39B/Tricore/Gpt12/Std;vendor/iLLD/TC39B/Tricore/Gtm/Atom;vendor/iLLD/TC39B/Tricore/Gtm/Pwm;vendor/iLLD/TC39B/Tricore/Gtm/Std;vendor/iLLD/TC39B/Tricore/Gtm/Tim;vendor/iLLD/TC39B/Tricore/Gtm/Tom;vendor/iLLD/TC39B/Tricore/Gtm/Trig;vendor/iLLD/TC39B/Tricore/Gtm/Atom/Dtm_PwmHl;vendor/iLLD/TC39B/Tricore/Gtm/Atom/Pwm;vendor/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl;vendor/iLLD/TC39B/Tricore/Gtm/Atom/Timer;vendor/iLLD/TC39B/Tricore/Gtm/Tim/In;vendor/iLLD/TC39B/Tricore/Gtm/Tim/Timer;vendor/iLLD/TC39B/Tricore/Gtm/Tom/Dtm_PwmHl;vendor/iLLD/TC39B/Tricore/Gtm/Tom/Pwm;vendor/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl;vendor/iLLD/TC39B/Tricore/Gtm/Tom/Timer;vendor/iLLD/TC39B/Tricore/Hspdm/Std;vendor/iLLD/TC39B/Tricore/Hssl/Hssl;vendor/iLLD/TC39B/Tricore/Hssl/Std;vendor/iLLD/TC39B/Tricore/I2c/I2c;vendor/iLLD/TC39B/Tricore/I2c/Std;vendor/iLLD/TC39B/Tricore/Iom/Driver;vendor/iLLD/TC39B/Tricore/Iom/Iom;vendor/iLLD/TC39B/Tricore/Iom/Std;vendor/iLLD/TC39B/Tricore/Msc/Msc;vendor/iLLD/TC39B/Tricore/Msc/Std;vendor/iLLD/TC39B/Tricore/Mtu/Std;vendor/iLLD/TC39B/Tricore/Pms/Std;vendor/iLLD/TC39B/Tricore/Port/Io;vendor/iLLD/TC39B/Tricore/Port/Std;vendor/iLLD/TC39B/Tricore/Psi5/Psi5;vendor/iLLD/TC39B/Tricore/Psi5/Std;vendor/iLLD/TC39B/Tricore/Psi5s/Psi5s;vendor/iLLD/TC39B/Tricore/Psi5s/Std;vendor/iLLD/TC39B/Tricore/Qspi/SpiMaster;vendor/iLLD/TC39B/Tricore/Qspi/SpiSlave;vendor/iLLD/TC39B/Tricore/Qspi/Std;vendor/iLLD/TC39B/Tricore/Rif/Rif;vendor/iLLD/TC39B/Tricore/Rif/Std;vendor/iLLD/TC39B/Tricore/Scu/Std;vendor/iLLD/TC39B/Tricore/Sdmmc/Emmc;vendor/iLLD/TC39B/Tricore/Sdmmc/Sd;vendor/iLLD/TC39B/Tricore/Sdmmc/Std;vendor/iLLD/TC39B/Tricore/Sent/Sent;vendor/iLLD/TC39B/Tricore/Sent/Std;vendor/iLLD/TC39B/Tricore/Smu/Smu;vendor/iLLD/TC39B/Tricore/Smu/Std;vendor/iLLD/TC39B/Tricore/Spu/Std;vendor/iLLD/TC39B/Tricore/Src/Std;vendor/iLLD/TC39B/Tricore/Stm/Std;vendor/iLLD/TC39B/Tricore/Stm/Timer;vendor/iLLD/TC39B/Tricore/_Lib/DataHandling;vendor/iLLD/TC39B/Tricore/_Lib/InternalMux;vendor/Infra/Platform;vendor/Infra/Sfr;vendor/Infra/Ssw;vendor/Infra/Platform/Tricore;vendor/Infra/Platform/Tricore/Compilers;vendor/Infra/Sfr/TC39B;vendor/Infra/Sfr/TC39B/_Reg;vendor/Infra/Ssw/TC39B;vendor/Infra/Ssw/TC39B/Tricore;vendor/Service/CpuGeneric;vendor/Service/CpuGeneric/If;vendor/Service/CpuGeneric/StdIf;vendor/Service/CpuGeneric/SysSe;vendor/Service/CpuGeneric/_Utilities;vendor/Service/CpuGeneric/If/Ccu6If;vendor/Service/CpuGeneric/SysSe/Bsp;vendor/Service/CpuGeneric/SysSe/Comm;vendor/Service/CpuGeneric/SysSe/General;vendor/Service/CpuGeneric/SysSe/Math;vendor/Service/CpuGeneric/SysSe/Time

	INC DIRS = vendor/Configurations;
	vendor/iLLD;
	vendor/Infra;
	vendor/linkerscript;
	vendor/Service;
	vendor/Configurations/Debug;
	vendor/iLLD/TC39B;
	vendor/iLLD/TC39B/Tricore;
	vendor/iLLD/TC39B/Tricore/Asclin;
	vendor/iLLD/TC39B/Tricore/Can;
	vendor/iLLD/TC39B/Tricore/Ccu6;
	vendor/iLLD/TC39B/Tricore/Convctrl;
	vendor/iLLD/TC39B/Tricore/Cpu;
	vendor/iLLD/TC39B/Tricore/Dma;
	vendor/iLLD/TC39B/Tricore/Dts;
	vendor/iLLD/TC39B/Tricore/Ebu;
	vendor/iLLD/TC39B/Tricore/Edsadc;
	vendor/iLLD/TC39B/Tricore/Emem;
	vendor/iLLD/TC39B/Tricore/Eray;
	vendor/iLLD/TC39B/Tricore/Evadc;
	vendor/iLLD/TC39B/Tricore/Fce;
	vendor/iLLD/TC39B/Tricore/Flash;
	vendor/iLLD/TC39B/Tricore/Geth;
	vendor/iLLD/TC39B/Tricore/Gpt12;
	vendor/iLLD/TC39B/Tricore/Gtm;
	vendor/iLLD/TC39B/Tricore/Hspdm;
	vendor/iLLD/TC39B/Tricore/Hssl;
	vendor/iLLD/TC39B/Tricore/I2c;
	vendor/iLLD/TC39B/Tricore/Iom;
	vendor/iLLD/TC39B/Tricore/Msc;
	vendor/iLLD/TC39B/Tricore/Mtu;
	vendor/iLLD/TC39B/Tricore/Pms;
	vendor/iLLD/TC39B/Tricore/Port;
	vendor/iLLD/TC39B/Tricore/Psi5;
	vendor/iLLD/TC39B/Tricore/Psi5s;
	vendor/iLLD/TC39B/Tricore/Qspi;
	vendor/iLLD/TC39B/Tricore/Rif;
	vendor/iLLD/TC39B/Tricore/Scu;
	vendor/iLLD/TC39B/Tricore/Sdmmc;
	vendor/iLLD/TC39B/Tricore/Sent;
	vendor/iLLD/TC39B/Tricore/Smu;
	vendor/iLLD/TC39B/Tricore/Spu;
	vendor/iLLD/TC39B/Tricore/Src;
	vendor/iLLD/TC39B/Tricore/Stm;
	vendor/iLLD/TC39B/Tricore/_Build;
	vendor/iLLD/TC39B/Tricore/_Impl;
	vendor/iLLD/TC39B/Tricore/_Lib;
	vendor/iLLD/TC39B/Tricore/_PinMap;
	vendor/iLLD/TC39B/Tricore/Asclin/Asc;
	vendor/iLLD/TC39B/Tricore/Asclin/Lin;
	vendor/iLLD/TC39B/Tricore/Asclin/Spi;
	vendor/iLLD/TC39B/Tricore/Asclin/Std;
	vendor/iLLD/TC39B/Tricore/Can/Can;
	vendor/iLLD/TC39B/Tricore/Can/Std;
	vendor/iLLD/TC39B/Tricore/Ccu6/Icu;
	vendor/iLLD/TC39B/Tricore/Ccu6/PwmBc;
	vendor/iLLD/TC39B/Tricore/Ccu6/PwmHl;
	vendor/iLLD/TC39B/Tricore/Ccu6/Std;
	vendor/iLLD/TC39B/Tricore/Ccu6/Timer;
	vendor/iLLD/TC39B/Tricore/Ccu6/TimerWithTrigger;
	vendor/iLLD/TC39B/Tricore/Ccu6/TPwm;
	vendor/iLLD/TC39B/Tricore/Convctrl/Std;
	vendor/iLLD/TC39B/Tricore/Cpu/Irq;
	vendor/iLLD/TC39B/Tricore/Cpu/Std;
	vendor/iLLD/TC39B/Tricore/Cpu/Trap;
	vendor/iLLD/TC39B/Tricore/Dma/Dma;
	vendor/iLLD/TC39B/Tricore/Dma/Std;
	vendor/iLLD/TC39B/Tricore/Dts/Dts;
	vendor/iLLD/TC39B/Tricore/Dts/Std;
	vendor/iLLD/TC39B/Tricore/Ebu/BFlashSpansion;
	vendor/iLLD/TC39B/Tricore/Ebu/BFlashSt;
	vendor/iLLD/TC39B/Tricore/Ebu/Dram;
	vendor/iLLD/TC39B/Tricore/Ebu/Sram;
	vendor/iLLD/TC39B/Tricore/Ebu/Std;
	vendor/iLLD/TC39B/Tricore/Edsadc/Edsadc;
	vendor/iLLD/TC39B/Tricore/Edsadc/Std;
	vendor/iLLD/TC39B/Tricore/Emem/Std;
	vendor/iLLD/TC39B/Tricore/Eray/Eray;
	vendor/iLLD/TC39B/Tricore/Eray/Std;
	vendor/iLLD/TC39B/Tricore/Evadc/Adc;
	vendor/iLLD/TC39B/Tricore/Evadc/Std;
	vendor/iLLD/TC39B/Tricore/Fce/Crc;
	vendor/iLLD/TC39B/Tricore/Fce/Std;
	vendor/iLLD/TC39B/Tricore/Flash/Std;
	vendor/iLLD/TC39B/Tricore/Geth/Eth;
	vendor/iLLD/TC39B/Tricore/Geth/Std;
	vendor/iLLD/TC39B/Tricore/Gpt12/IncrEnc;
	vendor/iLLD/TC39B/Tricore/Gpt12/Std;
	vendor/iLLD/TC39B/Tricore/Gtm/Atom;
	vendor/iLLD/TC39B/Tricore/Gtm/Pwm;
	vendor/iLLD/TC39B/Tricore/Gtm/Std;
	vendor/iLLD/TC39B/Tricore/Gtm/Tim;
	vendor/iLLD/TC39B/Tricore/Gtm/Tom;
	vendor/iLLD/TC39B/Tricore/Gtm/Trig;
	vendor/iLLD/TC39B/Tricore/Gtm/Atom/Dtm_PwmHl;
	vendor/iLLD/TC39B/Tricore/Gtm/Atom/Pwm;
	vendor/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl;
	vendor/iLLD/TC39B/Tricore/Gtm/Atom/Timer;
	vendor/iLLD/TC39B/Tricore/Gtm/Tim/In;
	vendor/iLLD/TC39B/Tricore/Gtm/Tim/Timer;
	vendor/iLLD/TC39B/Tricore/Gtm/Tom/Dtm_PwmHl;
	vendor/iLLD/TC39B/Tricore/Gtm/Tom/Pwm;
	vendor/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl;
	vendor/iLLD/TC39B/Tricore/Gtm/Tom/Timer;
	vendor/iLLD/TC39B/Tricore/Hspdm/Std;
	vendor/iLLD/TC39B/Tricore/Hssl/Hssl;
	vendor/iLLD/TC39B/Tricore/Hssl/Std;
	vendor/iLLD/TC39B/Tricore/I2c/I2c;
	vendor/iLLD/TC39B/Tricore/I2c/Std;
	vendor/iLLD/TC39B/Tricore/Iom/Driver;
	vendor/iLLD/TC39B/Tricore/Iom/Iom;
	vendor/iLLD/TC39B/Tricore/Iom/Std;
	vendor/iLLD/TC39B/Tricore/Msc/Msc;
	vendor/iLLD/TC39B/Tricore/Msc/Std;
	vendor/iLLD/TC39B/Tricore/Mtu/Std;
	vendor/iLLD/TC39B/Tricore/Pms/Std;
	vendor/iLLD/TC39B/Tricore/Port/Io;
	vendor/iLLD/TC39B/Tricore/Port/Std;
	vendor/iLLD/TC39B/Tricore/Psi5/Psi5;
	vendor/iLLD/TC39B/Tricore/Psi5/Std;
	vendor/iLLD/TC39B/Tricore/Psi5s/Psi5s;
	vendor/iLLD/TC39B/Tricore/Psi5s/Std;
	vendor/iLLD/TC39B/Tricore/Qspi/SpiMaster;
	vendor/iLLD/TC39B/Tricore/Qspi/SpiSlave;
	vendor/iLLD/TC39B/Tricore/Qspi/Std;
	vendor/iLLD/TC39B/Tricore/Rif/Rif;
	vendor/iLLD/TC39B/Tricore/Rif/Std;
	vendor/iLLD/TC39B/Tricore/Scu/Std;
	vendor/iLLD/TC39B/Tricore/Sdmmc/Emmc;
	vendor/iLLD/TC39B/Tricore/Sdmmc/Sd;
	vendor/iLLD/TC39B/Tricore/Sdmmc/Std;
	vendor/iLLD/TC39B/Tricore/Sent/Sent;
	vendor/iLLD/TC39B/Tricore/Sent/Std;
	vendor/iLLD/TC39B/Tricore/Smu/Smu;
	vendor/iLLD/TC39B/Tricore/Smu/Std;
	vendor/iLLD/TC39B/Tricore/Spu/Std;
	vendor/iLLD/TC39B/Tricore/Src/Std;
	vendor/iLLD/TC39B/Tricore/Stm/Std;
	vendor/iLLD/TC39B/Tricore/Stm/Timer;
	vendor/iLLD/TC39B/Tricore/_Lib/DataHandling;
	vendor/iLLD/TC39B/Tricore/_Lib/InternalMux;
	vendor/Infra/Platform;
	vendor/Infra/Sfr;
	vendor/Infra/Ssw;
	vendor/Infra/Platform/Tricore;
	vendor/Infra/Platform/Tricore/Compilers;
	vendor/Infra/Sfr/TC39B;
	vendor/Infra/Sfr/TC39B/_Reg;
	vendor/Infra/Ssw/TC39B;
	vendor/Infra/Ssw/TC39B/Tricore;
	vendor/Service/CpuGeneric;
	vendor/Service/CpuGeneric/If;
	vendor/Service/CpuGeneric/StdIf;
	vendor/Service/CpuGeneric/SysSe;
	vendor/Service/CpuGeneric/_Utilities;
	vendor/Service/CpuGeneric/If/Ccu6If;
	vendor/Service/CpuGeneric/SysSe/Bsp;
	vendor/Service/CpuGeneric/SysSe/Comm;
	vendor/Service/CpuGeneric/SysSe/General;
	vendor/Service/CpuGeneric/SysSe/Math;
	vendor/Service/CpuGeneric/SysSe/Time
******************************************************** */
/* **************************************
	Extras
*************************************** */


#endif
