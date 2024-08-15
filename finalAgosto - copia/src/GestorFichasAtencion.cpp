#include "GestorFichasAtencion.hpp"
#include <iostream>
#include <algorithm>

void GestorFichasAtencion::crearFichaAtencion(shared_ptr<Paciente>& paciente) {
    int idFicha = fichas.size() + 1;
    shared_ptr<FichaAtencion> ficha(new FichaAtencion(idFicha, paciente));
    fichas.push_back(ficha);
}

void GestorFichasAtencion::agregarAtencion(int idFicha, shared_ptr<Atencion>& atencion) {
    auto it = find_if(fichas.begin(), fichas.end(), [idFicha](shared_ptr<FichaAtencion>& ficha) {
        return ficha->getId() == idFicha;
    });

    if (it != fichas.end()) {
        (*it)->agregarAtencion(atencion);
    } else {
        cout << "Ficha de atención no encontrada.\n";
    }
}

void GestorFichasAtencion::mostrarFichaAtencion(int idFicha) const {
    for (const auto& ficha : fichas) {
        if (ficha->getId() == idFicha) {
            cout << "Ficha ID: " << ficha->getId() << endl;
            cout << "Paciente: " << ficha->getPaciente()->mostrarInformacion() << endl;
            cout << "Atenciones:" << endl;
            for (const auto& atencion : ficha->getAtenciones()) {
                cout << "  - " << atencion->getDescripcion() << endl;
            }
            return;
        }
    }
    cout << "Ficha de atención no encontrada." << endl;
}

shared_ptr<FichaAtencion> GestorFichasAtencion::buscarFicha(int idFicha) const {
    auto it = find_if(fichas.begin(), fichas.end(),
                      [idFicha](const shared_ptr<FichaAtencion>& ficha) {
                          return ficha->getId() == idFicha;
                      });

    if (it != fichas.end()) {
        return *it;
    } else {
        return nullptr; // Ficha de atención no encontrada
    }
}

const vector<shared_ptr<FichaAtencion>>& GestorFichasAtencion::getFichas() const {
    return fichas;
}
