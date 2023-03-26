#pragma once

#include "Event.h"

namespace Omurice
{
	class OM_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}
		 
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "MouseMovedEvent: " << GetX() << ' ' << GetY();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_MouseX, m_MouseY;
	};

	class OM_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "MouseScrolledEvent: " << GetXOffset() << ' ' << GetYOffset();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_XOffset, m_YOffset;
	};

	class OM_API MouseButton : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		 
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	protected:
		MouseButton(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class OM_API MouseButtonPressedEvent : public MouseButton
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButton(button) {}
		
		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "MouseButtonPressed: " << GetMouseButton();
			return strstream.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class OM_API MouseButtonReleasedEvent : public MouseButton
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButton(button) {}

		std::string ToString() const override
		{
			std::stringstream strstream;
			strstream << "MouseButtonReleased: " << GetMouseButton();
			return strstream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}