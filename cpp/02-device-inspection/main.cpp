#include <iostream>
#include <string>

struct Record {
    std::string type;
    std::string status;
    int hours = 0;
};

struct Stat {
    int cnt = 0;
    int total_h = 0;
};

int main() {
    int count = 0;
    if (!(std::cin >> count)) return 1;

    Stat printer, scanner, router, server;

    for(int i = 0; i < count; i++){
        Record r;
        std::cin >> r.type >> r.status >> r.hours;

        if(r.type == "printer"){
            printer.cnt +=1;
            printer.total_h += r.hours;
        }else if(r.type == "scanner"){
            scanner.cnt +=1;
            scanner.total_h += r.hours;
        }else if(r.type == "router"){
            router.cnt +=1;
            router.total_h += r.hours;
        }else if(r.type == "server"){
            server.cnt +=1;
            server.total_h += r.hours;
        }
    }

    std::cout << "printer " << printer.cnt << " " << printer.total_h << "\n";
    std::cout << "scanner " << scanner.cnt << " " << scanner.total_h << "\n";
    std::cout << "router "  << router.cnt  << " " << router.total_h  << "\n";
    std::cout << "server "  << server.cnt  << " " << server.total_h  << "\n";

    std::string busiest_name = "printer";
    int max_h = printer.total_h;

    if(scanner.total_h > max_h){
        max_h = scanner.total_h;
        busiest_name = "scanner";
    }
    if(router.total_h > max_h){
        max_h = router.total_h;
        busiest_name = "router";
    }
    if(server.total_h > max_h){
        max_h = server.total_h;
        busiest_name = "server";
    }

    std::cout << "busiest " << busiest_name << "\n";

    return 0;
}
