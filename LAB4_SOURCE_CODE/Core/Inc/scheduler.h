/*
 * scheduler.h
 *
 *  Created on: Nov 22, 2023
 *      Author: hoang
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "stdint.h"
#include "main.h"


#define SCH_MAX_TASKS 40
typedef struct {
	// Pointer to the task (must be a ’ void ( void ) ’ function )
	void (*pTask)(void) ;
	// Delay ( ticks ) until the function w ill ( next ) be run
	uint32_t Delay ;
	// Interval ( ticks ) between subsequent runs .
	uint32_t Period;
	// Incremented ( by scheduler ) when task i s due to execute
	uint8_t RunMe;
	// This i s a hint to solve the question below .
	uint32_t TaskID ;
} sTask;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task(void(*pFunction)(), uint32_t Delay, uint32_t Period);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task ( uint32_t TASK_INDEX );

extern sTask SCH_tasks[SCH_MAX_TASKS];
extern int current_index_task;
#endif /* INC_SCHEDULER_H_ */
