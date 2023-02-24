/************************************************************************
 *  File: master.h
 *  Group: Rho Core
 ***********************************************************************/

#ifndef MASTER_H_
#define MASTER_H_
/***************************************************************************************/
/*                                    Includes                                         */
/***************************************************************************************/
#include "app.h"

/***************************************************************************************/
/*                              Function Definitions                                   */
/***************************************************************************************/
void Master_Connect( I2C_Handle_t *, TIMER_Handle_t *, UART_Handle_t * );
void Master_Init( void );
void Master_Run( void );

/***************************************************************************************/
/*                              Function Structures                                    */
/***************************************************************************************/
typedef struct
{
  void (*Connect)( I2C_Handle_t *, TIMER_Handle_t *, UART_Handle_t * );
  void (*Init)( void );
  void (*Run)( void );
} master_functions_t;

static master_functions_t MasterFunctions =
{
  .Connect = Master_Connect,
  .Init    = Master_Init,
  .Run     = Master_Run
};

/***************************************************************************************/
/*                                  Routines Definitions                               */
/***************************************************************************************/
void InitializePlatform( void );
void ConnectToHost( void );
void ConfigureApplication( void );
void ExitInitialization( void );
void ApplicationCore( void );
void SystemError( void );

/***************************************************************************************/
/*                                Core State List                                      */
/***************************************************************************************/
extern system_states_list_t global_states_list;

#endif /* MASTER_H_ */
