#include "DemoItem.h"
#include<iostream>

using namespace std;

DemoItem::DemoItem()
    : m_Index("")
    , m_Type("")
    , m_Count("")
    , m_POIType("")
    , m_POIId("")
    , m_POIName("")
    , m_POILon("")
    , m_POILat("")
    , m_Tel("")
    , m_Address("")
    , m_LinkId("")
    , m_Distance("")
    , m_SongId("")
    , m_SongName("")
    , m_AlbumId("")
    , m_AlbumName("")
    , m_ArtistId("")
    , m_ArtistName("")
    , m_SourceId("")

    , m_ContactId()
    , m_FirstName()
    , m_LastName()
    , m_PhoneType1()
    , m_PhoneType2()
    , m_PhoneType3()
    , m_PhoneType4()
    , m_PhoneNumber1()
    , m_PhoneNumber2()
    , m_PhoneNumber3()
    , m_PhoneNumber4()
{

}

DemoItem::DemoItem(const DemoItem &item)
{
    m_Index         = item.getIndex();
    m_Type          = item.getType();
    m_Count         = item.getCount();
    m_POIType       = item.getPOIType();
    m_POIId         = item.getPOIId();
    m_POIName       = item.getPOIName();
    m_POILon        = item.getPOILon();
    m_POILat        = item.getPOILat();
    m_Tel           = item.getTel();
    m_Address       = item.getAddress();
    m_LinkId        = item.getLinkId();
    m_Distance      = item.getDistance();
    m_SongId        = item.getSongId();
    m_SongName      = item.getSongName();
    m_AlbumId       = item.getAlbumId();
    m_AlbumName     = item.getAlbumName();
    m_ArtistId      = item.getArtistId();
    m_ArtistName    = item.getAlbumName();
    m_SourceId      = item.getSourceId();

    m_ContactId                  = item.getContactid();
    m_FirstName                 = item.getFirstName();
    m_LastName                 = item.getLastName();
    m_PhoneType1             = item.getPhoneType1();
    m_PhoneType2             = item.getPhoneType2();
    m_PhoneType3             = item.getPhoneType3();
    m_PhoneType4             = item.getPhoneType4();
    m_PhoneNumber1      = item.getPhoneNumber1();
    m_PhoneNumber2      = item.getPhoneNumber2();
    m_PhoneNumber3      = item.getPhoneNumber3();
    m_PhoneNumber4      = item.getPhoneNumber4();
}

DemoItem &DemoItem::operator=(const DemoItem &item)
{
    m_Index         = item.getIndex();
    m_Type          = item.getType();
    m_Count         = item.getCount();
    m_POIType       = item.getPOIType();
    m_POIId         = item.getPOIId();
    m_POIName       = item.getPOIName();
    m_POILon        = item.getPOILon();
    m_POILat        = item.getPOILat();
    m_Tel           = item.getTel();
    m_Address       = item.getAddress();
    m_LinkId        = item.getLinkId();
    m_Distance      = item.getDistance();
    m_SongId        = item.getSongId();
    m_SongName      = item.getSongName();
    m_AlbumId       = item.getAlbumId();
    m_AlbumName     = item.getAlbumName();
    m_ArtistId      = item.getArtistId();
    m_ArtistName    = item.getAlbumName();
    m_SourceId      = item.getSourceId();

    m_ContactId                  = item.getContactid();
    m_FirstName                 = item.getFirstName();
    m_LastName                 = item.getLastName();
    m_PhoneType1             = item.getPhoneType1();
    m_PhoneType2             = item.getPhoneType2();
    m_PhoneType3             = item.getPhoneType3();
    m_PhoneType4             = item.getPhoneType4();
    m_PhoneNumber1      = item.getPhoneNumber1();
    m_PhoneNumber2      = item.getPhoneNumber2();
    m_PhoneNumber3      = item.getPhoneNumber3();
    m_PhoneNumber4      = item.getPhoneNumber4();

    return *this;
}

