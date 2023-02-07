#pragma once
#include "RawEthernetFrame.h"

class eCPRI : public RawEhternetFrame
{
private:
	std::string ConcatenationIndicator;
	std::string MessageType;
	std::string PayloadSize;
	std::string ProtocolVersion;
	std::string RTC_ID;
	std::string Sequence_ID;
public:
    eCPRI();
	std::string GetConcatenationIndicator();
	void SetConcatenationIndicator();
	std::string GetMessageType();
	void SetMessageType();
	std::string GetPayloadSize();
	void SetPayloadSize();
	std::string GetProtocolVersion();
	void SetProtocolVersion();
	std::string GetRTC_ID();
	void SetRTC_ID();
	std::string GetSequence_ID();
	void SetSequence_ID();
};