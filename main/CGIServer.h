/*
 * CGIServer.h
 *
 *  Created on: Oct 26, 2017
 *      Author: Royce
 */

#ifndef MAIN_CGISERVER_H_
#define MAIN_CGISERVER_H_

//TODO this should encapsulate use of the whole libesphttpd component
//with no exposure of the component types in this header

//So then I feel like I need some interface class or something
//And the associated classes should also not touch the underlying component stuff

//So starting with the built-in url thing. How do you want to expose that
//containor? I think it should probably be a list of classes. Maybe the classes
//themselves can decide rather than the search thing. But I guess that search thing
//is handy. Maybe we should map that through somehow. A constructor arg
//perhaps to each object. But don't we want a instance per a connection?
//Can we get a list of classes that get new'ed? I guess that would be a factory
//pattern huh. Any clever alterative to a factory?


class CGIServer {
public:
	CGIServer();
	virtual ~CGIServer();



};

#endif /* MAIN_CGISERVER_H_ */
