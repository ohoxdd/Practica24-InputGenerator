#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>   

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(1, 200);
std::vector<std::string> Ciudades;
int nprod = dis(gen);

std::string generate_random_string(size_t length) {
    auto randchar = []() -> char {
        const char charset[] =
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

inline int roll() {
    return dis(gen)%12;
}

void generate_tree(int depth) {
    if (depth == 0) {
        std::cout << "#" << std::endl;
        return;
    }

    std::string name = generate_random_string(5);
    Ciudades.push_back(name);
    std::cout << name << std::endl;

    std::uniform_int_distribution<> dis_depth(0, depth - 1);
    int child_depth = dis_depth(gen);
    generate_tree(child_depth);
    generate_tree(child_depth);
}

int main() {
    std::cout << nprod << std::endl;

    for (int i = 0; i < nprod; ++i) {
        std::cout << dis(gen) << " " << dis(gen) << std::endl;
    }

    generate_tree(dis(gen));
    
    std::cout << dis(gen)%nprod + 1 << ' ' << dis(gen) << std::endl;
    std::cout << dis(gen)%nprod + 1 << ' ' << dis(gen)%25 << std::endl;

    std::cout << "// bucle" << std::endl;

    std::vector<std::function<void()>> commands =  {
        []() {
            std::cout << "escribir_barco" << std::endl;
        },
        []() {
            std::cout << "leer_rio" << std::endl;
            Ciudades.clear();
            generate_tree(dis(gen));
        },
        []() {
            std::cout << "leer_inventario" << ' ';
            if (roll() > 10) {
                std::cout << generate_random_string(5) << std::endl;  
            } else {
                std::cout << Ciudades[dis(gen)%Ciudades.size()] << std::endl;
            }
            int n = dis(gen)%9;
            std::cout << n << std::endl;
            std::set<int> prods;
            for (int i = 0; i < n; ++i) {
                int id = dis(gen)%nprod +1;
                while (prods.find(id) != prods.end()) {
                    id = dis(gen)%nprod + 1;
                }
                prods.insert(id);
                std::cout << id << ' ' 
                            << dis(gen) << ' ' 
                            << dis(gen) << std::endl; 
            }
        },
        []() {
            std::cout << "leer_inventarios" << std::endl;
            int n = dis(gen)%Ciudades.size();
            for (int i = 0; i < n; ++i) {
                std::cout << Ciudades[dis(gen)%Ciudades.size()] << std::endl;
                int n = dis(gen)%9;
                std::cout << n << std::endl;
                std::set<int> prods;
                for (int i = 0; i < n; ++i) {
                    int id = dis(gen)%nprod +1;
                    while (prods.find(id) != prods.end()) {
                        id = dis(gen)%nprod + 1;
                    }
                    prods.insert(id);
                    std::cout << id << ' ' 
                                << dis(gen) << ' ' 
                                << dis(gen) << std::endl; 
                }
            }
            std::cout << "#" << std::endl;
        },
        []() {
            std::cout << "modificar_barco" << std::endl;
            std::cout << dis(gen)%nprod + 1 << ' ' << dis(gen) << std::endl;
            std::cout << dis(gen)%nprod + 1 << ' ' << dis(gen)%25 << std::endl;
        },
        []() {
            std::cout << "escribir_barco" << std::endl;
        },
        []() {
            std::cout << "consultar_num" << std::endl;
        },
        []() {
            std::cout << "agregar_productos" << std::endl;
            int n = dis(gen)%9 + 1;
            std::cout << n << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << dis(gen)%20 + 1 << ' ' << dis(gen)%20 + 1 << std::endl;
            }
            nprod += n;
        },
        []() {
            std::cout << "escribir_producto" << ' ';
            if (roll() <= 8)
                std::cout << dis(gen)%nprod + 1 << std::endl;
            else 
                std::cout << nprod + 1 << std::endl;
        },
        []() {
            std::cout << "escribir_ciudad" << ' ';
            if (roll() >= 10) std::cout << generate_random_string(5) << std::endl;
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << std::endl;
        },
        []() {
            std::cout << "poner_prod" << ' ';
            if (roll() > 10) std::cout << generate_random_string(5) << ' ';
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << ' ';

            if (roll() > 10) std::cout << dis(gen)*dis(gen) << ' ';
            else std::cout << dis(gen)%nprod + 1 << ' ';

            std::cout << dis(gen)%20 << ' ' << dis(gen)%20 + 1 << std::endl;
        },
        []() {
            std::cout << "modificar_prod" << ' ';
            if (roll() > 10) std::cout << generate_random_string(5) << ' ';
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << ' ';

            if (roll() > 10) std::cout << dis(gen)*dis(gen) << ' ';
            else std::cout << dis(gen)%nprod + 1 << ' ';

            std::cout << dis(gen)%20 << ' ' << dis(gen)%20 + 1 << std::endl;
        },
        []() {
            std::cout << "quitar_prod" << ' ';
            if (roll() > 10) std::cout << generate_random_string(5) << ' ';
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << ' ';

            if (roll() > 10) std::cout << dis(gen)*dis(gen) << std::endl;
            else std::cout << dis(gen)%nprod + 1 << std::endl;
        },
        []() {
            std::cout << "consultar_prod" << ' ';
            if (roll() > 10) std::cout << generate_random_string(5) << ' ';
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << ' ';

            if (roll() > 10) std::cout << dis(gen)*dis(gen) << std::endl;
            else std::cout << dis(gen)%nprod + 1 << std::endl;
        },
        []() {
            std::cout << "comerciar" << ' ';
            if (roll() > 10) std::cout << generate_random_string(5) << ' ';
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << ' '; 

            if (roll() > 10) std::cout << generate_random_string(5) << std::endl;
            else std::cout << Ciudades[dis(gen)%Ciudades.size()] << std::endl; 
        },
        []() {
            std::cout << "redistribuir" << std::endl;
        },
        []() {
            std::cout << "hacer_viaje" << std::endl;
        },
        []() {
            std::cout << "// redistribuir" << std::endl; 
        }
    };

    std::uniform_int_distribution<> rind(0, commands.size() - 1);
    for (int i = 0; i < 1000; i++) {
        commands[rind(gen)]();
    }

    std::cout << "fin" << std::endl;

    return 0;
}