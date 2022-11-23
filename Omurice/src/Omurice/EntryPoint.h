#pragma once

#ifdef OM_PLATFORM_WINDOWS

extern Omurice::Application* Omurice::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Omurice::CreateApplication();
	app->Run();
	delete app;
}
#endif
