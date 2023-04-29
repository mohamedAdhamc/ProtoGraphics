#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "canvas.h"
#include "QColorDialog"
#include "QLabel"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//try to do test layout then replace the top thing with the actual widget we want

	// Create a new widget for the layout
	QWidget *centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	centralWidget->setObjectName("centralWidget");

	QVBoxLayout *layout = new QVBoxLayout();
	//replace with the canvas
	Canvas* canvas_ = new Canvas(centralWidget);
	canvas_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	canvas_->setStyleSheet("border: 2px solid green");
	layout->addWidget(canvas_, 1);

	QFrame* separator = new QFrame();
	separator->setFrameShape(QFrame::HLine);
	separator->setFrameShadow(QFrame::Sunken);
	layout->addWidget(separator);

	//Horizontal Tool Bar
	QHBoxLayout *toolBar = new QHBoxLayout();
	QPushButton* circleButton = createButton("circle");
	QPushButton* lineButton = createButton("line");
	QPushButton* rectangleButton = createButton("rectangle");
	toolBar->addWidget(circleButton);
	toolBar->addWidget(lineButton);
	toolBar->addWidget(rectangleButton);
//	toolBar->addWidget(new QColorDialog(this));

	layout->addStretch();
	layout->addLayout(toolBar);
	layout->setContentsMargins(2, 2, 2, 2); // Set a 10-pixel margin around the layout
	centralWidget->setStyleSheet("QWidget#centralWidget {border: 2px solid black;} "); // Set a 2-pixel thick black border around the widget
	centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
	delete ui;
}

QPushButton*
MainWindow::createButton(const QString& text, bool checkable) {
	QPushButton* button = new QPushButton(text);
	button->setCheckable(checkable);
	return button;
}
