/************************************************************************
 *  File: stm32_interface.c
 *  Group: Rho Hardware Interface
 ***********************************************************************/

/************************************************************************
 *                             Includes                                 *
 ***********************************************************************/
#include <platform_interface/stm32_interface.h>

/************************************************************************
 *                             Master Instance                          *
 ***********************************************************************/
master_t Master;

/************************************************************************
 *                           Interrupt Handlers                         *
 ***********************************************************************/
inline void STM_InterruptHandler( uint16_t GPIO_Pin )
{
//#ifdef __RHO__
//	if(!CameraFlags.IRQ) return;
	if(GPIO_Pin == VSYNC_Pin)
		CameraFlags.Frame = !(flag_t)( VSYNC_GPIO_Port->IDR & VSYNC_Pin );
	else if( GPIO_Pin == HREF_Pin)
	{
		CameraFlags.Row = (flag_t)( HREF_GPIO_Port->IDR & HREF_Pin );
		if(!CameraFlags.Row)
			HAL_PWR_DisableSleepOnExit();
	}
        /* Row capture is callback connected on HREF=HIGH */
//        if( !CameraFlags.Row
//         && CameraFlags.Capture.Flag )
////         && CameraFlags.Capture.Callback != NULL )
//        {
////            CameraFlags.Capture.Callback();
//        }
//        break;

//  if(!CameraFlags.Row || CameraFlags.Frame )
//  {
//    LOG(ALWAYS, "0x%08x", Master.Utilities.Timer_Primary->hdma[RHO_TIM_DMA_ID]->Instance->CNDTR );
//    HAL_DMA_Abort(Master.Utilities.Timer_Primary->hdma[RHO_TIM_DMA_ID]);
//    STM_InitDMA( (uint32_t)&CAMERA_PORT, _dma_destination, _dma_size, true );
//    LOG(ALWAYS, "0x%08x", Master.Utilities.Timer_Primary->hdma[RHO_TIM_DMA_ID]->Instance->CNDTR );
//    LOG(ALWAYS, ENDL);
//  }
//#endif/* EXTI line interrupt detected */
}
void STM_InterruptEnable( void )
{
//  STM_ResumeDMA(RHO_TIM_IT_CC, RHO_TIM_CHANNEL);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}
void STM_InterruptDisable( void )
{
//  STM_PauseDMA(RHO_TIM_IT_CC, RHO_TIM_CHANNEL);
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
  HAL_NVIC_DisableIRQ(EXTI3_IRQn);
}

/************************************************************************
 *                              DMA Handlers                            *
 ***********************************************************************/
inline void STM_PauseDMA( dma_info_t * info )
{
  __HAL_TIM_DISABLE_IT(Master.Utilities.Timer_Primary, info->it_cc);
  TIM_CCxChannelCmd(Master.Utilities.Timer_Primary->Instance, info->tim_ch, TIM_CCx_DISABLE);
}
inline void STM_ResumeDMA( dma_info_t * info )
{
  __HAL_TIM_ENABLE_IT(Master.Utilities.Timer_Primary, info->it_cc );
  TIM_CCxChannelCmd(Master.Utilities.Timer_Primary->Instance, info->tim_ch, TIM_CCx_ENABLE);
}
inline void STM_ResetDMA( dma_info_t * info )
{
    if(info->dst != (uint32_t)NULL)
        Master.Utilities.Timer_Primary->hdma[info->id]->Instance->CMAR = info->dst;
}
void STM_InitDMA( dma_info_t * info )
{
  if(HAL_DMA_Start_IT(Master.Utilities.Timer_Primary->hdma[info->id], info->src, info->dst, info->size) != HAL_OK)
    Error_Handler();
  __HAL_TIM_ENABLE_DMA(Master.Utilities.Timer_Primary, info->cc);
  if(info->state)
	  STM_ResumeDMA(info);
}
uint32_t STM_GetDMAFillAddress( dma_info_t * info )
{
  return info->dst + ( (int32_t)info->size - (int32_t)Master.Utilities.Timer_Primary->hdma[info->id]->Instance->CNDTR );
}

/************************************************************************
 *                             UART Handlers                            *
 ***********************************************************************/
inline uint8_t STM_UartTxDMA( UART_Handle_t * huart, uint8_t * buffer, uint16_t length )
{
	uint8_t ret;
	do
	{
		ret = HAL_UART_Transmit_DMA( Master.IOs.UART_Primary, buffer, length);
	} while(ret == HAL_BUSY);
	return ret;//( Master.IOs.UART_Primary, buffer, length);//, UART_TIMEOUT );
}

inline uint16_t STM_UartRxDMA( UART_Handle_t * huart, uint8_t * buffer )
{
  ///TODO: Actually implement
  return 1;
}
//inline bool STM_UartCompleted( UART_Handle_t * huart )
//{
//#ifdef __RHO__
//  Platform.CameraFlags.UARTBusy = 0;
//#endif
//  return false;
//}

/************************************************************************
 *                              I2C Handlers                            *
 ***********************************************************************/
inline void STM_I2CMasterTx( I2C_Handle_t * hi2c, uint16_t addr, uint8_t * buffer, uint16_t length, uint32_t timeout )
{
  HAL_I2C_Master_Transmit( hi2c, addr, buffer, length, timeout);
}

/************************************************************************
 *                             GPIO Handlers                            *
 ***********************************************************************/
inline void STM_SetPortMode( GPIO_TypeDef * port, uint16_t pin, uint8_t mode )
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = pin;
  GPIO_InitStruct.Mode = mode;
  HAL_GPIO_Init( (GPIO_TypeDef *)port, &GPIO_InitStruct );
}
inline uint8_t STM_ReadPort( GPIO_TypeDef * port )
{
    return port->IDR;
}
inline void STM_WritePin( GPIO_TypeDef * port, uint16_t pin, uint8_t state )
{
  HAL_GPIO_WritePin( port, pin, (GPIO_PinState)state);
}
inline void STM_TogglePin( GPIO_TypeDef * port, uint16_t pin )
{
  HAL_GPIO_TogglePin( port, pin );
}

/************************************************************************
 *                             Time Handlers                            *
 ***********************************************************************/
inline uint32_t STM_Timestamp(void)
{
  return HAL_GetTick();
}
inline void STM_Wait( uint32_t nTime )
{
  HAL_Delay( nTime );
}
inline uint32_t STM_SysClockFreq(void)
{
  return HAL_RCC_GetSysClockFreq();
}

/************************************************************************
 *                            System Handlers                           *
 ***********************************************************************/
void STM_Reset( void )
{
    NVIC_SystemReset();
}
