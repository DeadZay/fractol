/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:11:47 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 09:01:08 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLXEVENTS_H
# define FT_MLXEVENTS_H

/*
** ************************************************************************** **
**
** Original event codes gets from:
** /System/Library/Frameworks/Carbon
** .framework/Versions/A/Frameworks/HIToolbox
** .framework/Versions/A/Headers/Events.h
**
** or from:
** /Library/Developer/CommandLineTools/SDKs/MacOSX
** .sdk/System/Library/Frameworks/Carbon
** .framework/Versions/A/Frameworks/HIToolbox
** .framework/Versions/A/Headers/Events.h
**
** ************************************************************************** **
*/

typedef enum							e_mouse_event
{
	MOUSE_EVENT_NONE =					0,
	MOUSE_EVENT_LBUTTON =				1,
	MOUSE_EVENT_RBUTTON =				2,
	MOUSE_EVENT_SCROLL =				3,
	MOUSE_EVENT_SCROLL_UP =				4,
	MOUSE_EVENT_SCROLL_DOWN =			5,
	MOUSE_EVENT_SCROLL_LEFT =			6,
	MOUSE_EVENT_SCROLL_RIGHT =			7
}										t_mouse_event;

typedef enum							e_x_event
{
	EVENT_NONE = 						0,
	EVENT_KEY_PRESS =					2,
	EVENT_KEY_RELEASE  =				3,
	EVENT_MOUSE_BUTTON_PRESS =			4,
	EVENT_MOUSE_BUTTON_RELEASE =		5,
	EVENT_MOUSE_MOVE =					6,
	EVENT_EXPOSE =						12,
	EVENT_CLOSE =						17
}										t_x_event;

typedef enum 							e_x_mask
{
	MASK_NULL =							0,
	MASK_KEY_PRESS =					(1L << 2),
	MASK_KEY_RELEASE =					(1L << 3),
	MASK_MOUSE_BUTTON_PRESS =			(1L << 4),
	MASK_MOUSE_BUTTON_RELEASE =			(1L << 5),
	MASK_MOUSE_MOVE =					(1L << 6),
	MASK_EXPOSE =						(1L << 12),
	MASK_CLOSE =						(1L << 17)
}										t_x_mask;

typedef enum 							e_key
{
	KEY_A =								0X00,
	KEY_S =								0X01,
	KEY_D =								0X02,
	KEY_F =								0X03,
	KEY_H =								0X04,
	KEY_G =								0X05,
	KEY_Z =								0X06,
	KEY_X =								0X07,
	KEY_C =								0X08,
	KEY_V =								0X09,
	KEY_B =								0X0B,
	KEY_Q =								0X0C,
	KEY_W =								0X0D,
	KEY_E =								0X0E,
	KEY_R =								0X0F,
	KEY_Y =								0X10,
	KEY_T =								0X11,
	KEY_1 =								0X12,
	KEY_2 =								0X13,
	KEY_3 =								0X14,
	KEY_4 =								0X15,
	KEY_6 =								0X16,
	KEY_5 =								0X17,
	KEY_EQUAL =							0X18,
	KEY_9 =								0X19,
	KEY_7 =								0X1A,
	KEY_MINUS =							0X1B,
	KEY_8 =								0X1C,
	KEY_0 =								0X1D,
	KEY_RBRACKET =						0X1E,
	KEY_O =								0X1F,
	KEY_U =								0X20,
	KEY_LBRACKET =						0X21,
	KEY_I =								0X22,
	KEY_P =								0X23,
	KEY_L =								0X25,
	KEY_J =								0X26,
	KEY_QUOTE =							0X27,
	KEY_K =								0X28,
	KEY_SEMICOLON =						0X29,
	KEY_BACKSLASH =						0X2A,
	KEY_COMMA =							0X2B,
	KEY_SLASH =							0X2C,
	KEY_N =								0X2D,
	KEY_M =								0X2E,
	KEY_PERIOD =						0X2F,
	KEY_GRAVE =							0X32,
	KEY_NUM_DECIMAL =					0X41,
	KEY_NUM_MULTIPLY =					0X43,
	KEY_NUM_PLUS =						0X45,
	KEY_NUM_CLEAR =						0X47,
	KEY_NUM_DIVIDE =					0X4B,
	KEY_NUM_ENTER =						0X4C,
	KEY_NUM_MINUS =						0X4E,
	KEY_NUM_EQUALS =					0X51,
	KEY_NUM_0 =							0X52,
	KEY_NUM_1 =							0X53,
	KEY_NUM_2 =							0X54,
	KEY_NUM_3 =							0X55,
	KEY_NUM_4 =							0X56,
	KEY_NUM_5 =							0X57,
	KEY_NUM_6 =							0X58,
	KEY_NUM_7 =							0X59,
	KEY_NUM_8 =							0X5B,
	KEY_NUM_9 =							0X5C,
	KEY_RETURN =						0X24,
	KEY_TAB =							0X30,
	KEY_SPACE =							0X31,
	KEY_DELETE =						0X33,
	KEY_ESCAPE =						0X35,
	KEY_COMMAND =						0X37,
	KEY_SHIFT =							0X38,
	KEY_CAPSLOCK =						0X39,
	KEY_OPTION =						0X3A,
	KEY_CONTROL =						0X3B,
	KEY_RIGHTCOMMAND =					0X36,
	KEY_RIGHTSHIFT =					0X3C,
	KEY_RIGHTOPTION =					0X3D,
	KEY_RIGHTCONTROL =					0X3E,
	KEY_FUNCTION =						0X3F,
	KEY_F17 =							0X40,
	KEY_VOLUMEUP =						0X48,
	KEY_VOLUMEDOWN =					0X49,
	KEY_MUTE =							0X4A,
	KEY_F18 =							0X4F,
	KEY_F19 =							0X50,
	KEY_F20 =							0X5A,
	KEY_F5 =							0X60,
	KEY_F6 =							0X61,
	KEY_F7 =							0X62,
	KEY_F3 =							0X63,
	KEY_F8 =							0X64,
	KEY_F9 =							0X65,
	KEY_F11 =							0X67,
	KEY_F13 =							0X69,
	KEY_F16 =							0X6A,
	KEY_F14 =							0X6B,
	KEY_F10 =							0X6D,
	KEY_F12 =							0X6F,
	KEY_F15 =							0X71,
	KEY_HELP =							0X72,
	KEY_HOME =							0X73,
	KEY_PAGEUP =						0X74,
	KEY_FORWARDDELETE =					0X75,
	KEY_F4 =							0X76,
	KEY_END =							0X77,
	KEY_F2 =							0X78,
	KEY_PAGEDOWN =						0X79,
	KEY_F1 =							0X7A,
	KEY_LEFTARROW =						0X7B,
	KEY_RIGHTARROW =					0X7C,
	KEY_DOWNARROW =						0X7D,
	KEY_UPARROW =						0X7E
}										t_key;

#endif
