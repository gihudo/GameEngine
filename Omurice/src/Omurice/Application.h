#pragma once
#include "Core.h"

namespace Omurice 
{
	class OM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in a client
	Application* CreateApplication();
}


