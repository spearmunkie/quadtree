#ifndef CBASEQGL_H
#define CBASEQGL_H
#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
class CBaseQGL : public QGLWidget {
	Q_OBJECT			
	public:
		CBaseQGL( int timerInterval=0, QWidget *parent=0): QGLWidget(parent) {
			setFormat(QGLFormat(QGL::DoubleBuffer));
			setMouseTracking(true);
			
			if( timerInterval == 0 )
				timer  = 0;
			else {
				timer = new QTimer( this );
				connect( timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()) );
				timer->start( timerInterval );
			}
		}

	protected:
		virtual void initializeGL() = 0;
		virtual void resizeGL( int width, int height ) = 0;
		virtual void paintGL() = 0;
		virtual void timeOut() {}
		protected slots:
			virtual void timeOutSlot() {
				timeOut();
			}
										
		private:
			QTimer *timer;
};
#endif
