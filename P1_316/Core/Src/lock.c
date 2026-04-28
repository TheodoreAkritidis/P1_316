/*
 * lock.c
 *
 *  Created on: Apr 27, 2026
 *      Author: thodo
 */


#include "lock.h"

static lock_state_t g_lock_state = LOCKED;
static char g_entry[LOCK_PIN_LENGTH];
static char g_pin[LOCK_PIN_LENGTH] = {'1', '2', '3', '4'};
static uint8_t g_entry_len = 0;
static uint8_t g_pin_change_mode = 0;

void Lock_Init(void)
{
    g_lock_state = LOCKED;
    g_entry_len = 0;
    g_pin_change_mode = 0;
}

lock_state_t Lock_GetState(void)
{
    return g_lock_state;
}

void Lock_SetState(lock_state_t state)
{
    g_lock_state = state;
}

void Lock_ClearEntry(void)
{
    uint8_t i;

    for (i = 0; i < LOCK_PIN_LENGTH; i++) {
        g_entry[i] = 0;
    }

    g_entry_len = 0;
}

uint8_t Lock_AddKey(char key)
{
    if (g_entry_len >= LOCK_PIN_LENGTH) {
        return 0;
    }

    g_entry[g_entry_len] = key;
    g_entry_len++;

    return 1;
}

uint8_t Lock_CheckEntry(void)
{
    uint8_t i;

    if (g_entry_len != LOCK_PIN_LENGTH) {
        return 0;
    }

    for (i = 0; i < LOCK_PIN_LENGTH; i++) {
        if (g_entry[i] != g_pin[i]) {
            return 0;
        }
    }

    return 1;
}

void Lock_StartPinChange(void)
{
    g_pin_change_mode = 1;
    Lock_ClearEntry();
}

uint8_t Lock_PinChangeMode(void)
{
    return g_pin_change_mode;
}

uint8_t Lock_SaveNewPin(void)
{
    uint8_t i;

    if (g_entry_len != LOCK_PIN_LENGTH) {
        return 0;
    }

    for (i = 0; i < LOCK_PIN_LENGTH; i++) {
        g_pin[i] = g_entry[i];
    }

    g_pin_change_mode = 0;
    Lock_ClearEntry();

    return 1;
}
