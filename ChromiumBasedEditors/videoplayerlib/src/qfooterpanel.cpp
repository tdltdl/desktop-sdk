#include "../qfooterpanel.h"

#include <QStyleOption>
#include <QPainter>

#include "qfooterpanel_private.h"
#include "../qascvideoview.h"
#include "qascvideowidget.h"
#include "qpushbutton_icons.h"

QFooterPanel::QFooterPanel(QWidget* parent, QAscVideoView* pView) : QWidget(parent)
{
	m_pInternal = new QFooterPanel_Private();
	m_pInternal->m_pView = pView;

	// footer widgets
	m_pInternal->m_pPlayPause = new QIconPushButton(this, true, "play", "play-active");
	m_pInternal->m_pVolume = new QIconPushButton(this, true, "volume", "volume-active");
	m_pInternal->m_pFullscreen = new QIconPushButton(this, true, "fullscreen-on", "fullscreen-on-active");
	m_pInternal->m_pPlaylist = new QIconPushButton(this, true, "playlist", "playlist-active");

	m_pInternal->m_pSlider = new QVideoSlider(this);
	m_pInternal->m_pSlider->setOrientation(Qt::Horizontal);
	m_pInternal->m_pSlider->setMinimum(0);
	m_pInternal->m_pSlider->setMaximum(100000);
	m_pInternal->m_pSlider->setValue(0);
	m_pInternal->m_pSlider->setSingleStep(1000);
	m_pInternal->m_pSlider->setShortcutEnabled(QKeySequence::Back, true);
	m_pInternal->m_pSlider->setShortcutEnabled(QKeySequence::Forward, true);
	m_pInternal->m_pSlider->SetSeekOnClick(true);

	// volume control widgets
	m_pInternal->m_pVolumeControl = new QWidget(parent);
	m_pInternal->m_pVolumeControl->setHidden(true);
	m_pInternal->m_pVolumeControl->setStyleSheet("border: none; background-color:#111111");

	m_pInternal->m_pVolumeControlV = new QVideoSlider(m_pInternal->m_pVolumeControl);
	m_pInternal->m_pVolumeControlV->setOrientation(Qt::Vertical);
	m_pInternal->m_pVolumeControlV->setMinimum(0);
	m_pInternal->m_pVolumeControlV->setMaximum(100);
	m_pInternal->m_pVolumeControlV->setValue(50);

	// connect signals
	QObject::connect(m_pInternal->m_pPlayPause, SIGNAL(clicked(bool)), this, SLOT(onPlayPauseBtnClicked()));
	QObject::connect(m_pInternal->m_pVolume, SIGNAL(clicked(bool)), this, SLOT(onVolumeBtnClicked()));
	QObject::connect(m_pInternal->m_pFullscreen, SIGNAL(clicked(bool)), this, SLOT(onFullscreenBtnClicked()));
	QObject::connect(m_pInternal->m_pPlaylist, SIGNAL(clicked(bool)), this, SLOT(onPlaylistBtnClicked()));

	QObject::connect(m_pInternal->m_pSlider, SIGNAL(valueChanged(int)), this, SLOT(onSeekChanged(int)));
	QObject::connect(m_pInternal->m_pVolumeControlV, SIGNAL(valueChanged(int)), this, SLOT(onVolumeChanged(int)));

	// set event filters
	m_pInternal->m_pFullscreen->installEventFilter(pView);
	m_pInternal->m_pVolume->installEventFilter(pView);
	m_pInternal->m_pPlaylist->installEventFilter(pView);
	m_pInternal->m_pSlider->installEventFilter(pView);
	m_pInternal->m_pPlayPause->installEventFilter(pView);

	// set mouse tracking
	if (!pView->m_pInternal->m_bIsPresentationMode)
	{
		this->setMouseTracking(true);
		m_pInternal->m_pSlider->setMouseTracking(true);
		m_pInternal->m_pFullscreen->setMouseTracking(true);
		m_pInternal->m_pPlaylist->setMouseTracking(true);
		m_pInternal->m_pVolume->setMouseTracking(true);
		m_pInternal->m_pPlayPause->setMouseTracking(true);
	}

	// init flags
	m_pInternal->m_bIsEnabledPlayList = true;
	m_pInternal->m_bIsEnabledFullscreen = true;
}

QFooterPanel::~QFooterPanel()
{
	delete m_pInternal;
}

