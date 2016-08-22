//----------------------------------------------------------------------
/*
 * \file    ros_rqt_plugin.h
 *
 * \author  TODO <todo@osrf.org>
 * \date    2016-01-01
 *
 */
//----------------------------------------------------------------------

#include "ros_rqt_plugin/ros_rqt_plugin.h"

namespace rqt_plugin {

RqtPlugin::RqtPlugin()
  : rqt_gui_cpp::Plugin()
  , m_widget(nullptr)
{
  setObjectName("RqtTrajParamPlugin");
}

void RqtPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
  // access standalone command line arguments
  QStringList argv = context.argv();
  // create QWidget
  m_widget = new QWidget();
  // extend the widget with all attributes and children from UI file
  m_ui.setupUi(m_widget);
  // add widget to the user interface
  context.addWidget(m_widget);
}

void RqtPlugin::shutdownPlugin()
{
  // TODO unregister all publishers here
}

void RqtPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  // TODO save intrinsic configuration, usually using:
  // instance_settings.setValue(k, v)
}

void RqtPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  // TODO restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
}

/*bool hasConfiguration() const
{
  return true;
}

void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/

} // ns

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rqt_plugin::RqtPlugin, rqt_gui_cpp::Plugin)
