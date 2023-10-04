#include "board_init.h"
/* **************************************
	File Name: Board Init
*************************************** */
#include "board_init.h"
#include "IfxGpt12.h"
/* **************************************
	#defines
*************************************** */

#define RELOAD_VALUE_1MS            6250    /** 1ms --> 100MHz / (8 *2 * 100) = 6250 */
#define ISR_PRIORITY_GPT12_TIMER    6

/* **************************************
	Declarations
*************************************** */


static void initGpt12Timer(void);
/* **************************************
	Code
*************************************** */


void board_init(void) {
	// Init your HW here
}
