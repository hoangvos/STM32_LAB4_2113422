/*
 * scheduler.c
 *
 *  Created on: Nov 22, 2023
 *      Author: hoang
 */
#include "scheduler.h"
#include <stdio.h>
sTask SCH_tasks[SCH_MAX_TASKS];
int current_index_task = 0;


void SCH_Init(void){
	current_index_task = 0;
}
void SCH_Add_Task(void(*pFunction)(), uint32_t Delay, uint32_t Period){
	if(current_index_task == SCH_MAX_TASKS) return;
	int index = 0;
	while(index < current_index_task && Delay >= SCH_tasks[index].Delay){
		Delay -= SCH_tasks[index].Delay;
		index++;
	}
	for(int i = current_index_task; i > index; i--){
		SCH_tasks[i].pTask = SCH_tasks[i - 1].pTask;
		SCH_tasks[i].Delay = SCH_tasks[i - 1].Delay;
		SCH_tasks[i].Period = SCH_tasks[i - 1].Period;
		SCH_tasks[i].RunMe = SCH_tasks[i - 1].RunMe;
		SCH_tasks[i].TaskID = i;
	}
	if(index != current_index_task){
		SCH_tasks[index + 1].Delay -= Delay;
	}
	SCH_tasks[index].pTask = pFunction;
	SCH_tasks[index].Delay = Delay;
	SCH_tasks[index].Period = Period;
	SCH_tasks[index].RunMe = 0;
	SCH_tasks[index].TaskID = index;
	current_index_task++;
}
void SCH_Update(void){
	if(current_index_task == 0) return;
	if(SCH_tasks[0].Delay > 0){
		SCH_tasks[0].Delay--;
	}
	else{
		SCH_tasks[0].RunMe++;
	}
}
void SCH_Dispatch_Tasks(void){
	if(SCH_tasks[0].RunMe > 0){
		(*SCH_tasks[0].pTask)();
		void (*tmp_func)(void) = SCH_tasks[0].pTask;
		uint32_t tmp_period = SCH_tasks[0].Period;
		SCH_Delete_Task(0);
		if(tmp_period == 0){
			return;
		}
		SCH_Add_Task(tmp_func, tmp_period, tmp_period);
	}
}
void SCH_Delete_Task(uint32_t TASK_INDEX){
	for(int i = TASK_INDEX + 1; i < current_index_task; i++ ){
		SCH_tasks[i-1].pTask = SCH_tasks[i].pTask;
		SCH_tasks[i-1].Delay = SCH_tasks[i].Delay;
		SCH_tasks[i-1].Period = SCH_tasks[i].Period;
		SCH_tasks[i-1].RunMe = SCH_tasks[i].RunMe;
		SCH_tasks[i-1].TaskID = i - 1;
	}
	current_index_task--;
}









