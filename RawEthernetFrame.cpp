#include "RawEthernetFrame.h"

RawEhternetFrame::RawEhternetFrame()
{
}

std::string RawEhternetFrame::GetCRC()
{
	return CRC;
}

void RawEhternetFrame::SetCRC(std::string CRC)
{
	this->CRC = CRC;
}

std::string RawEhternetFrame::GetPreamble()
{
	return std::string();
}

void RawEhternetFrame::SetPreamble(std::string Preamble)
{
	this->Preamble = Preamble;
}

std::string RawEhternetFrame::GetDestinationAddress()
{
	return std::string();
}

void RawEhternetFrame::SetDestinationAddress(std::string DestinationAddress)
{
	this->DestinationAddress = DestinationAddress;
}

std::string RawEhternetFrame::GetSourceAddress()
{
	return std::string();
}

void RawEhternetFrame::SetSourceAddress(std::string SourceAddress)
{
	this->SourceAddress = SourceAddress;
}

std::string RawEhternetFrame::GetPayload()
{
	return std::string();
}

void RawEhternetFrame::SetPayload(std::string Payload)
{
	this->Payload = Payload;
}

std::string RawEhternetFrame::GetType()
{
	return std::string();
}

void RawEhternetFrame::SetType(std::string Type)
{
	this->Type = Type;
}
