#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class RawEhternetFrame
{
protected:
	std::string CRC;
	std::string Preamble;
	std::string DestinationAddress;
	std::string SourceAddress;
	std::string Payload;

public:
	std::string GetCRC();
	void SetCRC();
	std::string GetPreamble();
	void SetPreamble();
	std::string GetDestinationAddress();
	void SetDestinationAddress();
	std::string GetSourceAddress();
	void SetSourceAddress();
	std::string GetPayload();
	void SetPayload();
	std::string GetType();
	void SetType();

	std::string Type;

};