/*
 * login.h
 *
 *  Created on: Aug 3, 2023
 *      Author: MS
 */

#ifndef LOGIN_H_
#define LOGIN_H_

#define Cursor_on	0b00001110
#define Cursor_off	0b00001100

void enter_password(void);
void Save_Password(void);
u8   Check_password(void);
void First_password(void);
void handl_password(void);

#endif /* LOGIN_H_ */
