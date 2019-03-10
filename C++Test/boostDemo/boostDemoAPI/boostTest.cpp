#include <string>
#include <stdio.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

const static std::string sessionStateChanged = "<event name=\"sessionStateChanged\">"
                                                  "<state>%1%</state>"
                                              "</event>";

int main ()
{

    //Boost::format Test
//    const std::string str = (boost::format (sessionStateChanged) % "off").str().c_str();
//    printf("str = %s\n", str.c_str());

    //Generate uuid by boost::uuids::uuid
    std::string session = "";
    std::stringstream stream;
    std::stringstream stream1;
    boost::uuids::random_generator gen;
    boost::uuids::uuid uid = gen();
    stream1 << uid;
    for (boost::uuids::uuid::const_iterator it = uid.begin(); it != uid.end(); ++it) {
        stream << std::setfill('0') << std::setw(2) << std::hex << (short) (*it);
    }

    session = stream.str();
    std::string session1 = stream1.str();
    printf("%s\n", session.c_str());
    printf("%s\n", session1.c_str());
}
