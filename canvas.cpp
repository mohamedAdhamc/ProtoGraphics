#include "canvas.h"
#include "QPainter"
#include "QMouseEvent"
#include <iostream>

Canvas::Canvas(QWidget *parent)
	: QWidget{parent}
{
//	setFixedSize(400, 400); // Set the canvas size
	setMouseTracking(true); // Enable continuous mouse tracking
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setStyleSheet("border: 10px solid black;");
	std::cout<<styleSheet().toStdString()<<std::endl;
	std::cout<<(sizePolicy() == QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding))<<std::endl;
}

void
Canvas::paintEvent(QPaintEvent* event) {
	QWidget::paintEvent(event); // Call the base class implementation
	QPainter painter(this);
	QPen* pen = new QPen(Qt::red);
	pen->setWidth(5);
	painter.setPen(*pen);
	for (auto point: points){
		painter.drawPoint(point);
	}
	std::cout<<"paint event"<<std::endl;
}

void
Canvas::mouseMoveEvent(QMouseEvent* event) {
	if (event->buttons() & Qt::LeftButton) { // Check if left mouse button is pressed
//		if (!painter_active) { // Check if QPainter object is not active
//			painter.begin(this); // Activate the QPainter object
//			painter_active = true; // Set the QPainter object status to active
//		}
//		painter.setPen(Qt::red); // Set the pen color to red
//		painter.drawEllipse(event->pos(), 5, 5); // Draw a small circle at current mouse position
//		update(); // Schedule a repaint of the widget
		points.push_back(event->position());
		update();
	}
}
