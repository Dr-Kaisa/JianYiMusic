//
// Created by 18160 on 2024/11/21.
//

#ifndef SON_H
#define SON_H
#include <qstring.h>


class Song {
private:
    QString title = "未知";
    QString author = "";
    bool favo = false;
    QString path;

public:
    QString get_title() const;

    bool is_favo() const;

    QString get_author() const;

    QString get_path() const;

    void set_favo(bool favo);

    Song(QString title, QString author, QString path, bool favo);

    Song(QString title);

    friend uint qHash(const Song &song, uint seed);

    bool operator==(const Song &other) const;
};


#endif //SON_H
