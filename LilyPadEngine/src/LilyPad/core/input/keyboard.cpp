#include "keyboard.hpp"

namespace LilyPad
{
	Key convert_code(unsigned int code)
	{
		// Handle special cases for unique keycodes
		if (code >= static_cast<unsigned int>(Key::UNIQUE))
		{
			switch (code & ~static_cast<unsigned int>(Key::UNIQUE))
			{
			case 0x0022:
				return Key::F1;
			case 0x0023:
				return Key::F2;
			case 0x0024:
				return Key::F3;
			case 0x0025:
				return Key::F4;
			case 0x0026:
				return Key::F5;
			case 0x0027:
				return Key::F6;
			case 0x0028:
				return Key::F7;
			case 0x0029:
				return Key::F8;
			case 0x002A:
				return Key::F9;
			case 0x002B:
				return Key::F10;
			case 0x002C:
				return Key::F11;
			case 0x002D:
				return Key::F12;
			case 0x002E:
				return Key::F13;
			case 0x002F:
				return Key::F14;
			case 0x0030:
				return Key::F15;
			case 0x0031:
				return Key::F16;
			case 0x0032:
				return Key::F17;
			case 0x0033:
				return Key::F18;
			case 0x0034:
				return Key::F19;
			case 0x0035:
				return Key::F20;
			case 0x0036:
				return Key::F21;
			case 0x0037:
				return Key::F22;
			case 0x0038:
				return Key::F23;
			case 0x0039:
				return Key::F24;
			case 0x003A:
				return Key::F25;
			case GLFW_KEY_LEFT_SHIFT:
			case GLFW_KEY_RIGHT_SHIFT:
				return Key::SHIFT;
			case GLFW_KEY_LEFT_ALT:
			case GLFW_KEY_RIGHT_ALT:
                return Key::ALT;
			default:
				return Key::EMPTY; // Handle unexpected unique values
			}
		}

		// Handle regular keys
		switch (code)
		{
		case 0x0030:
			return Key::KEY_0;
		case 0x0031:
			return Key::KEY_1;
		case 0x0032:
			return Key::KEY_2;
		case 0x0033:
			return Key::KEY_3;
		case 0x0034:
			return Key::KEY_4;
		case 0x0035:
			return Key::KEY_5;
		case 0x0036:
			return Key::KEY_6;
		case 0x0037:
			return Key::KEY_7;
		case 0x0038:
			return Key::KEY_8;
		case 0x0039:
			return Key::KEY_9;
		case 0x003A:
			return Key::COLON;
		case 0x003B:
			return Key::SEMICOLON;
		case 0x003C:
			return Key::LESS;
		case 0x003D:
			return Key::EQUAL;
		case 0x003E:
			return Key::GREATER;
		case 0x003F:
			return Key::QUESTION;
		case 0x0041:
			return Key::A;
		case 0x0042:
			return Key::B;
		case 0x0043:
			return Key::C;
		case 0x0044:
			return Key::D;
		case 0x0045:
			return Key::E;
		case 0x0046:
			return Key::F;
		case 0x0047:
			return Key::G;
		case 0x0048:
			return Key::H;
		case 0x0049:
			return Key::I;
		case 0x004A:
			return Key::J;
		case 0x004B:
			return Key::K;
		case 0x004C:
			return Key::L;
		case 0x004D:
			return Key::M;
		case 0x004E:
			return Key::N;
		case 0x004F:
			return Key::O;
		case 0x0050:
			return Key::P;
		case 0x0051:
			return Key::Q;
		case 0x0052:
			return Key::R;
		case 0x0053:
			return Key::S;
		case 0x0054:
			return Key::T;
		case 0x0055:
			return Key::U;
		case 0x0056:
			return Key::V;
		case 0x0057:
			return Key::W;
		case 0x0058:
			return Key::X;
		case 0x0059:
			return Key::Y;
		case 0x005A:
			return Key::Z;
		default:
			return Key::EMPTY; // Handle unexpected values
		}
	}
} // namespace LilyPad
