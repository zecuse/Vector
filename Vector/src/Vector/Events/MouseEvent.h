#pragma once

#include <sstream>

#include "Event.h"

namespace Vector
{
	class VECTOR_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline int GetX() const { return m_MouseX; }
		inline int GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(Mouse | Input)

	private:
		int m_MouseX, m_MouseY;
	};

	class VECTOR_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline int GetX() const { return m_XOffset; }
		inline int GetY() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(Mouse | Input)

	private:
		int m_XOffset, m_YOffset;
	};

	class VECTOR_API MouseEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(Mouse | Input)

	protected:
		MouseEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class VECTOR_API MousePressedEvent : public MouseEvent
	{
	public:
		MousePressedEvent(int button)
			: MouseEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousePressed)
	};

	class VECTOR_API MouseReleasedEvent : public MouseEvent
	{
	public:
		MouseReleasedEvent(int button)
			: MouseEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseReleased)
	};
}