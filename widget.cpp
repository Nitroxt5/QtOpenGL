#include "widget.h"

void Widget::getxAxisState(int value)
{
    xAxisRotation = value;
    updateGL();
}

void Widget::getyAxisState(int value)
{
    yAxisRotation = value;
    updateGL();
}

void Widget::getzAxisState(int value)
{
    zAxisRotation = value;
    updateGL();
}

void Widget::getxAxisCameraState(int value)
{
    xAxisCameraRotation = (float)value / 90;
    updateGL();
}

void Widget::getyAxisCameraState(int value)
{
    yAxisCameraRotation = (float)value / 90;
    updateGL();
}

void Widget::getzAxisCameraState(int value)
{
    zAxisCameraRotation = (float)value / 90;
    updateGL();
}

void Widget::getPyramidState(int value)
{
    pyramidsRotation = value;
    updateGL();
}

void Widget::getScaleState(int value)
{
    scaleValue = (float)value / 10;
    updateGL();
}

void Widget::getLightingState(int value)
{
    if (value == 2)
    {
        toggleLighting = true;
    }
    else
    {
        toggleLighting = false;
    }
    updateGL();
}

void Widget::getPointLightingState(int value)
{
    if (value == 2)
    {
        togglePointLighting = true;
    }
    else
    {
        togglePointLighting = false;
    }
    updateGL();
}

void Widget::getPyramidsMovementState(int value)
{
    if (value == 2)
    {
        togglePyramidsMovement = true;
    }
    else
    {
        togglePyramidsMovement = false;
    }
    updateGL();
}

void Widget::getTeapotTextureState(int value)
{
    if (value == 2)
    {
        toggleTeapotTexture = true;
    }
    else
    {
        toggleTeapotTexture = false;
    }
    updateGL();
}

void Widget::getPyramidsTextureState(int value)
{
    if (value == 2)
    {
        togglePyramidsTexture = true;
    }
    else
    {
        togglePyramidsTexture = false;
    }
    updateGL();
}

void Widget::getMaterialReflection(int value)
{
    materialReflection = (float)value / 100;
    updateGL();
}

void Widget::pyramidsSpin()
{
    if (pyramidsRotation == 180)
    {
        pyramidsRotation = -180;
    }
    else
    {
        ++pyramidsRotation;
    }
    updateGL();
}

Widget::Widget(QWidget *parent) : QGLWidget(parent)
{
    setGeometry(0, 0, 900, 900);
    xAxisRotation = 0.0;
    yAxisRotation = 0.0;
    zAxisRotation = 0.0;
    xAxisCameraRotation = 0.0;
    yAxisCameraRotation = 0.0;
    zAxisCameraRotation = 0.0;
    materialReflection = 0.0;
    pyramidsRotation = 0.0;
    scaleValue = 0.5;
    toggleLighting = true;
    togglePointLighting = false;
    togglePyramidsMovement = false;
    toggleTeapotTexture = false;
    togglePyramidsTexture = false;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::pyramidsSpin);
}

void Widget::createTexture(unsigned int *texture)
{
    int width = 2, height = 2;
    struct {unsigned char r, g, b, a;} data[2][2];
    memset(data, 0, sizeof(data));
    data[0][0].r = 255;
    data[1][0].g = 255;
    data[1][1].b = 255;
    data[0][1].r = 255;
    data[0][1].g = 255;

    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                                    0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Widget::initializeGL()
{
    glEnable(GL_TEXTURE_2D);
    createTexture(&texture1);

    GLfloat white[4] = {1, 1, 1, 1};
    glClearColor(0.5, 0.5, 0.5, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glLightfv(GL_LIGHT0, GL_POSITION, diffuseLightPosition);
    glLightfv(GL_LIGHT1, GL_POSITION, pointLightPosition);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_MODELVIEW);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Widget::drawTable()
{
    glColor3f(0.2, 0.2, 0.0);
    glVertexPointer(3, GL_FLOAT, 0, tableVertexArray);
    glNormalPointer(GL_FLOAT, 0, tableNormalArray);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, tableIndexArray);
    glColor3f(0.0, 0.0, 0.0);
    glDrawElements(GL_LINE_STRIP, 16, GL_UNSIGNED_BYTE, tableIndexArray);
}

void Widget::drawPyramid(GLfloat x, GLfloat y, GLfloat z)
{
    if (togglePyramidsTexture)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glPushMatrix();
            glRotatef(pyramidsRotation, 0, 1, 0);
            glTranslatef(x, y, z);
            glVertexPointer(3, GL_FLOAT, 0, pyramidVertexArray);
            glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
            glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_BYTE, pyramidIndexArray);
            glNormalPointer(GL_FLOAT, 0, pyramidNormalArray);
            glBindTexture(GL_TEXTURE_2D, 0);
            glColor3f(0.0, 0.0, 0.0);
            glDrawElements(GL_LINE_STRIP, 18, GL_UNSIGNED_BYTE, pyramidIndexArray);
        glPopMatrix();
    }
    else
    {
        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
            glRotatef(pyramidsRotation, 0, 1, 0);
            glTranslatef(x, y, z);
            glVertexPointer(3, GL_FLOAT, 0, pyramidVertexArray);
            glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_BYTE, pyramidIndexArray);
            glNormalPointer(GL_FLOAT, 0, pyramidNormalArray);
            glColor3f(0.0, 0.0, 0.0);
            glDrawElements(GL_LINE_STRIP, 18, GL_UNSIGNED_BYTE, pyramidIndexArray);
        glPopMatrix();
    }
}

