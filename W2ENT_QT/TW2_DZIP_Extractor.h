#ifndef TW2_DZIP_EXTRACTOR_H
#define TW2_DZIP_EXTRACTOR_H

#include <QObject>
#include <QFile>
#include <QBuffer>
#include <QFileInfo>
#include <QDir>
#include <QMap>

// Based on :
// http://www.krinkels.ucoz.ru/_fr/0/scriptw2.txt

// LZF compression explained here :
// https://en.wikibooks.org/wiki/Data_Compression/Dictionary_compression#LZF
// https://github.com/ning/compress/wiki/LZFFormat


class TW2_DZIP_Extractor : public QObject
{
    Q_OBJECT
public:
    explicit TW2_DZIP_Extractor(QString file = "", QString folder = "");

private:
    void extractDZIP(QString exportFolder, QString filename);

    QString _file;
    QString _folder;
    bool _stopped;

    QByteArray decompressLZF(QString filename);
    void extractDecompressedFile(QBuffer& buffer, QString exportFolder);

public slots :
    void run();
    void quitThread();

signals:
    void onProgress(int);
    void finished();
    void error();
};

#endif // TW2_DZIP_EXTRACTOR_H