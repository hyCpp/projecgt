#include "VoiceVoiceRecogListItemBase.h"

VoiceVoiceRecogListItemBase::VoiceVoiceRecogListItemBase()
    : m_filled(true)
{

}

VoiceVoiceRecogListItemBase::~VoiceVoiceRecogListItemBase()
{
}

bool VoiceVoiceRecogListItemBase::filled() const
{
    return m_filled;
}


void VoiceVoiceRecogListItemBase::setFilledProperty(const bool bFilled)
{
    m_filled = bFilled;
}

/* EOF */



