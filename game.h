#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "player.h"
#include "health.h"


class Game: public QGraphicsView
{
 public:
  Game(QWidget * parent = 0);

  Player * player;
  QGraphicsScene * scene;
  Score * score;
  Health * health;

};

#endif // GAME_H
