#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject> //zeby korzystac z mechnizmu sygnalow i slotow klasa musi dziedziczyc z QObject

class Bullet: public QObject, public QGraphicsPixmapItem //klasa Bullet dziedziczy publicznie z QGraphicsRectItem i QObject
{
  Q_OBJECT //zeby korzystac z sygnalow i slotow trzeba dodac makro qobject
public:
  Bullet(QGraphicsItem * praent = 0); //tworzę konstruktor
public slots:
  void move();
};

#endif // BULLET_H
