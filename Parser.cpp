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
		std::string Packet = Data.Input[i];
		Type = GetType(Packet);
		int indexOfThePacket=i;
		if (Type == eCPRI_Type)
		{
            
            Parse_eCPRI(Packet,indexOfThePacket);
		}
		else if (Type == RawEhternetFrame_Type)
		{

			Parse_RawEthernetFrames(Packet,indexOfThePacket);
		}


	}
}

std::string Parser::GetType(std::string Packet)
{
	std::string TempString;
	for (int i = 0; i < TypeIndecies.size(); i++)
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

RawEhternetFrame Parser::Parse_RawEthernetFrames(std::string Packet,int indexOfThePacket)
{
	RawEhternetFrame r;
    REF[indexOfThePacket]= &r;
	return RawEhternetFrame();
}

eCPRI Parser::Parse_eCPRI(std::string Packet ,int indexOfThePacket)
{
	eCPRI e;
    REF[indexOfThePacket]= &e;
	return eCPRI();
}
