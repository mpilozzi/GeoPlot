#include "geoplot.h"
#include "geoplotplugin.h"

#include <QtPlugin>

GeoPlotPlugin::GeoPlotPlugin(QObject *parent)
    : QObject(parent)
{
    _initialized = false;
}

void GeoPlotPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (_initialized)
        return;

    // Add extension registrations, etc. here

    _initialized = true;
}

bool GeoPlotPlugin::isInitialized() const
{
    return _initialized;
}

QWidget *GeoPlotPlugin::createWidget(QWidget *parent)
{
    return new GeoPlot(parent);
}

QString GeoPlotPlugin::name() const
{
    return QLatin1String("GeoPlot");
}

QString GeoPlotPlugin::group() const
{
    return QLatin1String("");
}

QIcon GeoPlotPlugin::icon() const
{
    return QIcon();
}

QString GeoPlotPlugin::toolTip() const
{
    return QLatin1String("");
}

QString GeoPlotPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool GeoPlotPlugin::isContainer() const
{
    return false;
}

QString GeoPlotPlugin::domXml() const
{
    return QLatin1String("<widget class=\"GeoPlot\" name=\"geoPlot\">\n</widget>\n");
}

QString GeoPlotPlugin::includeFile() const
{
    return QLatin1String("geoplot.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(geoplotplugin, GeoPlotPlugin)
#endif // QT_VERSION < 0x050000
