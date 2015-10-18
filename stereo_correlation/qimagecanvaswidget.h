#ifndef QIMAGECANVASWIDGET
#define QIMAGECANVASWIDGET

#include <boost/smart_ptr.hpp>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

class QImageCanvasWidget: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
    /********
     * Typedefs
     ********/
public:
    typedef boost::shared_ptr<std::string> filename_ptr;

    /********
     * Object functions
     ********/
public:
    QImageCanvasWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual filename_ptr changeImageFilePath(filename_ptr newFilePath);

    /* This is a prefix used when inferring things about subclasses, e.g. when
     * munging or navigating strings, which we handle up here, but we need to
     * handle differently depending on the base class' value. It has a prefix
     * it can supply to us.
     */
    virtual const std::string imageTextPrefix() = 0;

    /********
     * OpenGL hooks
     ********/
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    /*******
     * Signals and slots
     ********/
public slots:
    // This is called from the menu or the button to change the image with QFileDialog.
    void updateImage();

    /********
     * Member variables
     ********/
protected:

    filename_ptr m_filePath;

};

#endif // QIMAGECANVASWIDGET
