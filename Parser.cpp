#include "Parser.h"
using namespace std;

Parser::Parser(Reader Data)
{
	NumberOfPackets = Data.NumberOfPackets;
	 this->Data=Data ;
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
        std::cout<<REF[indexOfThePacket]->GetCRC();

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

	// parsing CRc
	std::string CRC;
	int last_Packet_Index = Packet.length();

	for (int i = last_Packet_Index - CRC_bits; i < last_Packet_Index; i++)
	{
		CRC += Packet[i];
	}
	// parsing Destination Address
	std::string Destination_Address;
	for (int i = Destination_Address_index; i < Destination_Address_bits; i++)
	{
		Destination_Address += Packet[i];
	}
	// parsing Destination Address
	std::string Source_Address;
	for (int i = Source_Address_index; i < Source_Address_bits; i++)
	{
		Source_Address += Packet[i];
	}
	// setting the attributes
	REF[indexOfThePacket]->SetCRC(CRC);
	REF[indexOfThePacket]->SetSourceAddress(Source_Address);
	REF[indexOfThePacket]->SetDestinationAddress(Destination_Address);

	return *REF[indexOfThePacket];
}

eCPRI Parser::Parse_eCPRI(std::string Packet, int indexOfThePacket)
{
	eCPRI e;

	std::string ProtocolVersion = ""+Packet[Protocol_Version_Index];
	std::string ConcatenationIndicator = ""+Packet[Concatenation_Indicator_Index];
	std::string MessageType =""+ Packet[MessageTypeIndex] + Packet[MessageTypeIndex + 1];
	std::string PayloadSize;


	for (int i = 0; i < PayloadSize_bits; i++)
	{
		PayloadSize += Packet[i];
	}
	std::string RTC_ID;
	for (int i = 0; i < RTC_IDSize_bits; i++)
	{
		RTC_ID += Packet[i];
	}
	std::string Sequence_ID;
	for (int i = 0; i < Sequence_ID_bits; i++)
	{
		Sequence_ID += Packet[i];
	}

	e.SetProtocolVersion(ProtocolVersion);
	e.SetConcatenationIndicator(ConcatenationIndicator);
	e.SetMessageType(MessageType);
	e.SetPayloadSize(PayloadSize);
	e.SetRTC_ID(RTC_ID);
	e.SetSequence_ID(Sequence_ID);
	REF[indexOfThePacket] = &e;

	
}


