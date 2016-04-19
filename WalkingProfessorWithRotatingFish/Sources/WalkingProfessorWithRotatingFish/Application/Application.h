#if !defined APPLICATION_HEADER
#define APPLICATION_HEADER

namespace MyCodes
{
	class Application abstract 
	{
	public:
		Application();
		virtual ~Application();

		virtual bool initialize() = 0;
		virtual void finalize() = 0;
		virtual int operate() = 0;
	};
}

#endif