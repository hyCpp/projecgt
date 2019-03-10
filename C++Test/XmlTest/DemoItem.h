#ifndef DemoItem_H
#define DemoItem_H

#include <QObject>
#include <VoiceVoiceRecogListItemBase.h>

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

class DemoItem : public VoiceVoiceRecogListItemBase
{
public:
    explicit DemoItem();
    DemoItem(const DemoItem& item);
    DemoItem &operator=(const DemoItem& item);
    explicit DemoItem(const QString &index,
                                const QString &type,
                                const QString &count,
                                const QString &poiType,
                                const QString &poiID,
                                const QString &poiName,
                                const QString &poiLon,
                                const QString &poiLat,
                                const QString &tel,
                                const QString &address,
                                const QString &linkID,
                                const QString &distance,
                                const QString &songID,
                                const QString &songName,
                                const QString &albumId,
                                const QString &albumName,
                                const QString &artistID,
                                const QString &artistName,
                                const QString &sourceId,

                                const QString &contactId,
                                const QString &firstName,
                                const QString &lastName,
                                const QString &phoneType1,
                                const QString &phoneType2,
                                const QString &phoneType3,
                                const QString &phoneType4,
                                const QString &phoneNumber1,
                                const QString &phoneNumber2,
                                const QString &phoneNumber3,
                                const QString &phoneNumber4);
    ~DemoItem();

    QString getIndex() const;
    QString getType() const;
    QString getCount() const;
    QString getPOIType() const;
    QString getPOIId() const;
    QString getPOIName() const;
    QString getPOILon() const;
    QString getPOILat() const;
    QString getTel() const;
    QString getAddress() const;
    QString getLinkId() const;
    QString getDistance() const;
    QString getSongId() const;
    QString getSongName() const;
    QString getAlbumId() const;
    QString getAlbumName() const;
    QString getArtistId() const;
    QString getArtistName() const;
    QString getSourceId() const;

    QString getContactid() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getPhoneType1() const;
    QString getPhoneType2() const;
    QString getPhoneType3() const;
    QString getPhoneType4() const;
    QString getPhoneNumber1() const;
    QString getPhoneNumber2() const;
    QString getPhoneNumber3() const;
    QString getPhoneNumber4() const;

    void setIndex (const QString &index);
    void setType (const QString &type);
    void setCount (const QString &count);
    void setPOIType (const QString &poiType);
    void setPOIId (const QString &poiId);
    void setPOIName (const QString &poiName);
    void setPOILon (const QString &poiLon);
    void setPOILat (const QString &poiLat);
    void setTel (const QString &tel);
    void setAddress (const QString &address);
    void setLinkId (const QString &linkId);
    void setDistance (const QString &distance);
    void setSongId (const QString &songId);
    void setSongName (const QString &songName);
    void setAlbumId (const QString &albumId);
    void setAlbumName (const QString &albumName);
    void setArtistId (const QString &artistId);
    void setArtistName (const QString &artistName);
    void setSourceId (const QString &sourceId);

    void setContactid (const QString &contactid);
    void setFirstName (const QString &firstName);
    void setLastName (const QString &lastName);
    void setPhoneType1 (const QString &phoneType1);
    void setPhoneType2 (const QString &phoneType2);
    void setPhoneType3 (const QString &phoneType3);
    void setPhoneType4 (const QString &phoneType4);
    void setPhoneNumber1 (const QString &phoneNumber1);
    void setPhoneNumber2 (const QString &phoneNumber2);
    void setPhoneNumber3 (const QString &phoneNumber3);
    void setPhoneNumber4 (const QString &phoneNumber4);

private:
    QString m_Index;
    QString m_Type;
    QString m_Count;
    QString m_POIType;
    QString m_POIId;
    QString m_POIName;
    QString m_POILon;
    QString m_POILat;
    QString m_Tel;
    QString m_Address;
    QString m_LinkId;
    QString m_Distance;
    QString m_SongId;
    QString m_SongName;
    QString m_AlbumId;
    QString m_AlbumName;
    QString m_ArtistId;
    QString m_ArtistName;
    QString m_SourceId;

    QString m_ContactId;
    QString m_FirstName;
    QString m_LastName;
    QString m_PhoneType1;
    QString m_PhoneType2;
    QString m_PhoneType3;
    QString m_PhoneType4;
    QString m_PhoneNumber1;
    QString m_PhoneNumber2;
    QString m_PhoneNumber3;
    QString m_PhoneNumber4;
};

#endif // DemoItem_H
/* EOF */
