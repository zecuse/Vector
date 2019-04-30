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

	}
};

Vector::Engine* Vector::CreateApplication()
{
	return new Sandbox();
}