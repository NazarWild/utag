#include "src/main_lib.h"

void print_tags(const char *filename) {
    TagLib::FileRef f(filename);
    TagLib::String artist = f.tag()->artist();
    TagLib::String title = f.tag()->title();
    TagLib::String album = f.tag()->album();
    TagLib::String genre = f.tag()->genre();

    std::cout << "----------------------------------- " << filename << "\n";
    std::cout << "artist = " << artist 
            << "\ntitle = " << title 
            << "\nalbum = " << album
            << "\ngenre = " << genre;
    std::cout << "\n-----------------------------------\n";
}

int work_with_dir(const char *filename) {
    DIR *directory = opendir(filename);
    int err = 0;

    std::cout << filename << "\n";
    if (directory) {
        struct dirent *lupa = NULL;

        while ((lupa = readdir(directory)) != NULL) {
            std::string buff = lupa->d_name;
            std::string right_name = filename;

            right_name =  right_name + "/" + buff;
            // std::cout << "papka1 = " << lupa->d_name << "\n";
            buff = &buff[buff.find_last_of(".")];
            if (".mp3" == buff && (buff != "." || buff != ".."))
                print_tags(right_name.c_str());
        }
        closedir(directory);
    }
    else {
        std::cerr << "ERROR WITH DIRECTORY\n";
        err = 1;
    }
    return err;
}

int create_main_window(int argc, char **argv) {
    GtkWidget *window, *vbox;
    GtkWidget *label;
    int err = 0;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

    ////DIRECTORY CHECK
    if (argc == 2)
        err = work_with_dir(argv[1]);
    else
        std::cerr << "usage ./utag [dir_name]\n";
    //

    label = gtk_label_new("SANYA HUESOS");

    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(label), 1, 0, 5);

    gtk_container_add (GTK_CONTAINER (window), vbox);

    gtk_widget_show_all (window);
    gtk_main ();

    return err;
}

int main(int argc, char **argv) {
    int err = create_main_window(argc, argv);

	return err;
}