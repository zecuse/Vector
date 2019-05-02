#pragma once

#include "vcpch.h"
#include "Vector/Core.h"

namespace Vector
{
	// Currently, naive, blocking event system that processes events immediately.
	// Need to implement somesort of queue that captures events so they are processed
	// at an appropriate time.

	enum class EventType
	{
		None = 0,
		WindowFocus, WindowLostFocus, WindowMoved, WindowResize, WindowClose,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseMoved, MousePressed, MouseReleased, MouseScrolled
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }

	enum EventCategory
	{
		None = 0,
		Application = BIT(1),
		Input       = BIT(2),
		Keyboard    = BIT(3),
		Mouse       = BIT(4),
		MouseButton = BIT(5)
	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class VECTOR_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}