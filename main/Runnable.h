/*
 * Runnable.h
 *
 *  Created on: Jul 11, 2017
 *      Author: Royce
 */

#ifndef MAIN_RUNNABLE_H_
#define MAIN_RUNNABLE_H_

class Task;


class Runnable
{
public:
	virtual void run(Task*) = 0;
};


#endif /* MAIN_RUNNABLE_H_ */
