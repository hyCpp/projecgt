#####################################################################
# Automatically generated by qtpromaker
#####################################################################

TEMPLATE = app
TARGET = Audio_Recog

HEADERS *= \
    ./include/AUDIO_Recog.h \
    ./include/AudioProcess.h \
    ./include/RecordButton_Define.h \
    ./include/WavFile.h \
    ./include/config.h \
    ./include/fingerprint.h \
    ./include/hash.h \
    ./include/json/allocator.h \
    ./include/json/assertions.h \
    ./include/json/autolink.h \
    ./include/json/config.h \
    ./include/json/features.h \
    ./include/json/forwards.h \
    ./include/json/json.h \
    ./include/json/reader.h \
    ./include/json/value.h \
    ./include/json/version.h \
    ./include/json/writer.h \
    ./include/recog.h \
    ./include/wav.h

SOURCES *= \
    ./src/AUDIO_Recog.cpp \
    ./src/AudioProcess.cpp \
    ./src/WavFile.cpp \
    ./src/fingerprint.cpp \
    ./src/hash.cpp \
    ./src/recog.cpp \
    ./src/wav.cpp

PATHS *= \
    . \
    ./src \
    ./include \
    ./include/json

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS
