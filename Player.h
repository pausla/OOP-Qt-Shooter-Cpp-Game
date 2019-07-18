#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem //kolejnosc ma znaczenie najpierw dziecziczy po qobject potem qgraphicsrectitem
{
  Q_OBJECT
public:
  Player(QGraphicsItem * parent = 0);
  void keyPressEvent(QKeyEvent *event);
public slots:
  void spawn();
private:
  QMediaPlayer * sound;
};

#endif // PLAYER_H
