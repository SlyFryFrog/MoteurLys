#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace LilyPad
{
	enum class Key : unsigned int
	{
		EMPTY,
		UNIQUE = (1 << 8),
		KEY_0 = 0x0030,
		KEY_1 = 0x0031,
		KEY_2 = 0x0032,
		KEY_3 = 0x0033,
		KEY_4 = 0x0034,
		KEY_5 = 0x0035,
		KEY_6 = 0x0036,
		KEY_7 = 0x0037,
		KEY_8 = 0x0038,
		KEY_9 = 0x0039,
		COLON = 0x003A,
		SEMICOLON = 0x003B,
		LESS = 0x003C,
		EQUAL = 0x003D,
		GREATER = 0x003E,
		QUESTION = 0x003F,
		A = 0x0041,
		B = 0x0042,
		C = 0x0043,
		D = 0x0044,
		E = 0x0045,
		F = 0x0046,
		G = 0x0047,
		H = 0x0048,
		I = 0x0049,
		J = 0x004A,
		K = 0x004B,
		L = 0x004C,
		M = 0x004D,
		N = 0x004E,
		O = 0x004F,
		P = 0x0050,
		Q = 0x0051,
		R = 0x0052,
		S = 0x0053,
		T = 0x0054,
		U = 0x0055,
		V = 0x0056,
		W = 0x0057,
		X = 0x0058,
		Y = 0x0059,
		Z = 0x005A,
		ESCAPE = UNIQUE,
		F1 = UNIQUE | 0x0022,
		F2 = UNIQUE | 0x0023,
		F3 = UNIQUE | 0x0024,
		F4 = UNIQUE | 0x0025,
		F5 = UNIQUE | 0x0026,
		F6 = UNIQUE | 0x0027,
		F7 = UNIQUE | 0x0028,
		F8 = UNIQUE | 0x0029,
		F9 = UNIQUE | 0x002A,
		F10 = UNIQUE | 0x002B,
		F11 = UNIQUE | 0x002C,
		F12 = UNIQUE | 0x002D,
		F13 = UNIQUE | 0x002E,
		F14 = UNIQUE | 0x002F,
		F15 = UNIQUE | 0x0030,
		F16 = UNIQUE | 0x0031,
		F17 = UNIQUE | 0x0032,
		F18 = UNIQUE | 0x0033,
		F19 = UNIQUE | 0x0034,
		F20 = UNIQUE | 0x0035,
		F21 = UNIQUE | 0x0036,
		F22 = UNIQUE | 0x0037,
		F23 = UNIQUE | 0x0038,
		F24 = UNIQUE | 0x0039,
		F25 = UNIQUE | 0x003A,
        
		MASK = (1 << 16),
		SHIFT = MASK | 0x0001,
		ALT = MASK | 0x0002
	};

    enum class KeyPosition : unsigned int
    {
        UNKNOWN,
        LEFT,
        RIGHT
    };

	enum class KeyAction 
	{
		PRESS,
		JUST_PRESSED,
		RELEASE,
		JUST_RELEASED
	};

	Key convert_code(unsigned int code);
} // namespace LilyPad
