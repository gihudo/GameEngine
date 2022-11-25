#pragma once

#ifdef OM_PLATFORM_WINDOWS

extern Omurice::Application* Omurice::CreateApplication();

int main(int argc, char** argv)
{
	Omurice::Log::Init();
	OM_CORE_INFO("Initialized log!");
	OM_INFO("Initialized log!");

	auto app = Omurice::CreateApplication();
	app->Run();
	delete app;
}
#endif
