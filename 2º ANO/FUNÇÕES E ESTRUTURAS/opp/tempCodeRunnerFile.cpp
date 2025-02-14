#include <iostream>
using namespace std;

struct lata{
    string marca;
    string sabor;
    string validade;
    string fornecedor;
    string codBarras;
    string lote;
    string dataFabricacao;
    string infoFornecedor;
    string infoNutrucional[5];
    string materialEmbalagem;

    double capacidade;
    double preco;
    double peso;

    bool status;

};

class Refrigerante{
    private:
        lata refrigerante;

    public:

        Refrigerante(lata lata){
            refrigerante = lata;
        }

        void setMarca(string marca){
            refrigerante.marca = marca;
        }
}

int main(){

    lata lata1 = {"Coca-Cola", "Cola", "10/10/2021", "Coca-Cola",
                "123456789", "Lote 1", "01/01/2021", "coca-cola company",
                 "1000kcal", "Aluminio", {"calorias: 750kcal",
                                          "proteinas: 3g",
                                          "carbohidratos: 150g", 
                                          "fibra: 0.1g", 
                                          "sodio: 2g"},
                                          350.00,5.00, 0.350, false};

