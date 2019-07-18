#include <QTimer>
#include <QFont>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QImage>
#include "game.h"
#include "enemy.h"
#include "player.h"

Game::Game(QWidget *parent)
{
  //Create scene
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  scene->setBackgroundBrush(QImage(":/images/bg.jpg"));
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800,600);

  //create player
  player = new Player();
  player ->setPos(400,500);
  player -> setFlag(QGraphicsItem::ItemIsFocusable); //make the player focusable and set it to the current focus
  player -> setFocus();
  scene -> addItem(player);

  //create the score/health
  score = new Score();
  scene->addItem(score);
  health = new Health();
  health->setPos(health->x(), health->y()+25);
  scene->addItem(health);

  //spawn enemies
  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
  timer->start(2000);

  show();
}
