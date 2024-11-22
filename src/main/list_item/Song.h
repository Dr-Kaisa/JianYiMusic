//
// Created by 18160 on 2024/11/21.
//

#ifndef SON_H
#define SON_H
#include <qstring.h>


class Song {
private:
    QString title = "未知";
    bool favo = false;
    QString path;

public:
    QString get_title() const;

    bool is_favo() const;

    QString get_path() const;

    void set_favo(bool favo);

    Song(QString title, QString path, bool favo);

    Song(QString title);
};


#endif //SON_H
