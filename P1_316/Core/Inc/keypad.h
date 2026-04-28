/*
 * keypad.h
 *
 *  Created on: Apr 27, 2026
 *      Author: thodo
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_


#include <stdint.h>

#define KEYPAD_NO_KEY   ((char)0)
#define KEYPAD_STAR     '*'
#define KEYPAD_POUND    '#'

void Keypad_Init(void);
char Keypad_GetKey(void);



#endif /* INC_KEYPAD_H_ */
