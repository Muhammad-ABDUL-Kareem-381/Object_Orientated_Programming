#include "SchedulerApp.h"
void SchedulerApp::startApp()
{
	Scheduler o1;
	o1.reSize(3);
	o1.addTask(Task{ Date {2,8,2024}, Time{13,30,0},String {"go to Anarkali"} });
	o1.displayTodaysTasks();
}