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
		int indexOfThePacket = i;
		if (Type == eCPRI_Type)
		{
			Parse_RawEthernetFrames(Packet, indexOfThePacket);
			Parse_eCPRI(Packet, indexOfThePacket);
		}
		else if (Type == RawEhternetFrame_Type)
		{
			Parse_RawEthernetFrames(Packet, indexOfThePacket);
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

RawEhternetFrame Parser::Parse_RawEthernetFrames(std::string Packet, int indexOfThePacket)
{
	RawEhternetFrame r;
	REF[indexOfThePacket] = &r;
	return *REF[indexOfThePacket];
}

eCPRI Parser::Parse_eCPRI(std::string Packet, int indexOfThePacket)
{
	eCPRI e;
	REF[indexOfThePacket] = &e;
	std::string ProtocolVersion = Packet[Protocol_Version_Index] ;
	std::string ConcatenationIndicator = Packet[Concatenation_Indicator_Index] ;
	std::string MessageType = Packet[MessageTypeindex] + Packet[MessageTypeindex + 1];
	std::string PayloadSize;
	for (int i = 0; i < PayloadSize_bits; i++)
	{
		PayloadSize += Packet[i];
	}
	std::string RTC_ID;
	for (int i = 0; i < RTC_IDSize_bits; i++)
	{
		RTC_IDSize += Packet[i];
	}
		std::string Sequence_ID;
	for (int i = 0; i < Sequence_ID_bits; i++)
	{
		Sequence_ID += Packet[i];
	}
	REF[indexOfThePacket].SetProtocolVersion(ProtocolVersion);
	REF[indexOfThePacket].SetConcatenationIndicator(ConcatenationIndicator);
	REF[indexOfThePacket].SetMessageType(MessageType);
	REF[indexOfThePacket].SetPayloadSize(PayloadSize);
	REF[indexOfThePacket].SetRTC_ID(RTC_ID);
	REF[indexOfThePacket].SetSequence_ID(Sequence_ID);
	return *REF[indexOfThePacket];
}