DemoItem::DemoItem(const QString &index,
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
                   const QString &phoneNumber4
                   )
    : m_Index(index)
    , m_Type(type)
    , m_Count(count)
    , m_POIType(poiType)
    , m_POIId(poiID)
    , m_POIName(poiName)
    , m_POILon(poiLon)
    , m_POILat(poiLat)
    , m_Tel(tel)
    , m_Address(address)
    , m_LinkId(linkID)
    , m_Distance(distance)
    , m_SongId(songID)
    , m_SongName(songName)
    , m_AlbumId(albumId)
    , m_AlbumName(albumName)
    , m_ArtistId(artistID)
    , m_ArtistName(artistName)
    , m_SourceId(sourceId)

    , m_ContactId(contactId)
    , m_FirstName(firstName)
    , m_LastName(lastName)
    , m_PhoneType1(phoneType1)
    , m_PhoneType2(phoneType2)
    , m_PhoneType3(phoneType3)
    , m_PhoneType4(phoneType4)
    , m_PhoneNumber1(phoneNumber1)
    , m_PhoneNumber2(phoneNumber2)
    , m_PhoneNumber3(phoneNumber3)
    , m_PhoneNumber4(phoneNumber4)
{
    std::cout<<index.toStdString()<<std::endl;
    std::cout<<type.toStdString()<<std::endl;
    std::cout<<count.toStdString()<<std::endl;
    std::cout<<poiType.toStdString()<<std::endl;
    std::cout<<poiID.toStdString()<<std::endl;
    std::cout<<poiName.toStdString()<<std::endl;
    std::cout<<poiLon.toStdString()<<std::endl;
    std::cout<<poiLat.toStdString()<<std::endl;
    std::cout<<tel.toStdString()<<std::endl;
    std::cout<<address.toStdString()<<std::endl;
    std::cout<<linkID.toStdString()<<std::endl;
    std::cout<<distance.toStdString()<<std::endl;
    std::cout<<songID.toStdString()<<std::endl;
    std::cout<<songName.toStdString()<<std::endl;
    std::cout<<albumId.toStdString()<<std::endl;
    std::cout<<albumName.toStdString()<<std::endl;
    std::cout<<artistID.toStdString()<<std::endl;
    std::cout<<artistName.toStdString()<<std::endl;
    std::cout<<sourceId.toStdString()<<std::endl;

    std::cout<<contactId.toStdString()<<std::endl;
    std::cout<<firstName.toStdString()<<std::endl;
    std::cout<<lastName.toStdString()<<std::endl;
    std::cout<<phoneType1.toStdString()<<std::endl;
    std::cout<<phoneType2.toStdString()<<std::endl;
    std::cout<<phoneType3.toStdString()<<std::endl;
    std::cout<<phoneType4.toStdString()<<std::endl;
    std::cout<<phoneNumber1.toStdString()<<std::endl;
    std::cout<<phoneNumber2.toStdString()<<std::endl;
    std::cout<<phoneNumber3.toStdString()<<std::endl;
    std::cout<<phoneNumber4.toStdString()<<std::endl;
}

DemoItem::~DemoItem()
{
    std::cout<<"DemoItem::~DemoItem()"<<std::endl;
}

QString DemoItem::getIndex() const
{
    return m_Index;
}

QString DemoItem::getType() const
{
    return m_Type;
}

QString DemoItem::getCount() const
{
    return m_Count;
}

QString DemoItem::getPOIType() const
{
    return m_POIType;
}

QString DemoItem::getPOIId() const
{
    return m_POIId;
}

QString DemoItem::getPOIName() const
{
    return m_POIName;
}

QString DemoItem::getPOILon() const
{
    return m_POILon;
}

QString DemoItem::getPOILat() const
{
    return m_POILat;
}

QString DemoItem::getTel() const
{
    return m_Tel;
}

QString DemoItem::getAddress() const
{
    return m_Address;
}

QString DemoItem::getLinkId() const
{
    return m_LinkId;
}

QString DemoItem::getDistance() const
{
    return m_Distance;
}

QString DemoItem::getSongId() const
{
    return m_SongId;
}

QString DemoItem::getSongName() const
{
    return m_SongName;
}

QString DemoItem::getAlbumId() const
{
    return m_AlbumId;
}

QString DemoItem::getAlbumName() const
{
    return m_AlbumName;
}

QString DemoItem::getArtistId() const
{
    return m_ArtistId;
}

