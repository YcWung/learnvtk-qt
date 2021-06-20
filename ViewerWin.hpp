#pragma once

#include <QMainWindow>

class Ui_ViewerWin;
class PointCloudViewer;

class ViewerWin : public QMainWindow {
  Q_OBJECT

 public:
  ViewerWin();
  ~ViewerWin() override;

 protected slots:
  void toggle_select_region(bool);
  void pick_focal_point();

 private:
  Ui_ViewerWin* ui;
  PointCloudViewer* pcv;
};
