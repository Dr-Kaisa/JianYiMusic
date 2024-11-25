//
// Created by 18160 on 2024/11/21.
//

#include "Song.h"


QString Song::get_title() const {
    return title;
}

bool Song::is_favo() const {
    return favo;
}

QString Song::get_author() const {
    return author;
}

QString Song::get_path() const {
    return path;
}

void Song::set_favo(bool favo) {
    this->favo = favo;
}

Song::Song(QString title, QString author, QString path, bool favo): title(title), author(author), path(path),
                                                                    favo(favo) {
}

Song::Song(QString title): title(title), favo(false) {
}
