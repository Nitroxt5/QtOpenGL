#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QSlider>
#include <QTimer>
#include <QImage>
#include <cmath>
#include <gl/glut.h>

static const GLfloat pyX = 0.0;
static const GLfloat pyZ = 0.0;
static const GLfloat pyRad = 0.2;
static const GLfloat pyH = 0.3;

static const GLfloat tableVertexArray[8][3] = {{-2.0, -0.4, 1.0},
                                               {-2.0, -0.36, 1.0},
                                               {2.0, -0.36, 1.0},
                                               {2.0, -0.4, 1.0},
                                               {-2.0, -0.4, -1.0},
                                               {-2.0, -0.36, -1.0},
                                               {2.0, -0.36, -1.0},
                                               {2.0, -0.4, -1.0}};

static const GLubyte tableIndexArray[6][4] = {{0, 1, 2, 3},
                                              {0, 4, 5, 1},
                                              {4, 7, 6, 5},
                                              {3, 2, 6, 7},
                                              {1, 5, 6, 2},
                                              {0, 3, 7, 4}};

static const GLfloat tableNormalArray[8][3] = {{0.0, -1.0, 0.0},
                                               {0.0, 1.0, 0.0},
                                               {0.0, 1.0, 0.0},
                                               {0.0, -1.0, 0.0},
                                               {0.0, -1.0, 0.0},
                                               {0.0, 1.0, 0.0},
                                               {0.0, 1.0, 0.0},
                                               {0.0, -1.0, 0.0}};

static const GLfloat pyramidVertexArray[7][3] = {{pyX,                       0.0, pyZ - pyRad},
                                                 {pyX + pyRad * sqrt(3) / 2, 0.0, pyZ - pyRad / 2},
                                                 {pyX + pyRad * sqrt(3) / 2, 0.0, pyZ + pyRad / 2},
                                                 {pyX,                       0.0, pyZ + pyRad},
                                                 {pyX - pyRad * sqrt(3) / 2, 0.0, pyZ + pyRad / 2},
                                                 {pyX - pyRad * sqrt(3) / 2, 0.0, pyZ - pyRad / 2},
                                                 {pyX,                       pyH, pyZ}};

static const GLubyte pyramidIndexArray[6][3] = {{1, 0, 6},
                                                {2, 1, 6},
                                                {3, 2, 6},
                                                {4, 3, 6},
                                                {5, 4, 6},
                                                {0, 5, 6}};

static const GLfloat pyramidNormalArray[7][3] = {{0.0, 0.8, -1.0},
                                                 {2.0, 1.8, -1.0},
                                                 {2.0, 1.8, 1.0},
                                                 {0.0, 0.8, 1.0},
                                                 {-2.0, 1.8, 1.0},
                                                 {-2.0, 1.8, -1.0},
                                                 {0.0, 1.0, 0.0}};

static const GLfloat diffuseLightPosition[4] = {0.0, 1.0, 0.0, 0.0};
static const GLfloat pointLightPosition[4] = {2.0, 4.0, 2.0, 1.0};

static const GLfloat texCoords[4][2] = {{0, 0},
                                        {1, 0},
                                        {1, 1},
                                        {0, 1}};

class Widget : public QGLWidget
{
    Q_OBJECT
    QTimer *timer;

    float xAxisRotation;
    float yAxisRotation;
    float zAxisRotation;
    float xAxisCameraRotation;
    float yAxisCameraRotation;
    float zAxisCameraRotation;
    float pyramidsRotation;
    float scaleValue;
    float materialReflection;
    bool toggleLighting;
    bool togglePointLighting;
    bool togglePyramidsMovement;
    bool toggleTeapotTexture;
    bool togglePyramidsTexture;

    unsigned int texture1;

    void createTexture(unsigned int *texture);
    void drawTable();
    void drawPyramid(GLfloat x, GLfloat y, GLfloat z);
    void createShadowMatrix(float* ground, const float* light);
    void drawTeapotShadow(float* ground, const float* light);

public:
    Widget(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

public slots:
    void getxAxisState(int);
    void getyAxisState(int);
    void getzAxisState(int);
    void getxAxisCameraState(int);
    void getyAxisCameraState(int);
    void getzAxisCameraState(int);
    void getPyramidState(int);
    void getScaleState(int);
    void getLightingState(int);
    void getPointLightingState(int);
    void getPyramidsMovementState(int);
    void getTeapotTextureState(int);
    void getPyramidsTextureState(int);
    void getMaterialReflection(int);
    void pyramidsSpin();
};

#endif // WIDGET_H
