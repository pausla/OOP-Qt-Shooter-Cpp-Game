#ifndef SCORE_H
#define SCORE_Hh
#include <QGraphicsTextItem>


class Score : public QGraphicsTextItem
{
public:
  Score(QGraphicsTextItem * parent = 0); //when parent is deleted everything that derives from parent is deleted too
  void increase();
  int getScore();
private:
  int score;
};


#endif // SCORE_H
