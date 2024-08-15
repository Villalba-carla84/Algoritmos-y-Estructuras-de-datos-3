#ifndef GESTOR_FICHAS_ATENCION_HPP
#define GESTOR_FICHAS_ATENCION_HPP

#include <vector>
#include <memory>
#include "FichaAtencion.hpp"
#include "Atencion.hpp"

using namespace std;

class GestorFichasAtencion {
private:
    vector<shared_ptr<FichaAtencion>> fichas;

public:
    void crearFichaAtencion(shared_ptr<Paciente>& paciente);
    void agregarAtencion(int idFicha, shared_ptr<Atencion>& atencion);
    void mostrarFichaAtencion(int idFicha) const;
    shared_ptr<FichaAtencion> buscarFicha(int idFicha) const;
      
    const vector<shared_ptr<FichaAtencion>>& getFichas() const;
};

#endif // GESTOR_FICHAS_ATENCION_HPP
