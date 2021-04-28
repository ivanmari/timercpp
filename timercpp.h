#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

enum class Mode {PERIODIC, ONESHOT};

class Timer {
	std::atomic<bool> active{true};
	
    public:
	template<class Rep,class Period = std::ratio<1>>
        Timer(auto function, const std::chrono::duration<Rep, Period>  duration, Mode mode): active{true},m_mode{mode},
        m_thread{std::thread ([=]() {
        if(!active.load()) return;
	while(active.load())
	{
        	std::this_thread::sleep_for(duration);
        	if(!active.load()) break;
        	function();
		if(Mode::ONESHOT == m_mode) break;
	}
    })}
{}
        void stop();
	std::thread m_thread;
	Mode m_mode;

	~Timer()
	{
		stop();
		m_thread.join();
	}

};


void Timer::stop() {
    active = false;
}
