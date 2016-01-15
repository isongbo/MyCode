#include <iostream>
#include <cstdio>
using namespace std;
class Clock {
public:
	/*
	Clock (void) {
		m_hour = 0;
		m_min = 0;
		m_sec = 0;
	}
	*/
	Clock (int hour = 0, int min = 0,
		int sec = 0) {
		m_hour = hour;
		m_min = min;
		m_sec = sec;
	}
	void run (void) {
		for (;;) {
			show ();
			tick ();
		}
	}
private:
	void show (void) {
		printf ("%02d:%02d:%02d\r",
			m_hour, m_min, m_sec);
		fflush (stdout);
	}
	void tick (void) {
		sleep (1);
		if (++m_sec == 60) {
			m_sec = 0;
			if (++m_min == 60) {
				m_min = 0;
				if (++m_hour == 24)
					m_hour = 0;
			}
		}
	}
	int m_hour;
	int m_min;
	int m_sec;
};
int main (void) {
	time_t t = time (NULL);
	tm* local = localtime (&t);
	/*
	Clock clock (local->tm_hour,
		local->tm_min, local->tm_sec);
	*/
	Clock clock;
	clock.run ();
	return 0;
}
