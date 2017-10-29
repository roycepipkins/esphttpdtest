/*
 * ESPHTTPD.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: Royce
 */

#include "ESPHTTPD.h"
#include <libesphttpd/httpd.h>
#include <vector>
#include "HttpConnectionFactory.h"

std::vector<HttpdBuiltInUrl> url_patterns;


CgiStatus connection_handler(HttpdConnData* connData, char* data, int len)
{
	//TODO find factory instance and call it
}


void ESPHTTPD::AddHttpConnectionFactory(HttpConnectionFactory* factory, const char* url_pattern)
{
	HttpdBuiltInUrl url_pattern = {url_pattern, connection_handler, factory};
}
