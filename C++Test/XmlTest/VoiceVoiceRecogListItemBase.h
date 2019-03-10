#ifndef VOICEVOICERECOGLISTITEMBASE_H
#define VOICEVOICERECOGLISTITEMBASE_H

#include <QObject>

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

class VoiceVoiceRecogListItemBase
{

public:

    VoiceVoiceRecogListItemBase();
    virtual ~VoiceVoiceRecogListItemBase();
    bool filled() const;
    void setFilledProperty(const bool bFilled);

private :
    bool m_filled;
};
#endif // VOICEVOICERECOGLISTITEMBASE_H
/* EOF */

