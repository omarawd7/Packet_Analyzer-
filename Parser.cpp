#include "Parser.h"

Parser::Parser(Reader Data)
{
	NumberOfPackets = Data.NumberOfPackets;
	Data = this->Data;
}

void Parser::Parse()
{
	for (int i = 0; i < NumberOfPackets; i++)
	{
		RawEhternetFrame REF;
		std::string Packet = Data.Input[i];
		REF.Type = GetType(Packet);
	}
}

std::string Parser::GetType(std::string Packet)
{
	std::string TempString;
	for (int i = 0;i < TypeIndecies.size();i++)
	{
		TempString += Packet[TypeIndecies[i]];
	}
	if (TempString == "AEFE" || TempString == "88F7")
	{
		return TempString;
	}
	else
	{
		return TempString;
	}
}

RawEhternetFrame Parser::Parse_RawEthernetFrames()
{
	return RawEhternetFrame();
}

eCPRI Parser::Parse_eCPRI()
{
	return eCPRI();
}
