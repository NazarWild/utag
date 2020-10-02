#include "main_lib.h"

using namespace std;

New_Window::New_Window(string title) {
    set_border_width(10);
    set_default_size(500, 400);
    set_title(title);
    set_position(Gtk::WIN_POS_CENTER);
    add(m_box);
    m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box.pack_start(m_path, true, true, 10);
    m_box.pack_start(m_artist_l, true, true, 10);
    m_box.pack_start(m_artist, true, true, 10);
    m_box.pack_start(m_title_l, true, true, 10);
    m_box.pack_start(m_title, true, true, 10);
    m_box.pack_start(m_album_l, true, true, 10);
    m_box.pack_start(m_album, true, true, 10);
    m_box.pack_start(m_genre_l, true, true, 10);
    m_box.pack_start(m_genre, true, true, 10);
    m_box.pack_start(m_button, true, true, 10);
    show();
    show_all_children();
}

New_Window::~New_Window() {}

ListBoxScroll::ListBoxScroll() {
    set_border_width(4);
    add(m_hbox);
    m_hbox.pack_start(m_listbox, Gtk::PackOptions::PACK_EXPAND_WIDGET);
    m_listbox.signal_row_selected().connect(sigc::mem_fun(*this, &ListBoxScroll::sig_row_selected));
    show_all_children();
    m_i = 0;
}

void ListBoxScroll::api_Clear() {
   m_listbox.unselect_all();
    vector<Gtk::Widget*> children = m_listbox.get_children();
    for (Widget* w : children) {
       m_listbox.remove(*w);
       delete w;
    }
}

void ListBoxScroll::api_AddRow(std::string text) {
    auto row = Gtk::manage(new MyListRow{text});
    m_listbox.append(*row);
    row->show();
}

void ListBoxScroll::sig_row_selected(Gtk::ListBoxRow* listboxrow) {
    if (listboxrow != nullptr) {
        MyListRow* listrow = (MyListRow*)listboxrow;
        m_us = listrow->m_label.get_text();
        m_filename = m_dirname + "/" + m_us;
        m_new_w = 0;
        print_tags();
    }
}

void ListBoxScroll::print_tags() { ///////////// /////////////
    TagLib::FileRef f(m_filename.c_str());

    if(f.file()->isValid()) {
        if (m_i != 1) {
            m_i = 1;
            window_4_tag();

            m_new_w->m_path.set_text(m_filename);
            m_new_w->m_artist.set_text(f.tag()->artist().to8Bit());
            m_new_w->m_title.set_text(f.tag()->title().to8Bit());
            m_new_w->m_album.set_text(f.tag()->album().to8Bit());
            m_new_w->m_genre.set_text(f.tag()->genre().to8Bit());
        }   
    }
}

void ListBoxScroll::window_4_tag() {
    if(m_new_w != 0)
        return;
    m_new_w = new New_Window(m_us);
    m_new_w->signal_hide().connect(sigc::mem_fun(*this, &ListBoxScroll::aboutWinClose));
    m_new_w->m_button.signal_clicked().connect(sigc::mem_fun(*this, &ListBoxScroll::on_click_button_save));
}

void ListBoxScroll::on_click_button_save(){ ///////////// ///////////// /////////////
     TagLib::FileRef f(m_filename.c_str());

    if(f.file()->isValid()) {
        string buffer = m_new_w->m_title.get_text();
        f.tag()->setTitle(buffer);
        buffer = m_new_w->m_artist.get_text();
        f.tag()->setArtist(buffer);
        buffer = m_new_w->m_album.get_text();
        f.tag()->setAlbum(buffer);
        buffer = m_new_w->m_genre.get_text();
        f.tag()->setGenre(buffer);
        f.save();
    }
}

void ListBoxScroll::aboutWinClose()
{
    m_i = 0;
    m_new_w = 0;
    delete m_new_w;
}
