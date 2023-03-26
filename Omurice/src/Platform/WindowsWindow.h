#pragma once
#include "Omurice/Window.h"
#include <GLFW/glfw3.h>

#include "Omurice/Events/ApplicationEvents.h"
#include "Omurice/Events/KeyboardEvents.h"
#include "Omurice/Events/MouseEvents.h"

namespace Omurice
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
			
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline bool IsVSync() const override { return m_Data.VSync; }

		inline void SetVSync(bool enabled) override;
		inline void SetEventCallback(const std::function<void(Event&)>& callback) override { m_Data.EventCallback = callback; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;

			unsigned int Width;
			unsigned int Height;
			bool VSync;

			std::function<void(Event&)> EventCallback;

		} m_Data;
	};
}


