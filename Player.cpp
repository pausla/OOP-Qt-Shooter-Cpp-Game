#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player(QGraphicsItem * parent) : QGraphicsPixmapItem (parent)
{
  sound = new QMediaPlayer();
  sound->setMedia(QUrl("qrc:/sounds/Gun_Shot.wav"));

  setPixmap(QPixmap(":/images/ufo.png"));
};

void Player::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Left)
    {
      if(pos().x() > 0)
        {
          setPos(x() - 14, y());
        }
    }
  else if (event->key() == Qt::Key_Right)
    {
      if(pos().x() + 100 < 800 )
        {
          setPos(x()+14, y());
        }
    }
//  else if (event->key() == Qt::Key_Up)
//    {
//      setPos(x(),y()-10);
//    }
//  else if (event->key() == Qt::Key_Down)
//    {
//      setPos(x(),y()+10);
//    }
  else if (event->key() == Qt::Key_Space)
    {
      Bullet * bullet = new Bullet();
      scene()->addItem(bullet);
      bullet->setPos(x() + 30, y() - 50);
      if(sound->state()== QMediaPlayer::PlayingState )
        {
          sound->setPosition(0);
        }
      else if(sound->state() == QMediaPlayer::StoppedState )
        {
          sound->play();
        }
    }

}

void Player::spawn()
{
  Enemy * enemy = new Enemy();
  scene()->addItem(enemy);
}
