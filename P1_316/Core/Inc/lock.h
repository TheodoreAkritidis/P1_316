/*
 * lock.h
 *
 *  Created on: Apr 27, 2026
 *      Author: thodo
 */

#ifndef INC_LOCK_H_
#define INC_LOCK_H_


#include <stdint.h>

#define LOCK_PIN_LENGTH 4

typedef enum {
    LOCKED = 0,
    UNLOCKED = 1
} lock_state_t;

void Lock_Init(void);
lock_state_t Lock_GetState(void);
void Lock_SetState(lock_state_t state);

void Lock_ClearEntry(void);
uint8_t Lock_AddKey(char key);
uint8_t Lock_CheckEntry(void);

void Lock_StartPinChange(void);
uint8_t Lock_PinChangeMode(void);
uint8_t Lock_SaveNewPin(void);



#endif /* INC_LOCK_H_ */