void QFooterPanel::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event);

	double dDpi = QWidget_GetDPI(this);

	int nButW = QWidget_ScaleDPI(m_pInternal->c_nButtonsWidth, dDpi);
	int nY = QWidget_ScaleDPI(m_pInternal->c_nButtonsY, dDpi);
	int nBetweenButtons = QWidget_ScaleDPI(m_pInternal->c_nButtonsBetween, dDpi);

	int nLeft = nBetweenButtons;
	m_pInternal->m_pPlayPause->setGeometry(nLeft, nY, nButW, nButW); nLeft += (nButW + nBetweenButtons);

	int nRight = this->width();

	nRight -= (nBetweenButtons + nButW);
	if (m_pInternal->m_bIsEnabledPlayList)
	{
		m_pInternal->m_pPlaylist->setGeometry(nRight, nY, nButW, nButW); nRight -= (nBetweenButtons + nButW);
	}
	if (m_pInternal->m_bIsEnabledFullscreen)
	{
		m_pInternal->m_pFullscreen->setGeometry(nRight, nY, nButW, nButW); nRight -= (nBetweenButtons + nButW);
	}

	m_pInternal->m_pVolume->setGeometry(nRight, nY, nButW, nButW); nRight -= nBetweenButtons;
	m_pInternal->m_pSlider->setGeometry(nLeft, nY, nRight - nLeft, nButW);

	// set volume control geometry
	int nVolumeControlW = QWidget_ScaleDPI(m_pInternal->c_nVolumeControlWidth, dDpi);
	int nVolumeControlH = QWidget_ScaleDPI(m_pInternal->c_nVolumeControlHeight, dDpi);
	int nVolumeControlX = this->x() + m_pInternal->m_pVolume->x() + nButW / 2 - nVolumeControlW / 2;
	int nVolumeControlY = this->y() + m_pInternal->m_pVolume->y() - nVolumeControlH - nBetweenButtons;

	m_pInternal->m_pVolumeControl->setGeometry(nVolumeControlX, nVolumeControlY, nVolumeControlW, nVolumeControlH);

	// set volume slider geometry
	int nVolumeSliderW = QWidget_ScaleDPI(m_pInternal->c_nVolumeSliderWidth, dDpi);
	int nVolumeSliderH = QWidget_ScaleDPI(m_pInternal->c_nVolumeSliderHeight, dDpi);
	int nVolumeSliderX = QWidget_ScaleDPI(m_pInternal->c_nVolumeSliderX, dDpi);
	int nVolumeSliderY = QWidget_ScaleDPI(m_pInternal->c_nVolumeSliderY, dDpi);

	m_pInternal->m_pVolumeControlV->setGeometry(nVolumeSliderX, nVolumeSliderY, nVolumeSliderW, nVolumeSliderH);
}

void QFooterPanel::mouseMoveEvent(QMouseEvent* event)
{
	if (m_pInternal->m_pView->getMainWindowFullScreen())
	{
		QAscVideoView* pView = m_pInternal->m_pView;
		// stop cursor hiding timer
		if (pView->m_pInternal->m_oCursorTimer.isActive())
			pView->m_pInternal->m_oCursorTimer.stop();
		// stop footer hiding timer
		if (pView->m_pInternal->m_oFooterTimer.isActive())
			pView->m_pInternal->m_oFooterTimer.stop();
	}
	event->accept();
}

void QFooterPanel::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

int QFooterPanel::GetHeight()
{
	return QWidget_ScaleDPI(m_pInternal->c_nHeight, QWidget_GetDPI(this));
}

int QFooterPanel::GetMinWidth()
{
	return QWidget_ScaleDPI(m_pInternal->c_nMinWidth, QWidget_GetDPI(this));
}

int QFooterPanel::GetMaxWidth()
{
	return QWidget_ScaleDPI(m_pInternal->c_nMaxWidth, QWidget_GetDPI(this));
}

QWidget* QFooterPanel::VolumeControls()
{
	return m_pInternal->m_pVolumeControl;
}

void QFooterPanel::onPlayPauseBtnClicked()
{
	m_pInternal->m_pView->PlayPause();
}

void QFooterPanel::onVolumeBtnClicked()
{
	VolumeControls()->setHidden(!VolumeControls()->isHidden());
}

void QFooterPanel::onFullscreenBtnClicked()
{
	m_pInternal->m_pView->Fullscreen();
}

void QFooterPanel::onPlaylistBtnClicked()
{
	m_pInternal->m_pView->TogglePlaylist();
}

void QFooterPanel::onSeekChanged(int nValue)
{
	m_pInternal->m_pView->ChangeSeek(nValue);
}

void QFooterPanel::onVolumeChanged(int nValue)
{
	m_pInternal->m_pView->ChangeVolume(nValue);
}

void QFooterPanel::SetPlayPauseIcon(bool bIsPlay)
{
	QString sI = bIsPlay ? "play" : "pause";
	((QIconPushButton*)m_pInternal->m_pPlayPause)->changeIcons(sI, sI + "-active");
}

void QFooterPanel::SetFullscreenIcon(bool bIsFullscreen)
{
	QString sI = bIsFullscreen ? "fullscreen-on" : "fullscreen-off";
	((QIconPushButton*)m_pInternal->m_pFullscreen)->changeIcons(sI, sI + "-active");
}
