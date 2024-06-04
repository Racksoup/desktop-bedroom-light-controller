#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/scale.h>

class UI {
	public:
		UI();
		virtual ~UI();

		Gtk::Box m_box;

	protected:
		void slider_clicked();

		Gtk::Scale m_slidBri, m_slidHue, m_slidSat;
		Gtk::Button m_btnsColors[12];
		Gtk::Button m_btnsBri[4];
		Gtk::Button m_btnOn;
		Gtk::Button m_btnOff;
};
