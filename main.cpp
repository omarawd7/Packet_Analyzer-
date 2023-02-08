#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


#include "RawEthernetFrame.h"
#include "eCPRI.h"
#include "Parser.h"
#include "Parser.cpp"
#include "Reader.cpp"
#include "Reader.h"

int main()
{
	Reader reader;
	reader.read("C:/Users/User/Documents/GitHub/Packet_Analyzer-/input_packets");
    Parser parser(reader);
	std::cout<<"test";
	return 0;
}


