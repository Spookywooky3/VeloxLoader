#include "auth.h"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

#include <sstream>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

// cURL wrapper used:
// https://github.com/pocoproject/poco/tree/master
bool Authentication::AuthUser( const char* username, const char* password ) {
	try {
		// Code is pretty self explanatory here, create session => create request => send request => get request => get response
		// Very basic needs to be improved on
		// Replace localhost and port with that of your server
		HTTPClientSession session( "localhost", 8080 );
		HTTPRequest request( HTTPRequest::HTTP_GET, ( "/auth?username=" + string(username) + "&password=" + string(password) ), HTTPMessage::HTTP_1_1 );
		session.sendRequest( request );
		
		HTTPResponse response;
		string responseCode;
		istream& stream = session.receiveResponse( response );
		StreamCopier::copyToString( stream, responseCode );

		if ( responseCode == "1" )
			return true;

		return false;
	}
	catch ( Exception& ex ) {
		return false;
	}
}