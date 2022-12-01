#ifndef EVENT_H
#define EVENT_H
#include <QObject>
#include <QDateTime>
#include <QString>

class Event: public QObject {

    Q_OBJECT

    Q_PROPERTY(QString id READ getID WRITE setID NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QDateTime date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString startTime READ startTime WRITE setStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(QString endTime READ endTime WRITE setEndTime NOTIFY endTimeChanged)

    public:
        explicit Event(QObject* parent = nullptr);

        QString getID() const;
        void setID(const QString &id);

        QString name() const;
        void setName(const QString &name);

        QDateTime date() const;
        void setDate(const QDateTime &date);

        QString startTime() const;
        void setStartTime(const QString &startTime);

        QString endTime() const;
        void setEndTime(const QString &endTime);

    private:

        QString evtID;
        QString evtName;
        QDateTime evtDate;
        QString evtStartTime;
        QString evtEndTime;

    signals:

        void idChanged(const QString &id);
        void nameChanged(const QString &name);
        void dateChanged(const QDateTime &date);
        void startTimeChanged(const QString &startTime);
        void endTimeChanged(const QString &endTime);
};

#endif
