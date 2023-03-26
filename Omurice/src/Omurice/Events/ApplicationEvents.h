#pragma once

#include "Event.h"

namespace Omurice
{
	class OM_API WindowResizeEvent: public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "WindowResizeEvent: " << GetWidth() << ' ' << GetHeight();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class OM_API WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(unsigned int appX, unsigned int appY)
			: m_AppX(appX), m_AppY(appY) {}

		inline unsigned int GetAppX() const { return m_AppX; }
		inline unsigned int GetAppY() const { return m_AppY; }

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "WindowMoveEvent: " << GetAppX() << ' ' << GetAppY();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(WindowMove)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_AppX, m_AppY;
	};

	class OM_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "WindowCloseEvent";
			return strstream.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class OM_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "WindowFocusEvent";
			return strstream.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}