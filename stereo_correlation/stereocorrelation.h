#ifndef STEREOCORRELATION_H
#define STEREOCORRELATION_H

#include <QMainWindow>
#include "common.h"
#include "imageprocessingview.h"

namespace Ui {
    class StereoCorrelation;
}

namespace Stereo
{

  class StereoCorrelation : public QMainWindow
  {
    Q_OBJECT

  public:
    explicit StereoCorrelation(QWidget *parent = 0);
    ~StereoCorrelation();

  private:
    Ui::StereoCorrelation *ui;
    ImageProcessingView* m_processingView;
  };

}
#endif // STEREOCORRELATION_H
