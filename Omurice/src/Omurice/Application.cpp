#include "Application.h"

#include "Events/MouseEvents.h"
#include "Log.h"

namespace Omurice 
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		MouseMovedEvent e(100, 100);
		OM_TRACE(e);

		while (true);
	}
}

