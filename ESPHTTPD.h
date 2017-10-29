/*
 * ESPHTTPD.h
 *
 *  Created on: Oct 29, 2017
 *      Author: Royce
 */

#ifndef ESPHTTPD_H_
#define ESPHTTPD_H_

#include <string>

class HttpConnectionFactory;

class ESPHTTPD {
public:

	static void Start();
	static void AddHttpConnectionFactory(HttpConnectionFactory* factory, const char* url_pattern);

};

#endif /* ESPHTTPD_H_ */
