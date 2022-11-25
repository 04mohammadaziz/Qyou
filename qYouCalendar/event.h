#pragma once

#include <QAbstractListModel>
#include <QDateTime>

struct Event {
    QString name;
    QDateTime startDate;
    QDateTime endDate;
};

