#############################################################################
# Makefile for building: endless_counting
# Generated by qmake (3.0) (Qt 5.4.0)
# Project:  endless_counting.pro
# Template: app
# Command: /home/lainproliant/builds/mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5 -o Makefile endless_counting.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = /home/lainproliant/builds/mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = cp -f
INSTALL_PROGRAM = cp -f
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv -f
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: endless_counting.pro ../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/win32-g++/qmake.conf ../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/spec_pre.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/qdevice.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/device_config.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/common/shell-unix.conf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/qconfig.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_core.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_core_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_dbus.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_gui.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_network.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_network_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_opengl.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_sql.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_testlib.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_widgets.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_xml.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qgenericbearer.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qico.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qminimal.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qnativewifibearer.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlite.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlodbc.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlpsql.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqltds.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qwindows.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_windowsprintersupport.pri \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt_functions.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt_config.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/qt_config.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/win32-g++/qmake.conf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/spec_post.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exclusive_builds.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/default_pre.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/default_pre.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/resolve_config.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exclusive_builds_post.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/default_post.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/c++11.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/rtti.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/precompile_header.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/warn_on.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/resources.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/moc.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/opengl.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/uic.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/windows.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/testcase_targets.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exceptions.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/yacc.prf \
		../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/lex.prf \
		endless_counting.pro \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/qtmain.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Core.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Widgets.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Gui.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/plugins/platforms/qwindows.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5PlatformSupport.prl \
		/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/plugins/imageformats/qico.prl
	$(QMAKE) -o Makefile endless_counting.pro
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/spec_pre.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/qdevice.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/device_config.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/common/shell-unix.conf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/qconfig.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_concurrent.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_core.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_core_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_dbus.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_gui.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_gui_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_network.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_network_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_opengl.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_printsupport.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_sql.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_sql_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_testlib.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_widgets.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_xml.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_lib_xml_private.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qgenericbearer.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qico.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qminimal.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qnativewifibearer.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlite.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlodbc.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqlpsql.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qsqltds.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_qwindows.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/modules/qt_plugin_windowsprintersupport.pri:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt_functions.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt_config.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/qt_config.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/win32-g++/qmake.conf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/spec_post.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exclusive_builds.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/default_pre.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/default_pre.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/resolve_config.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exclusive_builds_post.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/default_post.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/c++11.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/rtti.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/precompile_header.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/warn_on.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/qt.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/resources.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/moc.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/opengl.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/uic.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/win32/windows.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/testcase_targets.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/exceptions.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/yacc.prf:
../../builds/mxe/usr/i686-w64-mingw32.static/qt5/mkspecs/features/lex.prf:
endless_counting.pro:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/qtmain.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Core.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Widgets.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5Gui.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/plugins/platforms/qwindows.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/lib/Qt5PlatformSupport.prl:
/home/lainproliant/builds/mxe/usr/i686-w64-mingw32.static/qt5/plugins/imageformats/qico.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile endless_counting.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) /home/lainproliant/proj/endless_counting/endless_counting_plugin_import.cpp

release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
