#include "../include/object.h"

Object::Object(QString name, QObject *parent ):QObject(parent)
{
    name_ = name;
    setObjectName(name_);
    connect(this, SIGNAL(ageChanged(int)), this, SLOT(onAgeChanged(int)));
    connect(this, SIGNAL(scoreChanged(int)), this, SLOT(onScoreChanged(int)));
}

void Object::setAge(const int& age)
{
    age_ = age;
    emit ageChanged(age_);
}

void Object::setScore(const int& score)
{
    score_ = score;
    emit scoreChanged(score_);
}

void Object::onAgeChanged(int age)
{
}

void Object::onScoreChanged(int score)
{
}
