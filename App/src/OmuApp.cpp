#include <Omurice.h>

class OmuApp : public Omurice::Application
{
public:
	OmuApp()
	{

	}

	~OmuApp()
	{

	}
};

Omurice::Application* Omurice::CreateApplication()
{
	return new OmuApp();
}