#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h> //includes rand

extern Game *game;

Enemy::Enemy(QGraphicsItem * parent) : QObject (), QGraphicsPixmapItem (parent)
{
  int random_number = rand() % 700;
  //set random position
  setPos(random_number, 0);

  //create
  setPixmap(QPixmap(":/images/alien.png"));
  setTransformOriginPoint(50,50);
  setRotation(180);

  //connect
  QTimer * timer = new QTimer();
  connect(timer, SIGNAL(timeout()),this,SLOT(move()));

  timer->start(50);
}

void Enemy::move()
{
  setPos(x(), y()+10); //enemy moves down
  if(pos().y()+ 100 >600) //remove when it touches ground
    {
      scene()->removeItem(this);
      delete this;
      game->health->decrease();
      if(game->health->getHealth()<0)
        {
          game->close();
        }
      qDebug() << "Enemy deleted";

    }
}
