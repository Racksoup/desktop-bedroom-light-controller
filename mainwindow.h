#include <gtkmm/window.h>
#include "UI.h"

class MainWindow : public Gtk::Window
{
	public: 
		MainWindow();
		virtual ~MainWindow();

	protected:
		UI m_ui;
};
