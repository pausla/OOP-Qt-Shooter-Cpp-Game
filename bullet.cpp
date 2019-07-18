#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game *game; //there is an external global object called game

Bullet::Bullet(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem (parent)
{
  //create
  setPixmap(QPixmap(":/images/projectile.png"));

  //connect
  QTimer * timer = new QTimer();
  connect(timer, SIGNAL(timeout()),this,SLOT(move()));

  timer->start(50);
}

void Bullet::move()
{
  //if bullet collides with an enemy destroy both
  QList<QGraphicsItem * > colliding_items = collidingItems(); //list of pointers of colliding items, traverse list to check if bullet collides witn an enemy
  for(int i = 0, n=colliding_items.size() ;i<n ;i++)
    {
      if(typeid (*(colliding_items[i])) == typeid (Enemy))
        {
          game->score->increase();
          scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);
          delete colliding_items[i];
          delete this;
          return;
        }
    }

  setPos(x(), y()-15);
  if(pos().y()+ 60 <0)
    {
      scene()->removeItem(this);
      delete this;
      qDebug() << "Bullet deleted";

    }
}
