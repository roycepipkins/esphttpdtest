/*
 * HttpConnectionFactory.h
 *
 *  Created on: Oct 29, 2017
 *      Author: Royce
 */

#ifndef HTTPCONNECTIONFACTORY_H_
#define HTTPCONNECTIONFACTORY_H_

class HttpConnectionFactory {
public:
	HttpConnectionFactory();
	virtual ~HttpConnectionFactory();

	CgiStatus connection_handler(HttpdConnData* connData, char* data, int len);
};

#endif /* HTTPCONNECTIONFACTORY_H_ */
