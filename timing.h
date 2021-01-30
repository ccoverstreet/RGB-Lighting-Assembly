#pragma once

#ifdef __linux__
#include <time.h>
#elif _WIN32
#include <windows.h>
#endif

int msleep(unsigned int s_time) {
	#ifdef __linux__
	struct timespec req_time;
	req_time.tv_sec = (unsigned int)(s_time / 1000);
	req_time.tv_nsec = (s_time - req_time.tv_sec * 1000) * 1000000;

	return nanosleep(&req_time, NULL);
	#endif

	#ifdef _WIN32
	Sleep(s_time);
	#endif
}
