#ifndef HW_H_ //checks if HW_H_ lib already included ; newer compilers use #pragma once for any libs
#define HW_H_ //only defines HW_H_ if not alr included

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifdef DEBUG //if DEBUG flag added to g++, set DEBUG
#define PDEBUG 1
#else
#define PDEBUG 0
#endif
/*
#define DPRINT(fmt, ...) do { if (PDEBUG) fprintf(stderr, "%s:%d:%s(): "fmt,\
                __FILE__, __LINE__, __func__, ##__VA_ARGS__); } while (0)
*/
#define DPRINT(fmt, ...) do {\
		 		if (PDEBUG) {\
					char str[100];\
					snprintf(str, 100, fmt, ##__VA_ARGS__);\
					std::cerr << "DEBUG-->";\
					std::cerr << __FILE__ << ":" << __LINE__ << ":";\
					std::cerr << __func__ << "():" << str;\
		 		}\
                	} while (0)

#endif
