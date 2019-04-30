#include <Vector.h>

class Sandbox : public Vector::Engine
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Vector::Engine* Vector::CreateApplication()
{
	return new Sandbox();
}