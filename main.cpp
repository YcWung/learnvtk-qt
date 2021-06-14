#include <QtGui/QSurfaceFormat>
#include <QtWidgets/QApplication>
#include "ViewerWin.hpp"
#include <QVTKOpenGLNativeWidget.h>

int main(int argc, char** argv) {
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
  QApplication app(argc, argv);
  ViewerWin win;
  win.show();
  return app.exec();
}
