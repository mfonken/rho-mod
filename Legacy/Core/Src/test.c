
/*
 * test.c
 *
 *  Created on: Jan 4, 2022
 *      Author: Matthew
 */
#include "test.h"

#define STRIDE 5

#define __RUN_ASSEMBLY__

//__attribute__((naked))
uint32_t test1(
		uint8_t sub_sample,
		uint8_t * capture_address,
		uint16_t capture_length,
		uint8_t thresh_value,
		uint16_t ** p_thresh_address,
		bool * flag_address)
{

	uint16_t * thresh_address = *p_thresh_address;
	register uint32_t working_register = 0;
	register uint32_t capture_offset = 0;

	stopwatch_reset();
	STOPWATCH_START;
#ifndef __RUN_ASSEMBLY__
    while( 1 )
    {
#ifdef __CHECK_FRAME_FLAG__
        working_register = *flag_address;
        if( working_register ) break;
#endif
        working_register = *( capture_address + capture_offset );
        capture_offset += sub_sample;
        if( capture_offset >= capture_length )
        	break;
        if( working_register >= thresh_value )
            *(thresh_address++) = capture_offset;
    }
#else
    __asm volatile
    (
    "capture_start:"                                                           		"\n\t"
#ifdef __CHECK_FRAME_FLAG__
        "ldrb    %[wrk_r], [%[flg_a]]  	@ Load row end flag byte"                   "\n\t"
        "cmp     %[wrk_r], #1         	@ Check if end is reached (set)"            "\n\t"
        "bge     capture_end            @ If so, end"                               "\n\t"
#endif
    	"ldrb 	%[wrk_r], [%[cap_a], %[cap_o]]" 									"\n\t"
        "add    %[cap_o], %[sub_s]    	@ Increment capture index by sub_sample"    "\n\t"
        "cmp    %[cap_o], %[cap_l]     	@ Check if capture reached max width"       "\n\t"
        "bge     capture_end           	@ If so, end"                               "\n\t"

        "cmp     %[wrk_r], %[thr_v]    	@ Compare with threshold value"             "\n\t"
        "blt     capture_start        	@ If less than, continue to next capture"   "\n\t"

        "strh    %[cap_o], [%[thr_a]], #2   @ Store offset word at thresh index"   	"\n\t"
        "b       capture_start        	@ Branch back to next ca pture"             "\n"
    "capture_end:"                                                                 	"\n"
        :
        [thr_a] "+r"(thresh_address)
		:
        [wrk_r] "r"(working_register),
        [sub_s] "r"(sub_sample),
        [cap_a] "r"(capture_address),
        [cap_o] "r"(capture_offset),
        [cap_l] "r"(capture_length),
        [thr_v] "r"(thresh_value),
        [flg_a] "r"(flag_address)
    );
#endif
    STOPWATCH_STOP;
    *p_thresh_address = thresh_address;
    return STOPWATCH_DUR;
}


//__attribute__((naked))
uint32_t test2( const uint16_t rows,
			register uint16_t * thresh_address,
			const register uint16_t * thresh_end,
			const register uint16_t Cx,
			register uint16_t * Dy,
			register uint16_t * Dx_i )
{
    register uint32_t value_register 	= 0;
    register uint16_t * Dx_end          = Dx_i + rows;
	register uint32_t Q_total           = 0;
	register uint32_t Q_prev            = 0;
	register uint16_t Q_left            = 0;
	register uint16_t Q_right           = 0;
//    bool complete = false;

    register uint32_t working_register		= 0;

	stopwatch_reset();
	STOPWATCH_START;
    __asm volatile
    (
    "loop_process:                                                      			\n\t"
        "ldrh    %[val_r], [%[thr_a]], #2 	@ Load next threshold buffer            \n\t"
        "cmp     %[val_r], %[stride] 		@ Is value outside or equal frame width \n\t"
        "bge     row_end        			@ Go to end row                         \n"
    "left_value:                                                        			\n\t"
        "cmp     %[val_r], %[c_x]         	@ If value is right (greater) x centroid\n\t"
        "bgt     right_value    			@ Branch to right quadrant updated      \n\t"
        "add     %[q_lft], #1   			@ Increment left quadrant               \n\t"
        "b       row_update    		 		@ Branch to row map update              \n"
    "right_value:                                                       			\n\t"
        "add     %[q_rgt], #1   			@ Increment right quadrant              \n"
    "row_update:                                                        			\n\t"
    	"lsl 	 %[val_r], #1				@ Double value to match half-word width \n\t"
        "ldrh    %[wrk_r], [%[d_y], %[val_r]]   @ Load word at row map              \n\t"
        "add     %[wrk_r], #1     			@ Increment row map value               \n\t"
        "strh    %[wrk_r], [%[d_y], %[val_r]]   @ Store incremented value           \n\t"
        "b       loop_process   			@ Loop back to start next values        \n"
    "row_end:                                                           \n\t"
        "add     %[q_tot], %[q_lft], %[q_rgt]	@ Add left and right quadrants to total \n\t"
        "uqsub16 %[wrk_r], %[q_tot], %[q_prv]	@ Calculate active pixels in row    \n\t"
        "strh    %[wrk_r], [%[d_x]], #2   	@ Store at next column address          \n\t"
        "cmp     %[d_x], %[d_x_e]         	@ Check if all rows are processed       \n\t"
        "bge     end2          			 	@ If so, end                            \n\t"
        "mov     %[q_prv], %[q_tot]        	@ Move current total px to previous     \n\t"
        "cmp     %[thr_a], %[thr_e]         @ Check for end of threshold buffer     \n\t"
        "bge     end2           			@ If so, end                            \n\t"
        "blt     loop_process   			@ Loop back to start next values        \n"
    "end2:                      			@ End if all rows are processed         \n"
        ::
        [val_r] "r"(value_register),
        [wrk_r] "r"(working_register),
        [thr_a] "r"(thresh_address),
        [thr_e] "r"(thresh_end),
        [c_x] "r"(Cx),
        [d_y] "r"(Dy),
        [d_x] "r"(Dx_i),
        [d_x_e] "r"(Dx_end),
        [q_tot] "r"(Q_total),
        [q_prv] "r"(Q_prev),
        [q_lft] "r"(Q_left),
        [q_rgt] "r"(Q_right),
		[stride] "I" (STRIDE)
    );
    STOPWATCH_STOP;
    return STOPWATCH_DUR;
}
