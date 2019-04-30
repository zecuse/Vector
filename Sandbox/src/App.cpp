#include <Vector.h>

class Sandbox : public Vector::Engine
{
public:
	Sandbox()
	{
		VC_INFO("Hello");
	}

	~Sandbox()
	{
		VC_INFO("Goodbye");
	}
};

Vector::Engine* Vector::CreateApplication()
{
	return new Sandbox();
}