void Widget::createShadowMatrix(float ground[4], const float light[4])
{
    float dot;
    float shadowMat[4][4];

    dot = ground[0] * light[0] +
          ground[1] * light[1] +
          ground[2] * light[2] +
          ground[3] * light[3];

    shadowMat[0][0] = dot - light[0] * ground[0];
    shadowMat[1][0] = 0.0 - light[0] * ground[1];
    shadowMat[2][0] = 0.0 - light[0] * ground[2];
    shadowMat[3][0] = 0.0 - light[0] * ground[3];

    shadowMat[0][1] = 0.0 - light[1] * ground[0];
    shadowMat[1][1] = dot - light[1] * ground[1];
    shadowMat[2][1] = 0.0 - light[1] * ground[2];
    shadowMat[3][1] = 0.0 - light[1] * ground[3];

    shadowMat[0][2] = 0.0 - light[2] * ground[0];
    shadowMat[1][2] = 0.0 - light[2] * ground[1];
    shadowMat[2][2] = dot - light[2] * ground[2];
    shadowMat[3][2] = 0.0 - light[2] * ground[3];

    shadowMat[0][3] = 0.0 - light[3] * ground[0];
    shadowMat[1][3] = 0.0 - light[3] * ground[1];
    shadowMat[2][3] = 0.0 - light[3] * ground[2];
    shadowMat[3][3] = dot - light[3] * ground[3];

    glMultMatrixf((const GLfloat*)shadowMat);
}

void Widget::drawTeapotShadow(float ground[4], const float light[4])
{
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
        createShadowMatrix(ground, light);
        glColor3f(0.0, 0.0, 0.0);
        glutSolidTeapot(0.5);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}

void Widget::paintGL()
{
    float floor[] = {0.0, 1.0, 0.0, 0.36};
    float defaultSpecularColor[] = {0.0, 0.0, 0.0, 1.0};
    float specularColor[] = {materialReflection, materialReflection, materialReflection, 1.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(xAxisCameraRotation, yAxisCameraRotation, zAxisCameraRotation, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);

    glRotatef(xAxisRotation, 1.0, 0.0, 0.0);
    glRotatef(yAxisRotation, 0.0, 1.0, 0.0);
    glRotatef(zAxisRotation, 0.0, 0.0, 1.0);

    glScalef(scaleValue, scaleValue, scaleValue);

    glLightfv(GL_LIGHT1, GL_POSITION, pointLightPosition);
    glLightfv(GL_LIGHT0, GL_POSITION, diffuseLightPosition);

    if (toggleLighting)
    {
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }
    if (togglePointLighting)
    {
        glEnable(GL_LIGHT1);
    }
    else
    {
        glDisable(GL_LIGHT1);
    }

    drawTable();

    if (toggleLighting)
    {
        drawTeapotShadow(floor, diffuseLightPosition);
    }
    if (togglePointLighting)
    {
        drawTeapotShadow(floor, pointLightPosition);
    }

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
    if (toggleTeapotTexture)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glutSolidTeapot(0.5);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    else
    {
        glColor3f(0.0, 1.0, 1.0);
        glutSolidTeapot(0.5);
    }
    glMaterialfv(GL_FRONT, GL_SPECULAR, defaultSpecularColor);

    drawPyramid(0.0, 0.0, 0.7);
    drawPyramid(0.49, 0.0, -0.49);
    drawPyramid(-0.49, 0.0, -0.49);

    if (togglePyramidsMovement)
    {
        timer->start(30);
    }
    else
    {
        timer->stop();
    }
}
