#include "ViewerWin.hpp"
#include "../viewer/viewer.h"
#include "ui_ViewerWin.h"

#include <vtkConeSource.h>
#include <vtkGenericOpenGLRenderWindow.h>

ViewerWin::ViewerWin() : ui(new Ui_ViewerWin) {
  ui->setupUi(this);

  vtkNew<vtkGenericOpenGLRenderWindow> rwin;
  ui->centralwidget->setRenderWindow(rwin);
  pcv = new PointCloudViewer(rwin);

  vtkConeSource *cone = vtkConeSource::New();
  cone->SetHeight(3.0);
  cone->SetRadius(1.0);
  cone->SetResolution(10);
  cone->Update();
  this->pcv->SetData(cone->GetOutput());
}

ViewerWin::~ViewerWin() {}

void ViewerWin::toggle_select_region(bool toggled) {
  pcv->interactor_style()->SetSelectionMode(toggled);
}
