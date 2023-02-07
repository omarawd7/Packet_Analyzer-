#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Reader.h"
#include "RawEthernetFrame.h"
#include "eCPRI.h"
#define TypeIndexOne   40
#define TypeIndexTwo   41
#define TypeIndexThree 42
#define TypeIndexFour  43

const std::vector<int> TypeIndecies{ TypeIndexOne , TypeIndexTwo , TypeIndexThree ,TypeIndexFour };
class Parser
{
private:
	Reader Data;
	std::string Type;
	int NumberOfPackets;
public:
	Parser(Reader Data );
	void Parse();
	std::string GetType(std::string Packet);
	RawEhternetFrame Parse_RawEthernetFrames();
	eCPRI            Parse_eCPRI();

};