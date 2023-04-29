#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

class Canvas : public QWidget
{
	Q_OBJECT
public:
	explicit Canvas(QWidget *parent = nullptr);

private:
	 void paintEvent(QPaintEvent* event) override;
	 void mouseMoveEvent(QMouseEvent *event) override;
	 QPainter painter; // Member variable for the QPainter object
	 bool painter_active; // Boolean status variable for the QPainter object
	 int mouse_paint_pos_x;
	 int mouse_paint_pos_y;
	 std::vector<QPointF> points;
signals:

};

#endif // CANVAS_H
