#include <iostream>
#define TAM 50

class Alumno{
private:
    std::string nombre;
    std::string carrera;
    std::string prepa;
    float promedio;
public:
    Alumno(){};
    friend std::ostream & operator<<(std::ostream &O, Alumno &x){
         O<<"\n Nombre: "<<x.nombre<<std::endl;
          O<<"\n Carrera: "<<x.carrera<<std::endl;
           O<<"\n Prepa: "<<x.prepa<<std::endl;
            O<<"\n Promedio: "<<x.promedio<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, Alumno &x){
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera:";
            O>>x.carrera;
            std::cout<<"\n Prepa:";
            O>>x.prepa;
            std::cout<<"\n Promedio:";
            O>>x.promedio;
            return O;
    }

        bool operator == (Alumno &a){
            return nombre == a.nombre && carrera == a.carrera && prepa == a.prepa && promedio == a.promedio;
        }

        bool operator <(Alumno &a)
        {
            return promedio<a.promedio;
        }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    int buscar(T&);
    int busquedabin(T&);
    void insercion();
    T Front()const;

};
template<class T>
void Cola<T>::insercion()
{
    T aux;
    for(int i=0;i<=ult;i++)
    {
        aux=datos[i];
        int j=i;
        while(j>0 && aux<datos[j-1])
        {
            datos[j]=datos[j-1];
            j=j-1;
        }
        if(i!=j)
        {
            datos[j]=aux;
            i=i+1;
        }
    }
}
template<class T>
int Cola<T>::busquedabin(T& dat)
{
    int i=0;
    int j=ult;
     int medio=0;
    while(i<=j)
    {
    medio=(i+j)/2;
    if(datos[medio]==dat)
    {
        return medio;
    }
    if(dat<datos[medio])
    {
        j=medio-1;
    }
    else
    {
        i=medio+1;
    }
    }
    return -1;
}
template<class T>
int Cola<T>::buscar(T& dat)
{
    for(int i=0;i<=ult;i++)
    {
        if(dat==datos[i])
        {
         return i;
        }
    }
   std::cout<<"Dato no encontrado"<<std::endl;
   return -1;
}
template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Alumno x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int menu;
    do
    {
    std::cout<<"Menu "<<std::endl;
    std::cout<<"1.Alta de solicitu"<<std::endl;
    std::cout<<"2.Imprimir constancia"<<std::endl;
    std::cout<<"3.Ordenar"<<std::endl;
    std::cout<<"4.Buscar"<<std::endl;
    std::cout<<"5.Salir"<<std::endl;
    std::cin>>menu;
    switch(menu)
    {
    case 1:

        std::cout<<"Datos de la solicitud"<<std::endl;
        std::cin>>x;
        MiCola.Queue(x);
        break;
    case 2:
        if(MiCola.vacia()){
         std::cout<<"Cola vacia"<<std::endl;
         }
         else
         {
         x=MiCola.Front();
         std::cout<<x<<std::endl;
         MiCola.Dequeue();
         }
         break;
    case 3:
        MiCola.insercion();
        std::cout<<"Ordenado";
        break;
    case 4:
         if(!MiCola.vacia())
         {
            std::cout<<"Datos para buscar"<<std::endl;
            std::cin>>x;
            if(MiCola.busquedabin(x) !=-1)
            {
              std::cout<<"Tu solicitud esta"<<MiCola.busquedabin(x)<<std::endl;
            }
            else
            {
                std::cout<<"Datos no encontrados  "<<std::endl;
            }
         }
         else
            {
                std::cout<<"Cola de solisitud vacia "<<std::endl;
            }
        break;
    }
    }while(menu!=5);


    return 0;
}

