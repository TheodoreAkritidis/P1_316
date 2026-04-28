/*
 * lcd.h
 *
 *  Created on: Apr 27, 2026
 *      Author: thodo
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_



#include <stdint.h>

void LCD_Init(void);
void LCD_Command(uint8_t command);
void LCD_WriteChar(char c);
void LCD_WriteString(const char *str);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);



#endif /* INC_LCD_H_ */
