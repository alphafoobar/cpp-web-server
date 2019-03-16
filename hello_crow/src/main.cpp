#include "crow_all.h"

using namespace std;

#include <string>

int main(int argc, char *argv[]) {
    crow::SimpleApp app;

    app.loglevel(crow::LogLevel::Info);

    CROW_ROUTE(app, "/")
            ([]() {
                return "<div><h1>Hello, Crow.</h1></div>";
            });
    CROW_ROUTE(app, "/<string>")
            ([](string name) {
                return "<div><h1>Hello, " + name + ".</h1></div>";
            });

    char *port = getenv("PORT");
    uint16_t iPort = static_cast<uint16_t>(port != NULL ? stoi(port) : 18080);
    cout << "PORT = " << iPort << "\n";
    app.port(iPort).multithreaded().run();
}
