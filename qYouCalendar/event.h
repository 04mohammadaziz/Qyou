/*#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDateTime>
#include <QString>

class Event: public QObject {

    Q_OBJECT

    Q_PROPERTY(int id READ getID WRITE setID CONSTANT)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QDateTime startDate READ startDate WRITE setStartDate NOTIFY startDateChanged)
    Q_PROPERTY(QDateTime endDate READ endDate WRITE setEndDate NOTIFY endDateChanged)

    public:
        explicit Event(QObject* parent = nullptr);

        int getID() const;
        void setID(const int &id);

        QString name() const;
        void setName(const QString &name);

        QDateTime startDate() const;
        void setStartDate(const QDateTime &startDate);

        QDateTime endDate() const;
        void setEndDate(const QDateTime &endDate);

    private:

        int evtID;
        QString evtName;
        QDateTime evtStartDate;
        QDateTime evtEndDate;

    signals:

        void nameChanged(const QString &name);
        void startDateChanged(const QDateTime &startDate);
        void endDateChanged(const QDateTime &endDate);
};

#endif // EVENT_H
*/
