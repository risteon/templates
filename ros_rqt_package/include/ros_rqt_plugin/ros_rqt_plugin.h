//----------------------------------------------------------------------
/*
 * \file    ros_rqt_plugin.h
 *
 * \author  TODO <todo@osrf.org>
 * \date    2016-01-01
 *
 */
//----------------------------------------------------------------------

#ifndef ROS_RQT_PLUGIN_RQT_PLUGIN_RQT_PLUGIN_H
#define ROS_RQT_PLUGIN_RQT_PLUGIN_RQT_PLUGIN_H

// Rqt-Plugin
#include <rqt_gui_cpp/plugin.h>
// Generated UI header
#include <ui_ros_rqt_plugin.h>

// Qt
#include <QWidget>


namespace rqt_plugin {

/**
 * @brief The RqtPlugin class
 */
class RqtPlugin
  : public rqt_gui_cpp::Plugin
{
  Q_OBJECT

public:

  //! Constructor
  RqtPlugin();

  //! Plugin implementation interface
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

  // Comment in to signal that the plugin has a way to configure it
  //bool hasConfiguration() const;
  //void triggerConfiguration();

protected slots: 


private:    

  //! UI
  Ui::ROS_RQT_Plugin m_ui;
  //! Qt widget pointer
  QWidget* m_widget;

};

}

#endif // ROS_RQT_PLUGIN_RQT_PLUGIN_RQT_PLUGIN_H
