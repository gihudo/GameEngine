#pragma once

#include "Core.h"
#include "Window.h"
#include "Omurice/Events/ApplicationEvents.h"

namespace Omurice {

	class OM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}