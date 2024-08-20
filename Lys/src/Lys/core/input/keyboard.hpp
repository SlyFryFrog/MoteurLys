#pragma once

#ifdef OpenGL
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

namespace Lys
{
	/**
	 * @brief Collection of keys supported by the engine.
	 */
	enum class Key : unsigned int
	{
		EMPTY,
		UNIQUE = (1 << 8),
		SPACE = 0x0020,
		EXCLAM = 0x0021,
		QUOTEDBL = 0x0022,
		NUMBERSIGN = 0x0023,
		DOLLAR = 0x0024,
		PERCENT = 0x0025,
		AMPERSAND = 0x0026,
		APOSTROPHE = 0x0027,
		PARENLEFT = 0x0028,
		PARENRIGHT = 0x0029,
		ASTERISK = 0x002A,
		PLUS = 0x002B,
		COMMA = 0x002C,
		MINUS = 0x002D,
		PERIOD = 0x002E,
		SLASH = 0x002F,
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
		AT = 0x0040,
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
		ENTER = UNIQUE | 0x0001,
		CONTROL = UNIQUE | 0x0002,
		SUPER = UNIQUE | 0x0003,
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
		KEY_PAD_0 = UNIQUE | 0x0040,
		KEY_PAD_1 = UNIQUE | 0x0041,
		KEY_PAD_2 = UNIQUE | 0x0042,
		KEY_PAD_3 = UNIQUE | 0x0043,
		KEY_PAD_4 = UNIQUE | 0x0044,
		KEY_PAD_5 = UNIQUE | 0x0045,
		KEY_PAD_6 = UNIQUE | 0x0046,
		KEY_PAD_7 = UNIQUE | 0x0047,
		KEY_PAD_8 = UNIQUE | 0x0048,
		KEY_PAD_9 = UNIQUE | 0x0049,

		MASK = (1 << 10),
		SHIFT = MASK | 0x0001,
		ALT = MASK | 0x0002
	};

	enum class KeyPosition : unsigned int
	{
		UNKNOWN,
		LEFT,
		RIGHT
	};

	Key convert_code(unsigned int code);
} // namespace Lys