QString DemoItem::getArtistName() const
{
    return m_ArtistName;
}

QString DemoItem::getSourceId() const
{
    return m_SourceId;
}



QString DemoItem::getContactid() const
{
    return m_ContactId;
}

QString DemoItem::getFirstName() const
{
    return m_FirstName;
}

QString DemoItem::getLastName() const
{
    return m_LastName;
}

QString DemoItem::getPhoneType1() const
{
    return m_PhoneType1;
}

QString DemoItem::getPhoneType2() const
{
    return m_PhoneType2;
}

QString DemoItem::getPhoneType3() const
{
    return m_PhoneType3;
}

QString DemoItem::getPhoneType4() const
{
    return m_PhoneType4;
}

QString DemoItem::getPhoneNumber1() const
{
    return m_PhoneNumber1;
}

QString DemoItem::getPhoneNumber2() const
{
    return m_PhoneNumber2;
}

QString DemoItem::getPhoneNumber3() const
{
    return m_PhoneNumber3;
}

QString DemoItem::getPhoneNumber4() const
{
    return m_PhoneNumber4;
}



void DemoItem::setIndex (const QString &index)
{
    m_Index = index;
}

void DemoItem::setType (const QString &type)
{
    m_Type = type;
}

void DemoItem::setCount (const QString &count)
{
    m_Count = count;
}

void DemoItem::setPOIType (const QString &poiType)
{
    m_POIType = poiType;
}

void DemoItem::setPOIId (const QString &poiId)
{
    m_POIId = poiId;
}

void DemoItem::setPOIName (const QString &poiName)
{
    m_POIName = poiName;
}

void DemoItem::setPOILon (const QString &poiLon)
{
    m_POILon = poiLon;
}

void DemoItem::setPOILat (const QString &poiLat)
{
    m_POILat = poiLat;
}

void DemoItem::setTel (const QString &tel)
{
    m_Tel = tel;
}

void DemoItem::setAddress (const QString &address)
{
    m_Address = address;
}

void DemoItem::setLinkId (const QString &linkId)
{
    m_LinkId = linkId;
}

void DemoItem::setDistance (const QString &distance)
{
    m_Distance = distance;
}

void DemoItem::setSongId (const QString &songId)
{
    m_SongId = songId;
}

void DemoItem::setSongName (const QString &songName)
{
    m_SongName = songName;
}

void DemoItem::setAlbumId (const QString &albumId)
{
    m_AlbumId = albumId;
}

void DemoItem::setAlbumName (const QString &albumName)
{
    m_AlbumName = albumName;
}

void DemoItem::setArtistId (const QString &artistId)
{
    m_ArtistId = artistId;
}

void DemoItem::setArtistName (const QString &artistName)
{
    m_ArtistName = artistName;
}

void DemoItem::setSourceId (const QString &sourceId)
{
    m_SourceId = sourceId;
}



void DemoItem::setContactid(const QString &contactid)
{
    m_ContactId = contactid;
}

void DemoItem::setFirstName(const QString &firstName)
{
    m_FirstName = firstName;
}

void DemoItem::setLastName(const QString &lastName)
{
    m_LastName = lastName;
}

void DemoItem::setPhoneType1(const QString &phoneType1)
{
    m_PhoneType1 = phoneType1;
}

void DemoItem::setPhoneType2(const QString &phoneType2)
{
    m_PhoneType2 = phoneType2;
}

void DemoItem::setPhoneType3(const QString &phoneType3)
{
    m_PhoneType3 = phoneType3;
}

void DemoItem::setPhoneType4(const QString &phoneType4)
{
    m_PhoneType4 = phoneType4;
}

void DemoItem::setPhoneNumber1(const QString &phoneNumber1)
{
    m_PhoneNumber1 = phoneNumber1;
}

void DemoItem::setPhoneNumber2(const QString &phoneNumber2)
{
    m_PhoneNumber2 = phoneNumber2;
}

void DemoItem::setPhoneNumber3(const QString &phoneNumber3)
{
    m_PhoneNumber3 = phoneNumber3;
}

void DemoItem::setPhoneNumber4(const QString &phoneNumber4)
{
    m_PhoneNumber4 = phoneNumber4;
}

/* EOF */
