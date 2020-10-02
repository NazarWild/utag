#include "src/main_lib.h"

int main(int argc, char **argv) {
    auto app = Gtk::Application::create();
    All all_staff(argc, argv);

	return app->run(all_staff);
}
