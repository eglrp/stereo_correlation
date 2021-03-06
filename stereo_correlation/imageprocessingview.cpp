#include "imageprocessingview.h"
#include "ui_imageprocessingview.h"
#include "common.h"

// processing steps
#include "image_pipeline/openimage.h"
#include "image_pipeline/saveimage.h"

namespace Stereo
{

    ImageProcessingView::ImageProcessingView(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::ImageProcessingView),
      m_stepsAvailable(),
      m_stepsToExecute(),
      m_stepBuilder()
    {
      ui->setupUi(this);
      // Add all the known processing steps to available steps
      // The user moves them into the execution queue.
      populateAvailableSteps();
      LOGV << "Processing steps available: " <<m_stringMapping.size();
    }

    void ImageProcessingView::populateAvailableSteps()
    {
        m_stringMapping["Open Image"] = &GuiImagePipelineBuilder::buildOpenImage;
        m_stringMapping["Save Image"] = &GuiImagePipelineBuilder::buildSaveImage;
    }

    ImageProcessingView::~ImageProcessingView()
    {
      delete ui;
    }
}
