#if !defined ACTOR_HEADER
#define ACTOR_HEADER

namespace MyCodes
{
	enum class ActorState
	{
		Error,
		Undefined,
		StandBy,
		InAction,
		Done
	};

	class Actor abstract
	{
	public:
		Actor();
		virtual ~Actor();

		virtual bool initialize() = 0;
		virtual void finalize() = 0;
		virtual void act(const float elapsedTimeSinceLastFrame) = 0;
		virtual ActorState getState() const = 0;
	};
}

#endif