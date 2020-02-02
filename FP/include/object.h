#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QString>

class Object : public QObject
{
    Q_OBJECT

protected:
    QString name_;
    int age_;
    int score_;

public:
    explicit Object(QString name, QObject *parent = 0);

    void setAge(const int& age);
    void setScore(const int& score);

signals:
    void ageChanged(int age);
    void scoreChanged(int score);

public slots:
    void onAgeChanged(int age);
    void onScoreChanged(int score);
};

#endif // OBJECT_H