#ifndef TIMER_CONFG_H
#define TIMER_CONFG_H

#define CTC               1
#define NORMAL            2
#define STOP_PRESCALLER   0
#define PRESCALLER_1      1
#define PRESCALLER_8      8
#define PRESCALLER_64     64
#define PRESCALLER_256    256
#define FALLING_EDGE      1024
#define RISING_EDGE       2048
#define NULL              0

#define counter  count

/* OPTION SELECT PRESCALLER [STOP_PRESCALLER , PRESCALLER_1 , PRESCALLER_8 ,
 *  PRESCALLER_64 , PRESCALLER_256 , RISING_EDGE , FALLING_EDGE  ]   */

#define PRESCALLER    PRESCALLER_256

/* OpTION SELECT MODE [NORMAL , CTC] */

#define MODE         NORMAL

#endif
