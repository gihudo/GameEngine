#pragma once

#include "Event.h"

namespace Omurice
{
	class OM_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class OM_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool isRepeat)
			:KeyEvent(keyCode), m_IsRepeat(isRepeat) {}

		inline bool GetIsRepeat() const { return m_IsRepeat; }

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "KeyPressedEvent: " << GetKeyCode() << " (Repeats " << GetIsRepeat() << ")";
			return strstream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_IsRepeat;
	};

	class OM_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool isRepeat)
			:KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "KeyPressedEvent: " << GetKeyCode();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}



