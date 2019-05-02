#pragma once

#include "Event.h"

namespace Vector
{
	class VECTOR_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(Application)
		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class VECTOR_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_CATEGORY(Application)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class VECTOR_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(Application)
		EVENT_CLASS_TYPE(AppTick)
	};

	class VECTOR_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(Application)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class VECTOR_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(Application)
		EVENT_CLASS_TYPE(AppRender)
	};
}