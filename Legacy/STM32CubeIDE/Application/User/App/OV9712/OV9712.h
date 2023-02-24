/************************************************************************
 *  File: OV9712.h
 *  Group: OV9712 Firmware
 ***********************************************************************/

#ifndef OV9712_h
#define OV9712_h

/************************************************************************
 *                             Includes                      *
 ***********************************************************************/
#include "OV9712_calc.h"
#include "OV9712_regs.h"

#include "platform.h"

/************************************************************************
 *                             Local Types                              *
 ***********************************************************************/
typedef struct
{
  /* Pins */
  GPIO_t
    ENABLE,
    LOW_VOLTAGE,
    POWER_DOWN,
    MASTER_CLOCK;
} OV9712_pins_t;

typedef struct
{
  uint8_t         ADDR;
  I2C_Handle_t  * CAM_I2C_PORT;
  OV9712_pins_t * Pins;
} OV9712_t;

/************************************************************************
 *                             Local Functions                              *
 ***********************************************************************/
void OV9712_Init( OV9712_t *, I2C_Handle_t *, OV9712_pins_t * );
void OV9712_Write( OV9712_t *, uint8_t, uint8_t );
void OV9712_Enable( OV9712_t * );
void OV9712_Disable( OV9712_t * );

typedef struct
{
  void (*Init)( OV9712_t *, I2C_Handle_t *, OV9712_pins_t * );
  void (*Write)( OV9712_t *, uint8_t, uint8_t);
  void (*Enable)(  OV9712_t * );
  void (*Disable)(  OV9712_t * );
} OV9712_functions;

extern OV9712_functions OV9712_Functions;
extern OV9712_pins_t Default_OV9712_Pins;
extern OV9712_t OV9712;

#endif
