#include <windows.h>

#include <sstream>

int main(int argc, char* argv[])
{
	std::stringstream tmp;
	for(int i = 1; i < argc; ++i)
	{
		tmp << i << ": " << argv[i] << std::endl;
	}

	std::string text = tmp.str();

	MessageBox(NULL, text.c_str(), "Hello World", MB_OK);
}
